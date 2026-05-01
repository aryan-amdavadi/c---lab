#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    set<int> s;  // automatically unique + sorted

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        s.insert(value);  // duplicates ignored
    }

    // -------- Display using iterators --------
    cout << "\nUnique sorted elements (using set): ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }

    // -------- Convert set to vector --------
    vector<int> v(s.begin(), s.end());

    cout << "\nConverted to vector: ";
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}