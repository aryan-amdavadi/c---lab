#include <iostream>
using namespace std;

#define MAX 100

struct BookP {
    int id;
    string title;
    string author;
    int copies;
};

void addBookP(BookP b[], int &n, int id, string title, string author, int copies) {
    b[n].id = id;
    b[n].title = title;
    b[n].author = author;
    b[n].copies = copies;
    n++;
}

void issueBookP(BookP b[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (b[i].id == id) {
            if (b[i].copies > 0) {
                b[i].copies--;
                cout << "Book issued\n";
            } else {
                cout << "No copies available\n";
            }
            return;
        }
    }
    cout << "Book not found\n";
}

void returnBookP(BookP b[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (b[i].id == id) {
            b[i].copies++;
            cout << "Book returned\n";
            return;
        }
    }
    cout << "Book not found\n";
}

void displayTotalP(int n) {
    cout << "Total books: " << n << endl;
}

class Book {
private:
    int id;
    string title;
    string author;
    int copies;

public:
    Book(int i, string t, string a, int c) {
        id = i;
        title = t;
        author = a;
        copies = c;
    }

    int getId() {
        return id;
    }

    void issue() {
        if (copies > 0) {
            copies--;
            cout << "Book issued\n";
        } else {
            cout << "No copies available\n";
        }
    }

    void giveBack() {
        copies++;
        cout << "Book returned\n";
    }
};

class Library {
private:
    Book* books[MAX];
    int count;

public:
    Library() {
        count = 0;
    }

    void addBook(Book* b) {
        books[count++] = b;
    }

    void issueBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i]->getId() == id) {
                books[i]->issue();
                return;
            }
        }
        cout << "Book not found\n";
    }

    void returnBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i]->getId() == id) {
                books[i]->giveBack();
                return;
            }
        }
        cout << "Book not found\n";
    }

    void displayTotal() {
        cout << "Total books: " << count << endl;
    }
};

int main() {
    BookP b[MAX];
    int n = 0;

    addBookP(b, n, 1, "C++", "Bjarne", 3);
    issueBookP(b, n, 1);
    returnBookP(b, n, 1);
    displayTotalP(n);

    Library lib;
    Book* b1 = new Book(1, "C++", "Bjarne", 3);

    lib.addBook(b1);
    lib.issueBook(1);
    lib.returnBook(1);
    lib.displayTotal();

    return 0;
}