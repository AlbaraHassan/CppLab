#include <iostream>
#include <string>

using namespace std;

bool checkIfNumber(string candidates) {
    for (char i : candidates)
        if (!isdigit(i))
            return false;
    return true;
}

int main() {
    while (true) {
        int num;
        cout << "Enter the number of candidates (type -1 to exit): ";
        cin >> num;
        if (num == -1) break;
        while (cin.fail() || num <= 0 || num > 40) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout
                    << "Bad entry.  The number of candidates cannot be more 0 or less than 0 or more than 40, and it has to be a number: "
                    << endl;
            cin >> num;
        }
        string candidates[num];
        int points[num];
        for (int i = 0; i < num; i++) {
            cout << "Enter the " << i + 1 << ". candidate's name: ";
            cin >> candidates[i];
            if (!checkIfNumber(candidates[i]));
            else if (checkIfNumber(candidates[i])) {
                cout << "Bad entry.  It has to be a name" << endl;
                i--;
            }
        }
        for (int i = 0; i < num; i++) {
            cout << "Enter how many points the " << i + 1 << ". candidate has: ";
            cin >> points[i];
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Bad entry.  Please enter a number: " << endl;
                cin >> points[i];
            }
        }
        for (int i = 0; i < num; i++) {
            if (points[i] < 60)
                cout << "The (" << i + 1 << ".) candidate (" << candidates[i] << ") FAILED the test with: " << points[i] << " points" << endl;
            else
                cout << "The (" << i + 1 << ".) candidate (" << candidates[i] << ") PASSED the test with: " << points[i] << " points" << endl;
        }
    }
    getchar();
    return 0;
}