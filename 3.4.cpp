#include <iostream>
using namespace std;

template <typename T>
T findMax(T arr[], int n) {
    T mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

template <typename T>
void reverseArray(T arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

template <typename T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
void leaders(T arr[], int n) {
    T maxRight = arr[n - 1];
    cout << maxRight << " ";
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            maxRight = arr[i];
            cout << maxRight << " ";
        }
    }
    cout << endl;
}

int main() {
    int a[] = {16, 17, 4, 3, 5, 2};
    int n1 = 6;

    float b[] = {1.2, 3.4, 2.1, 5.6, 4.0};
    int n2 = 5;

    char c[] = {'a', 'z', 'b', 'y', 'c'};
    int n3 = 5;

    display(a, n1);
    cout << findMax(a, n1) << endl;
    reverseArray(a, n1);
    display(a, n1);
    leaders(a, n1);

    display(b, n2);
    cout << findMax(b, n2) << endl;
    reverseArray(b, n2);
    display(b, n2);
    leaders(b, n2);

    display(c, n3);
    cout << findMax(c, n3) << endl;
    reverseArray(c, n3);
    display(c, n3);
    leaders(c, n3);

    return 0;
}