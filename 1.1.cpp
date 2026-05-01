#include <iostream>
using namespace std;

class Wallet {
private:
    int walletID;
    string userName;
    double balance;

public:
    Wallet(int id, string name, double bal = 0) {
        walletID = id;
        userName = name;
        balance = bal;
    }

    void loadMoney(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Money loaded successfully\n";
        } else {
            cout << "Invalid amount\n";
        }
    }

    void transferMoney(Wallet &receiver, double amount) {
        if (amount <= 0) {
            cout << "Invalid amount\n";
            return;
        }
        if (amount > balance) {
            cout << "Insufficient balance\n";
        } else {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transfer successful\n";
        }
    }

    void display() {
        cout << "Wallet ID: " << walletID << endl;
        cout << "User Name: " << userName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Wallet w1(101, "Aryan");
    Wallet w2(102, "Rahul");

    w1.loadMoney(500);
    w1.transferMoney(w2, 200);

    w1.display();
    w2.display();

    return 0;
}