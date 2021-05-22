#include <iostream>

using namespace std;

int main() {
    bool end;
    int num[10];
    int n;
    cout << "Enter 10 numbers: " << endl;
    for (int i = 0; i < 10; i++) {
        cin >> num[i];
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bad entry.  Enter a NUMBER: " << endl;
            cin >> num[i];
        }
        for (int j = 1; j <= i; j++) {
            if (num[i] == num[j - 1]) {
                while (num[i] == num[j - 1]) {
                    cout << "The number " << num[i] << " was already entered in the " << j << ". element. Please try again: " << endl;
                    cin >> num[i];
                }
                j = 0;
            }
        }
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bad entry.  Enter a NUMBER: " << endl;
            cin >> num[i];
        }
    }

    while (true) {
        cout << "Add other numbers to check if they are already there or not (to stop enter -1):" << endl;
        cin >> n;
        if (n == -1) break;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bad entry.  Enter a NUMBER: " << endl;
            cin >> n;
        }
        end = false;
        for (int i = 0; i < 10; i++) {
            if (n == num[i]) {
                cout << "The number " << n << " already exists in the " << i + 1 << ". element of the array" << endl << endl;
                end = true;
            }
        }
        if (!end) cout << "This number is new" << endl << endl;
    }

    getchar();
    return 0;
}