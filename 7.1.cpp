#include <iostream>
using namespace std;

class Calculator{
private:
    float results[100];
    int resultCount;
public:
    Calculator() : resultCount(0) {}
    int add(int a, int b) {
        return a + b;
    }
    float add(float a, float b) {
        return a + b;
    }
    float add(int a, float b) {
        return a + b;
    }
    float add(float a, int b) {
        return a + b;
    }
    void storeResult(float res) {
        if(resultCount < 100) {
            results[resultCount] = res;
            resultCount++;
        }
    }
    void displayResults() {
        cout << "Stored Results:" << endl;
        for(int i = 0; i < resultCount; i++) {
            cout << "Result " << (i+1) << ": " << results[i] << endl;
        }
    }
};

int main(){
    Calculator calc;
    
    int ch;
    float res;


    do{
        cout << "1. int - int Calculator. " << endl;
        cout << "2. float - float Calculator. " << endl;
        cout << "3. int - float Calculator. " << endl;
        cout << "4. float - int Calculator. " << endl;
        cout << "5. Exit. " << endl;
        cout << "\nEnter Your Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            int a,b;
            cout << "Enter two integers: ";
            cin >> a >> b;
            res = calc.add(a,b);
            cout << "Result : " << res << endl;
            calc.storeResult(res);
            break;
        case 2:
            float x,y;
            cout << "Enter two floats: ";
            cin >> x >> y;
            res = calc.add(x,y);
            cout << "Result : " << res << endl;
            calc.storeResult(res);
            break;
        case 3:
            int c;
            float d;
            cout << "Enter int and float: ";
            cin >> c >> d;
            res = calc.add(c,d);
            cout << "Result : " << res << endl;
            calc.storeResult(res);
            break;
        case 4:
            float e;
            int f;
            cout << "Enter float and int: ";
            cin >> e >> f;
            res = calc.add(e,f);
            cout << "Result : " << res << endl;
            calc.storeResult(res);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }while(ch != 5);
    
    calc.displayResults();
    
    return 0;
}