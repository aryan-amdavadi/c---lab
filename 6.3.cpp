#include <iostream>
#include <string>
using namespace std;

class Fuel {
protected:
    string fuelType;
public:
    Fuel(){
        fuelType = "";
    }
    Fuel(string n){
        fuelType = n;
    }
    void display() {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Brand{
protected:
    string brand;
    string model;
public:
    Brand(){
        brand = model = "";
    }
    Brand(string b, string m){
        brand = b;
        model = m;
    }
    void display() {
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
    }
};

class Car : public Brand, public Fuel{
protected:
    int modelID;
public:
    Car(){
        modelID = 0;
    }
    Car(string ft, string b, string m, int mID){
        Fuel::fuelType = ft;
        Brand::brand = b;
        Brand::model = m;
        modelID = mID;
    }
    void display() {
        Fuel::display();
        Brand::display();
        cout << "Model ID : " << modelID << endl;
    }
};

int main() {
    int n;
    cout << "Enter Number Of Objects : ";
    cin >> n;
    Car obj[n];

    for(int i = 0; i < n; i++){
        string ft, br, mn;
        int mID;
        cout << "\nEnter Fuel Type For " << i+1 << " : ";
        cin >> ft;
        cout << "\nEnter Brand Name For " << i+1 << " : ";
        cin >> br;
        cout << "\nEnter Model For " << i+1 << " : ";
        cin >> mn;
        cout << "\nEnter Model Id For " << i+1 << " : ";
        cin >> mID;
        obj[i] = Car(ft, br, mn, mID);
    }

    cout << "\n\n";
    for(int i = 0; i < n; i++){
        obj[i].display();
        cout << "\n\n";
    }
    return 0;
}