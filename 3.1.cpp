#include<iostream>
using namespace std;

class Employee{
    private:
        string name;
        float basic_salary;
        float bonus_amt;
    public:
        Employee(){
            name = "null";
            basic_salary = 0.0;
            bonus_amt = 0.0;
        }
        Employee(string n, float bs, float b = 1000)
        {
           name = n;
           basic_salary = bs;
           bonus_amt = b;
        }
        inline float calculateSalary(){
            return basic_salary + bonus_amt;
        }

        void display(){
            cout << endl << "Name : " << name << endl;
            cout << "Basic Salary : " << basic_salary << endl;
            cout << "Bonus Salary : " << bonus_amt << endl;
            cout << "Total Salary : " << calculateSalary() << endl << endl;
        }
};
int main(){

    int n;
    cout << "Enter Number of Employee : ";
    cin >> n;


    Employee *E = new Employee[n];


    string name;
    float basic, bonus;
    char choice;

    for(int i = 0; i < n; i++){
        cout << "\nEnter details for Employee " << i + 1 << endl;

        cout << "Name: ";
        cin >> name;

        cout << "Basic Salary: ";
        cin >> basic;

        cout << "Bonus (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            cout << "Enter Bonus: ";
            cin >> bonus;
            E[i] = Employee(name, basic, bonus);
        }
        else
        {
            E[i] = Employee(name, basic);
        }
    }

    cout << "\nEmployee Details:\n";
    for (int i = 0; i < n; i++)
    {
        E[i].display();
    }

    return 0;
}

