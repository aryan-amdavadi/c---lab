#include <iostream>
using namespace std;

class Account{
protected:
    int accountNumber;
    double balance;
    int transaction[100]={0};
public:
    Account(){
        accountNumber=0;
        balance=0;
        i=0;
    }
    Account(int acc_num, double b){
        accountNumber = acc_num;
        balance = b;
    }
    void display(){
        cout << "\nAccount Number : " << accountNumber << "\nBalance : " << balance << endl;
    }
    void deposit(double amount){
        balance += amount;
        transaction[i] = amount;
        i++;
        cout << "Deposit Successfull." << endl;
    }
    void withdraw(double amount){
        if(balance < amount){
            cout << "Insufficient Balance." << endl;
            return ;
        }
        transaction[i] = -1*amount;
        i++;
        balance -= amount;
        cout << "Withdraw Successfull." << endl;
    }
    int getAccountNo(){
        return accountNumber;
    }
    void displayTransaction(){
        for(int j = 0; j<i;j++){
            cout << transaction[i] << "|";
        }
    }
    void latestTransaction(){
        cout << transaction[i-1];
        balance += transaction[i-1];
        transaction[i-1] = 0;
        i--;
    }
    ~Account(){
        cout << "Destroyed Base Object." << endl;
    }
};
class Savings:public Account{
private:
    float interestRate;
public:
    Savings(){
        interestRate=0.00;
    }
    Savings(int acNo, double bal, float intr){
        Account(acNo,bal);
        interestRate=intr;
    }
    void display(){
        Account::display();
        cout << "Interest Rate : " << interestRate << endl;
    }
    ~Savings(){
        cout << "Destroyed Savings Object." << endl;
    }
};
class Current:public Account{
private:
    int overdraftLimit;
public:
    Current(){
        overdraftLimit=0;
    }
    Current(int acNo, double bal, int limit){
        Account(acNo,bal);
        overdraftLimit = limit;
    }
    void display(){
        Account::display();
        cout << "Overdraft Limit : " << overdraftLimit << endl;
    }
    ~Current(){
        cout << "Destroyed Current Object." << endl;
    }
};

int main(){
    int ch,i=0,j=0;
    Savings S[10];
    Current C[10];
    do{
        cout << "1. Add Savings Account." << endl;
        cout << "2. Add Current Account." << endl;
        cout << "3. Deposit Money." << endl;
        cout << "4. Withdraw Money." << endl;
        cout << "5. Display Records." << endl;
        cout << "6. Search By Account No." << endl;
        cout << "7. Display Transactions." << endl;
        cout << "8. Undo Last Transactions." << endl;
        cout << endl << "Enter Your Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:{
            int acNo;
            double bal;
            float intRate;

            cout << "\nEnter Account Number : ";
            cin >> acNo;
            cout << "Enter Balance : ";
            cin >> bal;
            cout << "Enter interest Rate : ";
            cin >> intRate;
            if(i > 10){
                return 1;
            }
            S[i] = Savings(acNo, bal, intRate);
            i++;
            cout << "Savings Account Created Successfull." << endl;
            break;
        }
        case 2:{
            int acNo,limit;
            double bal;

            cout << "\nEnter Account Number : ";
            cin >> acNo;
            cout << "Enter Balance : ";
            cin >> bal;
            cout << "Enter Overdraft Limit : ";
            cin >> limit;
            if(j > 10){
                return 1;
            }
            C[j] = Current(acNo, bal, limit);
            j++;
            cout << "Current Account Created Successfull." << endl;
            break;
        }
        case 3:{
            int sAcNo;
            cout << "Enter Account Number : ";
            cin >> sAcNo;

            //code to check account in savings Account
            for(int k = 0; k < i; k++){
                if(sAcNo == S[k].getAccountNo()){
                    double dBal;
                    cout << "Enter Amount To Deposit : ";
                    cin >> dBal;
                    S[k].deposit(dBal);
                    break;
                }
            }
            //code to check account in current Account
            for(int k = 0; k < j; k++){
                if(sAcNo == C[k].getAccountNo()){
                    double dBal;
                    cout << "Enter Amount To Deposit : ";
                    cin >> dBal;
                    C[k].deposit(dBal);
                    break;
                }
            }
        }
        case 4:{
            int sAcNo;
            cout << "Enter Account Number : ";
            cin >> sAcNo;

            //code to check account in savings Account
            for(int k = 0; k < i; k++){
                if(sAcNo == S[k].getAccountNo()){
                    double wBal;
                    cout << "Enter Amount To Withdraw : ";
                    cin >> wBal;
                    S[k].withdraw(wBal);
                    break;
                }
            }
            //code to check account in current Account
            for(int k = 0; k < j; k++){
                if(sAcNo == C[k].getAccountNo()){
                    double wBal;
                    cout << "Enter Amount To Withdraw : ";
                    cin >> wBal;
                    C[k].withdraw(wBal);
                    break;
                }
            }
        }
        case 5:{
            for(int k = 0; k < j; k++){
                C[k].display();
                cout << endl;
            }
            for(int k = 0; k < i; k++){
                S[k].display();
                cout << endl;
            }
        }
        case 6:{
            int sAcNo;
            cout << "Enter Account Number : ";
            cin >> sAcNo;
            //code to check account in savings Account
            for(int k = 0; k < i; k++){
                if(sAcNo == S[k].getAccountNo()){
                    S[k].display();
                    break;
                }
            }
            //code to check account in current Account
            for(int k = 0; k < j; k++){
                if(sAcNo == C[k].getAccountNo()){
                    C[k].display();
                    break;
                }
            }
        }
        case 7:{
            break;
        }
        default:
            break;
        }
    }while(ch != 7);
}