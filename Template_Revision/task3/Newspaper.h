// #include"LibraryItems.h"
class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper() {}

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() {
        return name;
    }

    string getEdition() {
        return edition;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }

    bool operator==(string n) {
        return name == n;
    }

    bool operator<(Newspaper n) {
        return edition < n.edition;
    }
};