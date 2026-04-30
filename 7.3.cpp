#include <iostream>
using namespace std;

class Celsius
{
private:
    float cel;

public:
    Celsius()
    {
        cel = 0;
    }
    Celsius(float)
    {
        cel = c;
    }
    float getCelsius()
    {
        return cel;
    }
    void operator = (Fahrenheit obj);
    void display()
    {
        cout << "Celcius : " << cel;
    }
};
class Fahrenheit
{
private:
    float fah;

public:
    Fahrenheit()
    {
        fah = 0;
    }
    Fahrenheit(float f)
    {
        fah = f;
    }
    float getFahrenheit()
    {
        return fah;
    }
    void operator = (Celsius obj)
    {
        fah = (obj.getCelsius() * (9 / 5)) + 32;
    }
    void display()
    {
        cout << "Fahrenheit : " << fah;
    }
};
Celsius::void operator=(Fahrenheit obj)
{
    cel = (obj.getFahrenheit() - 32) * (5 / 9);
}
int main()
{
    Celsius c(15.00f);
    Fahrenheit f(20.00f);

    c = f;
    c.display();
}