#include <iostream>
#include <cmath>
using namespace std;

class NegativeNumberException {
public:
    double value;

    NegativeNumberException(double v) {
        value = v;
    }

    void display() {
        cout << "Negative number not allowed: " << value << endl;
    }
};

int main() {
    double num;

    while (true) {
        cout << "Enter number (0 to exit): ";
        cin >> num;

        if (num == 0)
            break;

        try {
            if (num < 0)
                throw NegativeNumberException(num);

            cout << "Square root: " << sqrt(num) << endl;
        }
        catch (NegativeNumberException e) {
            e.display();
        }
    }

    return 0;
}