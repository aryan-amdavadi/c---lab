#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(){
        name = "";
        age = 0;
    }
    Person(string n, int a){
        name = n;
        age = a;
    }
    void display() {
        cout << "Name: " << name << endl << "Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int employeeID;
public:
    Employee(){
        employeeID = 0;
    }
    Employee(string n, int a, int id){
        name = n;
        age = a;
        employeeID = id;
    }
    void display() {
        Person::display();
        cout << "Employee ID: " << employeeID << endl;
    }
    int getID(){
        return employeeID;
    }
};

class Manager : public Employee{
protected:
    string block;
public:
    Manager(){
        block = "";
    }
    Manager(string n, int a, int id, string b){
        Employee::name = n;
        Employee::age = a;
        employeeID = id;
        block = b;
    }
    void display() {
        Employee::display();
        cout << "Block: " << block << endl;
    }

};

int main() {
    int n;
    cout << "Enter Number Of Objects : ";
    cin >> n;
    Manager obj[n];

    for(int i = 0; i < n; i++){
        string na, bl;
        int ag, ID;
        cout << "\nEnter Name For " << i+1 << " : ";
        cin >> na;
        cout << "\nEnter Age For " << i+1 << " : ";
        cin >> ag;
        cout << "\nEnter ID For " << i+1 << " : ";
        cin >> ID;
        cout << "\nEnter Block For " << i+1 << " : ";
        cin >> bl;
        obj[i] = Manager(na, ag, ID, bl);
    }
    for(int i = 0; i < n; i++){
        obj[i].display();
        cout << "\n\n";
    }

    int s_ID;
    cout << "\nEnter ID To Search : ";
    cin >> s_ID;
    for(int i = 0; i < n; i++){
        if(obj[i].getID()==s_ID){
            cout << "\nID Found : \n";
            obj[i].display();
        }
    }

    return 0;
}
