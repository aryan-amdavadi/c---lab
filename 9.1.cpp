#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

// Function to print vector
void printVector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
    }

    // -------- Method 1: std::reverse --------
    vector<int> v1 = v;  // copy original
    reverse(v1.begin(), v1.end());

    cout << "\nReversed using std::reverse(): ";
    printVector(v1);

    // -------- Method 2: Manual using iterators --------
    vector<int> v2 = v;  // copy original

    auto start = v2.begin();
    auto end = v2.end() - 1;

    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }

    cout << "Reversed manually using iterators: ";
    printVector(v2);

    return 0;
}