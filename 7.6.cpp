#include <iostream>
using namespace std;

class Base1 {
public:
    Base1() {
        cout << "Base1 constructor\n";
    }

    ~Base1() {
        cout << "Base1 destructor\n";
    }
};

class Derived1 : public Base1 {
private:
    int* data;

public:
    Derived1() {
        data = new int[5];
        cout << "Derived1 constructor\n";
    }

    ~Derived1() {
        delete[] data;
        cout << "Derived1 destructor\n";
    }
};

class Base2 {
public:
    Base2() {
        cout << "Base2 constructor\n";
    }

    virtual ~Base2() {
        cout << "Base2 destructor\n";
    }
};

class Derived2 : public Base2 {
private:
    int* data;

public:
    Derived2() {
        data = new int[5];
        cout << "Derived2 constructor\n";
    }

    ~Derived2() {
        delete[] data;
        cout << "Derived2 destructor\n";
    }
};

int main() {
    Base1* b1 = new Derived1();
    delete b1;

    cout << endl;

    Base2* b2 = new Derived2();
    delete b2;

    return 0;
}