#include <iostream>

using namespace std;

bool isPrime(int pom) {
    for (int i = 2; i < pom; i++) {
        if (pom % i == 0) return false;
    }
    return true;
}

void checkIfNumber(int &num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Bad entry.  Enter a NUMBER: " << endl;
        cin >> num;
    }
}

void program(){
    while (true) {
        int fst, lst, pom;
        cout << "To exit, enter -1" << endl;
        cout << "Enter the first number: ";
        cin >> fst;
        checkIfNumber(fst);
        if (fst == -1) break;
        cout << "Enter the last number: ";
        cin >> lst;
        checkIfNumber(lst);
        pom = fst;
        while (pom <= lst) {
            if (isPrime(pom)) cout << pom << endl;
            pom++;
        }
        cout << "\n";
    }
}

int main() {
    program();
    getchar();
    return 0;
}