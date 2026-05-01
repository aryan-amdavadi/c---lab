#include <iostream>
using namespace std;

class Item {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Item() {
        id = 0;
        name = "";
        price = 0;
        quantity = 0;
    }

    Item(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    int getId() {
        return id;
    }

    void addStock(int q) {
        if (q > 0) {
            quantity += q;
            cout << "Stock updated\n";
        } else {
            cout << "Invalid quantity\n";
        }
    }

    void sellItem(int q) {
        if (q <= 0) {
            cout << "Invalid quantity\n";
        } else if (q > quantity) {
            cout << "Insufficient stock\n";
        } else {
            quantity -= q;
            cout << "Sale successful\n";
        }
    }

    void display() {
        cout << "Item ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

int main() {
    Item items[100];
    int count = 0;
    int choice;

    do {
        cout << "\n1. Add Item\n2. Add Stock\n3. Sell Item\n4. Display Item\n5. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int id, q;
            string name;
            double price;
            cout << "Enter ID, Name, Price, Quantity: ";
            cin >> id >> name >> price >> q;
            items[count] = Item(id, name, price, q);
            count++;
        } else if (choice == 2) {
            int id, q;
            cout << "Enter Item ID and quantity: ";
            cin >> id >> q;
            for (int i = 0; i < count; i++) {
                if (items[i].getId() == id) {
                    items[i].addStock(q);
                }
            }
        } else if (choice == 3) {
            int id, q;
            cout << "Enter Item ID and quantity: ";
            cin >> id >> q;
            for (int i = 0; i < count; i++) {
                if (items[i].getId() == id) {
                    items[i].sellItem(q);
                }
            }
        } else if (choice == 4) {
            int id;
            cout << "Enter Item ID: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (items[i].getId() == id) {
                    items[i].display();
                }
            }
        }

    } while (choice != 5);

    return 0;
}