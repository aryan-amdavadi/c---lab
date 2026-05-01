#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    string filename;
    ifstream file;

    // -------- 1. Retry mechanism for file opening --------
    while (true) {
        cout << "Enter file name (or type exit): ";
        cin >> filename;

        if (filename == "exit") {
            cout << "Exiting program.\n";
            return 0;
        }

        file.open(filename);

        if (file) {
            break;  // success
        } else {
            cout << "Error: Cannot open file. Try again.\n";
        }
    }

    string line;
    int lineNumber = 0;
    double totalSum = 0;
    int totalCount = 0;

    // -------- 2. Read file line by line --------
    while (getline(file, line)) {
        lineNumber++;

        try {
            stringstream ss(line);
            double num;
            bool hasData = false;

            // -------- 3. Process numbers in line --------
            while (ss >> num) {
                totalSum += num;
                totalCount++;
                hasData = true;
            }

            // -------- 4. Check for corrupted data --------
            if (!hasData || !ss.eof()) {
                throw runtime_error("Invalid data found");
            }
        }
        catch (exception &e) {
            cout << "Warning: Skipping invalid line " << lineNumber
                 << " → " << line << endl;
        }
    }

    file.close();

    // -------- 5. Final result --------
    cout << "\n--- Processing Result ---\n";

    if (totalCount > 0) {
        cout << "Total Sum = " << totalSum << endl;
        cout << "Average = " << totalSum / totalCount << endl;
    } else {
        cout << "No valid numeric data found.\n";
    }

    return 0;
}