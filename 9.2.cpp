#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string sentence, word;
    map<string, int> freq;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

    stringstream ss(sentence);

    while (ss >> word) {
        freq[word]++;
    }

    cout << "\nWord Frequencies:\n";
    for (auto &pair : freq) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}