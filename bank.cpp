#include <iostream>

using namespace std;

void checkIfNumber(int &num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Bad entry.  Enter a NUMBER: " << endl;
        cin >> num;
    }
}

bool login(string name, string password) {
    string name1, pass1;
    cout << "\nTo login enter username: ";
    cin >> name1;
    cout << "To login enter password: ";
    cin >> pass1;
    if (name1 == name && pass1 == password) {
        cout << "\nWelcome " << name << endl;
        return true;
    } else {
        cout << "username or password is incorrect" << endl;
        return false;
    }
}

bool login1(string name, string password) {
    if (login(name, password)) return true;
    if (login(name, password)) return true;
    return login(name, password);
}

int menu(double money) {
    int n1;
    cout << "\nYou have: " << money << " KM" << endl;
    cout << "1. Withdraw" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Sign out" << endl;
    cin >> n1;
    checkIfNumber(n1);
    return n1;
}

void withdraw(double &money) {
    int x;
    cout << "\nEnter the amount of money you want to withdraw: ";
    cin >> x;
    checkIfNumber(x);
    if (money > x) money -= x;
    else cout << "Not enough credit" << endl;
}

void deposit(double &money) {
    int x;
    cout << "\nEnter the amount of money you want to deposit: ";
    cin >> x;
    checkIfNumber(x);
    money += x;
}


void reg(string &name, string &password, bool &ifreg) {
    ifreg = true;
    cout << "\nTo register ";
    cout << "enter your username: ";
    cin >> name;
    cout << "and enter you password: ";
    cin >> password;
}

int startMenu() {
    int n;
    cout << "\n1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose a section: ";
    cin >> n;
    checkIfNumber(n);
    return n;
}


int main() {
    string name, password;
    double money = 500;
    int n, n1;
    bool ifreg = false;
    while (true) {
        n = startMenu();
        if (n == 1) reg(name, password, ifreg);
        else if (n == 2) {
                if (!ifreg) {
                    cout << "\n\nPLEASE REGISTER FIRST\n" << endl;
                    continue;
                }
           if (login1(name, password)) {
               while (true){
                n1 = menu(money);
                if (n1 == 1) withdraw(money);
                else if (n1 == 2) deposit(money);
                else if (n1 == 3)break;
                else cout << "\nInvalid id" << endl;
               }
            } else break;
        } else if (n == 3) break;
        else cout << "\nInvalid id" << endl;
    }
    getchar();
    return 0;
}