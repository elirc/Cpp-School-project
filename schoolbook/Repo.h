#pragma once
#include "Book.h"

class Repo {
private:
    int lastIndex = -1;
    const static int numBooks = 5;
    Book* bookRepoArray[numBooks]; // not declared dynamicly

public:
    void parse(string row);//parses a set of comma seperated strings used for extracting book data
    void add(string bID,
        string bTitle,
        string bAuthor,
        double bprice1,
        double bprice2,
        double bprice3,
        BookType bt);
    void printAll();
    void printByBookType(BookType bt);
    void printInvalidIDs();
    void printAveragePrices();
    void removeBookByID(string bookID);
    ~Repo();

};