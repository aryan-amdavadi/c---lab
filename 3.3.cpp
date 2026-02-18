#include<iostream>
using namespace std;

class Account{
    private:
        int acc_num;
        string acc_name;
        double balance;

        static int total_acc;
    public:
        Account(){
            acc_num = 0;
            acc_name = "null"
            balance = 0.0;
        }
        Account(int acc_num, string acc_name, double balance){
            this->acc_num=acc_num;
            this->acc_name=acc_name;
            this->balance=balance;

            total_acc++;
        }

        void display(){
            cout << endl << "Account Number : " << acc_num << endl;
            cout << "Account Name : " << acc_name << endl;
            cout << "Balance : " << balance << endl;
        }

        int getAccountNumber(){
            return accountNumber;
        }
        double getBalance(){
            return balance;
        }
        void depositAmount(double amount){
            if(amount>0){
                balance += amount;
                cout << endl << "Deposit made successfully." << endl;
            }else{
                cout << "Error!" << endl;
            }
        }
        int transferMoney(Account &rec, amount){
            if(amount<=0){
                cout << "Invalid value of amount." << endl;
                return 0;
            }
            if(amount>balance){
                cout << "Need more funds." << endl;
                return 0;
            }
            balance -= amount;
            rec.balance += amount;

            cout << "Transferrr Successs" << endl;
            return 1;
        }
        static void showTotalAcc(){
            cout << endl << "Total Accounts : " << total_acc << endl;
        }
};

int main(){
    Account *P = new Account[100];

    
}