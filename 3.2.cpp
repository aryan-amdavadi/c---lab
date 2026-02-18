#include<iostream>
using namespace std;

int rec_sum(int arr[],int n){
    if(n<=0){
        return 0;
    }
    return arr[n-1] + rec_sum(arr, n-1);
}

int ite_sum(int arr[], int n){
    int sum = 0;
    for(int i =0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int n,i;

    cout << "How many numbers you want to add : ";
    cin >> n;

    int *P = new int[n];

    for(i=0;i<n;i++){
        cout << endl << "Enter Number " << i+1 << " : ";
        cin >> P[i];
    }

    cout << endl << "Function Call of Iterative Loop :" << endl;
    cout << ite_sum(P,n);

    cout << endl << "Function call of Recursive Loop :" << endl;
    cout << rec_sum(P,n);
}