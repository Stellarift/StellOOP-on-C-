#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(const string& author, const string& title, 
           const string& publisher, int year, int pages)
    : author(author), title(title), publisher(publisher), year(year), pages(pages) {}

Book::Book() : author(""), title(""), publisher(""), year(0), pages(0) {}

void Book::display() const {
    cout << "Автор: " << author << endl;
    cout << "Название: " << title << endl;
    cout << "Издательство: " << publisher << endl;
    cout << "Год: " << year << endl;
    cout << "Страниц: " << pages << endl;
}

string Book::getAuthor() const { return author; }
string Book::getTitle() const { return title; }
string Book::getPublisher() const { return publisher; }
int Book::getYear() const { return year; }
int Book::getPages() const { return pages; }