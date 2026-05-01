#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() {
        return 0;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() {
        return 3.14159 * radius * radius;
    }
};

int main() {
    int choice;

    Shape* dynamicShapes[100];
    int dcount = 0;

    Shape staticShapes[100];
    int scount = 0;

    do {
        cout << "\n1. Add Rectangle (Dynamic)\n2. Add Circle (Dynamic)\n3. Display Dynamic Areas\n4. Add Rectangle (Static)\n5. Add Circle (Static)\n6. Display Static Areas\n7. Exit\n";
        cin >> choice;

        if (choice == 1) {
            double l, w;
            cin >> l >> w;
            dynamicShapes[dcount++] = new Rectangle(l, w);
        } else if (choice == 2) {
            double r;
            cin >> r;
            dynamicShapes[dcount++] = new Circle(r);
        } else if (choice == 3) {
            for (int i = 0; i < dcount; i++) {
                cout << dynamicShapes[i]->area() << endl;
            }
        } else if (choice == 4) {
            double l, w;
            cin >> l >> w;
            staticShapes[scount++] = Rectangle(l, w);
        } else if (choice == 5) {
            double r;
            cin >> r;
            staticShapes[scount++] = Circle(r);
        } else if (choice == 6) {
            for (int i = 0; i < scount; i++) {
                cout << staticShapes[i].area() << endl;
            }
        }

    } while (choice != 7);

    return 0;
}