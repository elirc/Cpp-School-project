#pragma once
#include <iostream>
#include <iomanip>
#include "BookType.h"

using std::cout;
using std::string;

class Book {
public:
    const static int priceArraySize = 3;
private:
    std::string bookID;
    std::string title;
    std::string author;
    double prices[priceArraySize];
    BookType bookType;
public:
    Book();//parameterless constructor - sets to default values - apprently i always write this
    Book(string bookID, string title, string author, double prices[], BookType BookType);
    ~Book();//destructor

//getters aka accessors
    std::string getID();
    std::string getTitle();
    std::string getAuthor();
    double* getPrices();
    BookType getBookType();

    //setters aka mutators
    void setID(string ID);
    void setTitle(string title);
    void setAuthor(string author);
    void setPrices(double prices[]);
    void setBookTypes(BookType bt);

    static void printHeader();//displays a header for the data to follow

    void print();//displays 'this' students data

};