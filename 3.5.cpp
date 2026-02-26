#include <iostream>
using namespace std;

long long superDigit(long long num)
{
    // Base case
    if (num < 10)
        return num;

    long long sum = 0;

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return superDigit(sum); 
}

int main()
{
    string n;
    int k;

    cout << "Enter number (as string): ";
    cin >> n;

    cout << "Enter value of k: ";
    cin >> k;

    long long initialSum = 0;
    int num = stoi(n);

    while(num!=0){
        initialSum += num%10;
        num /= 10;
    }

    long long total = initialSum * k;

    long long result = superDigit(total);

    cout << "Super Digit: " << result << endl;

    return 0;
}