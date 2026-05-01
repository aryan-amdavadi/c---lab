#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n1. Add Item\n2. View All Items\n3. Search Item\n4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            ofstream out("inventory.txt", ios::app);
            string name;
            int quantity;
            double price;

            cout << "Enter name quantity price: ";
            cin >> name >> quantity >> price;

            out << name << " " << quantity << " " << price << endl;
            out.close();
        } else if (choice == 2) {
            ifstream in("inventory.txt");
            if (!in.is_open()) {
                cout << "File error\n";
            } else {
                string name;
                int quantity;
                double price;

                while (in >> name >> quantity >> price) {
                    cout << name << " " << quantity << " " << price << endl;
                }
                in.close();
            }
        } else if (choice == 3) {
            ifstream in("inventory.txt");
            if (!in.is_open()) {
                cout << "File error\n";
            } else {
                string search;
                cout << "Enter name: ";
                cin >> search;

                string name;
                int quantity;
                double price;
                int found = 0;

                while (in >> name >> quantity >> price) {
                    if (name == search) {
                        cout << name << " " << quantity << " " << price << endl;
                        found = 1;
                    }
                }

                if (!found)
                    cout << "Item not found\n";

                in.close();
            }
        }

    } while (choice != 4);

    return 0;
}