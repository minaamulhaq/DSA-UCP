
#include"LibraryItem.h"

class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    Book() {}

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() {
        return title;
    }

    int getPages() {
        return pages;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }

    bool operator==(string t) {
        return title == t;
    }

    bool operator<(Book b) {
        return pages < b.pages;
    }
};