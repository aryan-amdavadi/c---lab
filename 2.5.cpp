#include <iostream>
#include <cmath>
using namespace std;

class Loan
{
private:
    int loan_id;
    string applicant_name;
    double loan_amount;   // Principle amount
    double interest_rate; // R
    int loan_tenure;      // T
public:
    Loan()
    {
        loan_id = 0;
        applicant_name = "null";
        loan_amount = 0.0;
        interest_rate = 0.0;
        loan_tenure = 0;
    }
    Loan(int id, string name, double amount, double rate, int tenure)
    {
        loan_id = id;
        applicant_name = name;

        if (amount > 0)
        {
            loan_amount = amount;
        }
        else
        {
            cout << "Invalid Amount" << endl;
            loan_amount = 0;
        }

        if (rate > 0)
        {
            interest_rate = rate;
        }
        else
        {
            cout << "Invalid Rate." << endl;
            interest_rate = 0;
        }

        if (tenure > 0)
        {
            loan_tenure = tenure;
        }
        else
        {
            cout << "Invalid Rate." << endl;
            loan_tenure = 0;
        }
    }
    double calculateEMI()
    {
        if (loan_amount == 0 || interest_rate == 0 || loan_tenure == 0)
        {
            return 0;
        }
        double monthlyRate = interest_rate / (12 * 100);
        double EMI = (loan_amount * monthlyRate * pow(1 + monthlyRate, loan_tenure)) /
                     (pow(1 + monthlyRate, loan_tenure) - 1);
        return EMI;
    }
    void display(){
        cout << "--- Loan Details ---" << endl << endl;
        cout << "Loan ID : " << loan_id << endl;
        cout << "Applicant Name : " << applicant_name << endl;
        cout << "Loan Amount : " << loan_amount << endl;
        cout << "Interest Rate : " << interest_rate << endl;
        cout << "Loan Tenure : " << loan_tenure << endl;
        cout << "Monthly EMI: " << calculateEMI() << endl;
    }
};


int main()
{
    Loan l[100];
    int count = 0;
    int ch;

    do
    {
        cout << "\n1. Apply for Loan";
        cout << "\n2. Display All Loans";
        cout << "\n3. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            if (count >= 100)
            {
                cout << "Loan storage full!\n";
                break;
            }

            int id, tenure;
            string name;
            double amount, rate;

            cout << "Enter Loan ID: ";
            cin >> id;

            cout << "Enter Applicant Name: ";
            cin >> name;

            cout << "Enter Loan Amount: ";
            cin >> amount;

            cout << "Enter Interest Rate (annual %): ";
            cin >> rate;

            cout << "Enter Loan Tenure (in months): ";
            cin >> tenure;

            l[count] = Loan(id, name, amount, rate, tenure);
            count++;

            cout << "Loan Applied Successfully!\n";
            break;
        }

        case 2:
        {
            if (count == 0)
            {
                cout << "No loans available.\n";
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    l[i].display();
                }
            }
            break;
        }

        case 3:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (ch != 3);

    return 0;
}