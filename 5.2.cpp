#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;
    cin >> filename;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 0;
    }

    string line;
    int lines = 0, words = 0, characters = 0;

    while (getline(file, line)) {
        lines++;
        bool inWord = false;

        for (int i = 0; i < line.length(); i++) {
            characters++;

            if (line[i] != ' ' && line[i] != '\t') {
                if (!inWord) {
                    words++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
    }

    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << characters << endl;

    file.close();
    return 0;
}