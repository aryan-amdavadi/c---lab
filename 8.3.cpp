#include <iostream>
#include <stdexcept>
using namespace std;

// Simple log array
string logArr[50];
int idx = 0;

void log(string msg) {
    logArr[idx++] = msg;
}

// -------- BankAccount --------
class BankAccount {
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amt) {
        log("deposit() called");
        if (amt <= 0)
            throw invalid_argument("Invalid deposit amount");
        balance += amt;
    }

    void withdraw(double amt) {
        log("withdraw() called");
        if (amt > balance)
            throw runtime_error("Insufficient balance");
        balance -= amt;
    }
};

// -------- Function Chain --------
void func2(BankAccount &acc) {
    log("Entered func2()");
    acc.withdraw(5000);  // force exception
    log("Exiting func2()");
}

void func1(BankAccount &acc) {
    log("Entered func1()");
    func2(acc);
    log("Exiting func1()");
}

// -------- Main --------
int main() {
    BankAccount acc(1000);

    try {
        log("Entered main()");
        func1(acc);
        log("Exiting main()");
    }
    catch (exception &e) {
        log("Exception caught in main()");
        cout << "Error: " << e.what() << endl;
    }

    // Print logs
    cout << "\nLogs:\n";
    for (int i = 0; i < idx; i++) {
        cout << logArr[i] << endl;
    }

    return 0;
}