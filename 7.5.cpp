#include <iostream>
using namespace std;

class Grading {
protected:
    double marks;

public:
    Grading(double m) {
        marks = m;
    }

    virtual char computeGrade() = 0;
};

class Undergraduate : public Grading {
public:
    Undergraduate(double m) : Grading(m) {}

    char computeGrade() {
        if (marks >= 75) return 'A';
        else if (marks >= 60) return 'B';
        else if (marks >= 50) return 'C';
        else return 'F';
    }
};

class Postgraduate : public Grading {
public:
    Postgraduate(double m) : Grading(m) {}

    char computeGrade() {
        if (marks >= 80) return 'A';
        else if (marks >= 65) return 'B';
        else if (marks >= 55) return 'C';
        else return 'F';
    }
};

int main() {
    Grading* students[100];
    int count = 0;
    int choice;

    do {
        cout << "\n1. Add Undergraduate\n2. Add Postgraduate\n3. Display Grades\n4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            double m;
            cin >> m;
            students[count++] = new Undergraduate(m);
        } else if (choice == 2) {
            double m;
            cin >> m;
            students[count++] = new Postgraduate(m);
        } else if (choice == 3) {
            for (int i = 0; i < count; i++) {
                cout << students[i]->computeGrade() << endl;
            }
        }

    } while (choice != 4);

    return 0;
}