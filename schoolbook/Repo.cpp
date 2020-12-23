#include "Repo.h"
using std::string;
using std::cout;

void Repo::parse(string bookdata) {
    BookType bt = UNDECIDED;//default
    if (bookdata.at(0) == 'F') bt = FICTION;//using first char to determine booktype
    else if (bookdata.at(0) == 'N') bt = NONFICTION;

    int rhs = bookdata.find(","); // find the comma
    string bID = bookdata.substr(0, rhs); //extract substring infront of comma

    int lhs = rhs + 1; //move past comma
    rhs = bookdata.find(",", lhs);
    string ttl = bookdata.substr(lhs, rhs - lhs); //book title

    lhs = rhs + 1;//move past next comma
    rhs = bookdata.find(",", lhs);
    string aut = bookdata.substr(lhs, rhs - lhs); // book author

    lhs = rhs + 1;//move past next comma
    rhs = bookdata.find(",", lhs);
    double p1 = stod(bookdata.substr(lhs, rhs - lhs));//first price
    lhs = rhs + 1;
    rhs = bookdata.find(",", lhs);
    double p2 = stod(bookdata.substr(lhs, rhs - lhs));// second price
    lhs = rhs + 1;
    rhs = bookdata.find(",", lhs);
    double p3 = stod(bookdata.substr(lhs, rhs - lhs));// third price

    add(bID, ttl, aut, p1, p2, p3, bt);
}

void Repo::add(string bookID, string title, string author, double price1, double price2, double price3, BookType bt) {
    double parr[3] = { price1,price2,price3 };
    bookRepoArray[++lastIndex] = new Book(bookID, title, author, parr, bt);
}

void Repo::printAll() {
    Book::printHeader();
    for (int i = 0; i <= Repo::lastIndex; i++) {
        cout << bookRepoArray[i]->getID(); cout << '\t';
        cout << bookRepoArray[i]->getTitle(); cout << '\t';
        cout << bookRepoArray[i]->getAuthor(); cout << '\t';
        cout << bookRepoArray[i]->getPrices()[0]; cout << '\t';
        cout << bookRepoArray[i]->getPrices()[1]; cout << '\t';
        cout << bookRepoArray[i]->getPrices()[2]; cout << '\t';
        cout << bookTypeStrings[bookRepoArray[i]->getBookType()] << std::endl;
    }
}

//display only books of this type
void Repo::printByBookType(BookType bt) {
    Book::printHeader();
    for (int i = 0; i <= Repo::lastIndex; i++) {
        if (Repo::bookRepoArray[i]->getBookType() == bt) bookRepoArray[i]->print();
    }
    cout << std::endl;
}

void Repo::printInvalidIDs() {
    bool any = false;
    for (int i = 0; i <= Repo::lastIndex; i++) {
        string bID = (bookRepoArray[i]->getID());
        if (bID.find('_') == string::npos || (bID.find('X') == string::npos && bID.find('x') == string::npos)) {
            any = true;
            cout << bID << ": " << bookRepoArray[i]->getTitle() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Repo::printAveragePrices(string bID) {
    for (int i = 0; i <= Repo::lastIndex; i++) {
        if (bookRepoArray[i]->getID() == bID) {
            cout << bID << ": ";
            cout << (bookRepoArray[i] -> getPrices()[0]
                + bookRepoArray[i]->getPrices()[1]
                + bookRepoArray[i]->getPrices()[2]) / 3.0 << std::endl;
        }
        
    }
}

//remove a book
void Repo::removeBookByID(string bookID) {
    bool success = false;
    for (int i = 0; i <= Repo::lastIndex; i++) {
        if (bookRepoArray[i]->getID() == bookID) {
            success = true;//found matching bookid
            if (i < numBooks - 1) {
                Book* temp = bookRepoArray[i];
                bookRepoArray[i] = bookRepoArray[numBooks - 1];
                bookRepoArray[numBooks - 1] = temp;
            }
            Repo::lastIndex--;
        }
    }
    if (success) {
        cout << bookID << " removed from repository." << std::endl << std::endl;
        this->printAll();
    }
    else cout << bookID << " not found." << std::endl << std::endl;
}

Repo::~Repo() {
    cout << "Destructor Called!" << std::endl << std::endl;
    for (int i = 0; i < numBooks; i++) {
        cout << "Destroying book#" << i + 1 << std::endl;
        delete bookRepoArray[i];
        bookRepoArray[i] = nullptr;
    }
}
