#include <iostream>
using namespace std;

class Fuel {
protected:
    string fuelType;

public:
    Fuel(string f) {
        fuelType = f;
    }
};

class Brand {
protected:
    string brandName;

public:
    Brand(string b) {
        brandName = b;
    }
};

class Car : public Fuel, public Brand {
private:
    int id;

public:
    Car(int i, string f, string b) : Fuel(f), Brand(b) {
        id = i;
    }

    void display() {
        cout << "Car ID: " << id << endl;
        cout << "Brand: " << brandName << endl;
        cout << "Fuel: " << fuelType << endl;
    }
};

int main() {
    int choice;
    Car* queue[100];
    int front = 0, rear = -1;

    Car staticCars[100];
    int count = 0;

    do {
        cout << "\n1. Add Car (Queue)\n2. Process Car (Queue)\n3. Display Queue\n4. Add Car (Static)\n5. Display Static\n6. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int id;
            string fuel, brand;
            cout << "Enter id fuel brand: ";
            cin >> id >> fuel >> brand;
            queue[++rear] = new Car(id, fuel, brand);
        } else if (choice == 2) {
            if (front > rear) {
                cout << "Queue empty\n";
            } else {
                queue[front]->display();
                front++;
            }
        } else if (choice == 3) {
            if (front > rear) {
                cout << "Queue empty\n";
            } else {
                for (int i = front; i <= rear; i++) {
                    queue[i]->display();
                }
            }
        } else if (choice == 4) {
            int id;
            string fuel, brand;
            cout << "Enter id fuel brand: ";
            cin >> id >> fuel >> brand;
            staticCars[count++] = Car(id, fuel, brand);
        } else if (choice == 5) {
            for (int i = 0; i < count; i++) {
                staticCars[i].display();
            }
        }

    } while (choice != 6);

    return 0;
}