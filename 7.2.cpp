#include <iostream>
using namespace std;

class Complex{
private:
    double real,imag;
public:
    Complex(){
        real=0;
        imag=0;
    }
    Complex(double r, double i){
        real = r;
        imag = i;
    }
    double getReal(){
        return real;
    }
    double getImag(){
        return imag;
    }
    void operator + (Complex obj){
        real = real + obj.getReal();
        imag = imag + obj.getImag();
    }
    void operator - (Complex obj){
        real = real - obj.getReal();
        imag = imag - obj.getImag();
    }
    void display(){
        cout << real;
        if(imag > 0){
            cout << " + i" << imag << endl;
        }else{
            cout << " - i" << -1*imag << endl;
        }
    }
};

int main(){
    Complex A(2,2);
    Complex B(4,4);
    A - B;
    A.display();
}