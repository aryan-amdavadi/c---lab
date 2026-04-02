#include <iostream>
using namespace std;
double PI = 3.1415;

class Shape {
protected:
    double radius;
public:
    void setRadius(double r) { radius = r; }
    double getRadius() { return radius; }
};

class Circle : public Shape {
public:
    double area() {
        return PI * radius * radius;
    }
};

int main() {
    int n;
    cout << "Enter number of circles: ";
    cin >> n;

    Circle circles[n];
    double radii=0.00;
    for(int i = 0; i < n; i++) {
        radii = 0.00;
        cout << "Enter radius for circle " << i+1 << ": ";
        cin >> radii;
        circles[i].setRadius(radii);
    }

    cout << "\nAreas using array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Circle " << i+1 << ": " << circles[i].area() << endl;
    }
    Circle *c = new Circle[n];
    for(int i = 0; i < n; i++) {
        radii = 0.00;
        cout << "Enter radius for circle " << i+1 << ": ";
        cin >> radii;
        c[i].setRadius(radii);
    }

    cout << "\nAreas using array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Circle " << i+1 << ": " << c[i].area() << endl;
    }
    return 0;
}