#include "Book.h"
//using std::string;

Book::Book() {//parameterless constructor sets to default values
    this->bookID = "";//empty string is something a nullptr is nothing 
    this->title = "";
    this->author = "";
    for (int i = 0; i < priceArraySize; i++) this->prices[i] = 0;
    this->bookType = BookType::UNDECIDED;
}

Book::Book(string bookID, string title, string author, double prices[], BookType bookType) {
    this->bookID = bookID;
    this->title = title;
    this->author = author;
    for (int i = 0; i < priceArraySize; i++) this->prices[i] = prices[i];
    this->bookType = bookType;
}

Book::~Book() {}//empty destructor because there is nothing dynamic in the book class

//getters
string Book::getID() { return this->bookID; }
string Book::getTitle() { return this->title; }
string Book::getAuthor() { return this->author; }
double* Book::getPrices() { return this->prices; }
BookType Book::getBookType() { return this->bookType; }

//setters
void Book::setID(string ID) { this->bookID = ID; }
void Book::setTitle(string title) { this->title = title; }
void Book::setAuthor(string author) { this->author = author; }
void Book::setPrices(double prices[]) {
    for (int i = 0; i < priceArraySize; i++) this->prices[i] = prices[i];
}
void Book::setBookTypes(BookType bt) { this->bookType = bookType; }

//print using the print header
void Book::printHeader() {
    std::cout << "Output Format: ID|Title|Author|Prices|Type\n";
}

//print out this book
void Book::print() {
    std::cout << this->getID() << '\t';
    std::cout << this->getTitle() << '\t';
    std::cout << this->getAuthor() << '\t';
    std::cout << this->getPrices()[0] << ',';
    std::cout << this->getPrices()[1] << ',';
    std::cout << this->getPrices()[2] << '\t';
    std::cout << bookTypeStrings[this->getBookType()] << "\n";

}