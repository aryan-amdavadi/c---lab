#include <iostream>
#include <string>
using namespace std;

int main() {
    string paragraph;
    getline(cin, paragraph);

    for (int i = 0; i < paragraph.length(); i++) {
        if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
            paragraph[i] = paragraph[i] + 32;
    }

    string words[200];
    int n = 0;
    string temp = "";

    for (int i = 0; i < paragraph.length(); i++) {
        if (paragraph[i] != ' ' && paragraph[i] != '\t' && paragraph[i] != '\n') {
            temp += paragraph[i];
        } else {
            if (temp != "") {
                words[n++] = temp;
                temp = "";
            }
        }
    }
    if (temp != "")
        words[n++] = temp;

    string unique[200];
    int freq[200];
    int m = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < m; j++) {
            if (words[i] == unique[j]) {
                found = j;
                break;
            }
        }
        if (found == -1) {
            unique[m] = words[i];
            freq[m] = 1;
            m++;
        } else {
            freq[found]++;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << unique[i] << " : " << freq[i] << endl;
    }

    return 0;
}