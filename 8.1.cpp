#include <iostream>
using namespace std;

int main() {
    int a, b;

    try {
        cout << "Enter two integers: ";
        if (!(cin >> a >> b))
            throw "Invalid input";

        if (b == 0)
            throw "Division by zero";

        cout << "Result: " << a / b << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}