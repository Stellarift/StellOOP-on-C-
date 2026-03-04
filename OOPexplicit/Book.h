#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    int year;
    int pages;

public:
    Book(const string& author, const string& title, 
         const string& publisher, int year, int pages);
    
    Book();
    
    void display() const;
    
    string getAuthor() const;
    string getTitle() const;
    string getPublisher() const;
    int getYear() const;
    int getPages() const;
};

#endif