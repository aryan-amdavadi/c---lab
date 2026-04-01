#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int *arr1 = new int[n];
    int *arr2 = new int[m];
    int *fin = new int[n + m];

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    cout << endl
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << "|";
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << "|";
    }
    cout << endl;
    int i = 0, j = 0, k = 0;
    while (j < n && k < m)
    {
        cout << "Array 1 : " << arr1[j] << endl;
        cout << "Array 2 : " << arr2[k] << endl;

        if (arr1[j] <= arr2[k])
        {
            cout << "Array Fin : " << arr1[j] << endl
                 << endl;
            fin[i++] = arr1[j++];
        }
        else
        {
            cout << "Array Fin : " << arr2[k] << endl
                 << endl;
            fin[i++] = arr2[k++];
        }
    }

    while (j < n)
    {
        fin[i++] = arr1[j++];
    }

    while (k < m)
    {
        fin[i++] = arr2[k++];
    }

    cout << "Final Array : ";
    for (int p = 0; p < n + m; p++)
    {
        cout << fin[p] << "|";
    }
    cout << endl;

    return 0;
}