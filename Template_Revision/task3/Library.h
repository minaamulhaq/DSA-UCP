#include"Book.h"
#include"Newspaper.h"


template <class T>
int linearSearch(T arr[], int size, string key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
template <class T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

class Library {
private:
    Book books[50];
    Newspaper newspapers[50];

    int bookCount = 0;
    int newspaperCount = 0;

public:

    void addBook(Book b) {
        books[bookCount++] = b;
    }

    void addNewspaper(Newspaper n) {
        newspapers[newspaperCount++] = n;
    }

    void displayCollection() {

        cout << "\nBooks:\n";
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
            cout << endl;
        }

        cout << "\nNewspapers:\n";
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
            cout << endl;
        }
    }

    void sortBooksByPages() {
        bubbleSort(books, bookCount);
    }

    void sortNewspapersByEdition() {
        bubbleSort(newspapers, newspaperCount);
    }

    Book* searchBookByTitle(string title) {

        int index = linearSearch(books, bookCount, title);

        if (index != -1)
            return &books[index];

        return NULL;
    }

    Newspaper* searchNewspaperByName(string name) {

        int index = linearSearch(newspapers, newspaperCount, name);

        if (index != -1)
            return &newspapers[index];

        return NULL;
    }
};
