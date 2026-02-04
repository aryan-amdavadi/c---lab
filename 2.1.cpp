#include <iostream>
using namespace std;

class Rectangle
{
private:
    float length;
    float width;

public:
    void dimensions(float l, float w)
    {
        if (l > 0 && w > 0)
        {
            length = l;
            width = w;
        }
        else
        {
            cout << "Invalid Inputs." << endl;
        }
    }

    float calculateArea()
    {
        cout << "Area : " << length * width << endl;
        return length * width;
    }

    float calculatePerimeter()
    {
        cout << "Perimeter : " << length * width << endl;
        return 2 * (length + width);
    }

    void display()
    {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
        cout << "-----------------------------\n";
    }
};

int main()
{
    int rectC = 0, ch;

    Rectangle rect[100];

    do
    {
        cout << "----Menu----" << endl;
        cout << "1. Add Rectangle" << endl;
        cout << "2. Perimeter of rectangle" << endl;
        cout << "3. Area of rectangle" << endl;
        cout << "4. Display Every Rectangle" << endl;
        cout << "5. Update Dimensions of rectangle" << endl;
        cout << "6. Exit" << endl;
        cout << endl
             << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {

            float l, w;
            cout << "\nEnter details for Rectangle " << rectC + 1 << endl;
            cout << "Length: ";
            cin >> l;
            cout << "Width: ";
            cin >> w;

            rect[rectC].dimensions(l, w);
            rectC++;
            break;
        }
        case 2:
        {
            cout << "\n--- Perimeter Details ---\n";
            for (int i = 0; i < rectC; i++)
            {
                cout << "Rectangle " << i + 1 << endl;
                rect[i].calculatePerimeter();
            }
            break;
        }
        case 3:
        {
            cout << "\n--- Area Details ---\n";
            for (int i = 0; i < rectC; i++)
            {
                cout << "Rectangle " << i + 1 << endl;
                rect[i].calculatePerimeter();
            }
            break;
        }
        case 4:
        {
            cout << "\n--- Rectangle Details ---\n";
            for (int i = 0; i < rectC; i++)
            {
                cout << "Rectangle " << i + 1 << endl;
                rect[i].display();
            }
            break;
        }
        case 5:
        {
            int n;
            cout << "Enter the number of rectangle to change : " << endl;
            cin >> n;

            float l, w;
            cout << "\nEnter details for Rectangle " << n << endl;
            cout << "Length: ";
            cin >> l;
            cout << "Width: ";
            cin >> w;

            rect[n - 1].dimensions(l, w);
        }
        }
    } while (ch != 6);

    return 0;
}
