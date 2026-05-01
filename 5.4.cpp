#include <iostream>
#include <iomanip>
using namespace std;

ostream& currency(ostream& out) {
    out << "₹";
    return out;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    string name[100];
    double marks[100];
    double fees[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter name marks fees: ";
        cin >> name[i] >> marks[i] >> fees[i];
    }

    cout << setfill('-') << setw(50) << "-" << endl;
    cout << setfill(' ');
    cout << setw(15) << "Name" 
         << setw(15) << "Marks" 
         << setw(20) << "Fees" << endl;
    cout << setfill('-') << setw(50) << "-" << endl;
    cout << setfill(' ');

    for (int i = 0; i < n; i++) {
        cout << setw(15) << name[i]
             << setw(15) << fixed << setprecision(2) << marks[i]
             << setw(5) << currency << setw(15) << fixed << setprecision(2) << fees[i]
             << endl;
    }

    cout << setfill('-') << setw(50) << "-" << endl;

    return 0;
}