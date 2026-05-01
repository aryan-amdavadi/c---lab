#include <iostream>
using namespace std;

class Account {
private:
    int accountID;
    string name;
    double balance;

public:
    Account() {
        accountID = 0;
        name = "";
        balance = 0;
    }

    void createAccount(int id, string n, double b) {
        accountID = id;
        name = n;
        if (b >= 0)
            balance = b;
        else
            balance = 0;
    }

    int getID() {
        return accountID;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful\n";
        } else {
            cout << "Invalid amount\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount\n";
        } else if (amount > balance) {
            cout << "Insufficient balance\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful\n";
        }
    }

    void display() {
        cout << "Account ID: " << accountID << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Account acc[100];
    int count = 0;
    int choice;

    do {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Display Account\n5. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            double bal;
            cout << "Enter ID, Name, Initial Balance: ";
            cin >> id >> name >> bal;
            acc[count].createAccount(id, name, bal);
            count++;
        } else if (choice == 2) {
            int id;
            double amt;
            cout << "Enter Account ID and amount: ";
            cin >> id >> amt;
            for (int i = 0; i < count; i++) {
                if (acc[i].getID() == id) {
                    acc[i].deposit(amt);
                }
            }
        } else if (choice == 3) {
            int id;
            double amt;
            cout << "Enter Account ID and amount: ";
            cin >> id >> amt;
            for (int i = 0; i < count; i++) {
                if (acc[i].getID() == id) {
                    acc[i].withdraw(amt);
                }
            }
        } else if (choice == 4) {
            int id;
            cout << "Enter Account ID: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (acc[i].getID() == id) {
                    acc[i].display();
                }
            }
        }

    } while (choice != 5);

    return 0;
}
