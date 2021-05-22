#include <iostream>

using namespace std;


int checkIfNum(int x) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Bad entry.  Please enter a number: " << endl;
        cin >> x;
    }
    return x;
}

int fun1(int &ref, int user) {
    int perHour, dailyHours, daysPerMonth, salary;
    cout << "User " << user << " =>" << " Please enter payment per hour: ";
    cin >> perHour;
    while (perHour <= 0) {
        cout << "Are you you sure that you have a job?? Please try again: ";
        cin >> perHour;
    }
    if (cin.fail()) perHour = checkIfNum(perHour);
    cout << "User " << user << " =>" << " How many hours of work a day?: ";
    cin >> dailyHours;
    while (dailyHours > 24 || dailyHours <= 0) {
        if (dailyHours <= 0) cout << "Are you even working ar all?? Please try again: ";
        else cout << "A day only has 24 hours. Please try again: ";
        cin >> dailyHours;
    }
    if (cin.fail()) dailyHours = checkIfNum(dailyHours);
    cout << "User " << user << " =>" << " How many days of work in a month?:";
    cin >> daysPerMonth;
    while (daysPerMonth > 31 || daysPerMonth <= 0) {
        if (daysPerMonth <= 0) cout << "That means that you are not working at all Please try again: ";
        else cout << "A month can only have 31 days maximum. Please try again: ";
        cin >> daysPerMonth;
    }
    if (cin.fail()) daysPerMonth = checkIfNum(daysPerMonth);
    ref = daysPerMonth;
    salary = perHour * dailyHours * daysPerMonth;
    cout << "User " << user << " =>" << " The monthly salary is: " << salary << endl;
    return salary;
}

void fun2(int pok2, int user, int &ref) {
    int dailySpent, monthlyCost;
    cout << "User " << user << " =>" << " How much is spent daily?: ";
    cin >> dailySpent;
    if (cin.fail()) dailySpent = checkIfNum(dailySpent);
    monthlyCost = (dailySpent * pok2);
    ref = monthlyCost;
    cout << "The monthly cost for the " << user << ". user is: " << monthlyCost << endl;

}

int fun3(int *pok, int user, int dailySpent) {
    cout << "The " << user << ". user would have " << *pok - dailySpent << " left by the end of the month" << endl;
    return *pok - dailySpent;
}

int main() {
    int salary[3], monthlyCost[3], stillHave[3];
    int daysPerMonth, user, dailySpent, still, count;
    int *pok;
    for (int i = 0; i < 3; i++) {
        user = i + 1;
        salary[i] = fun1(daysPerMonth, user);
        pok = &salary[i];
        fun2(daysPerMonth, user, dailySpent);
        stillHave[i] = fun3(pok, user, dailySpent);
    }

    cout << "The amount of money left from largest to smallest are: " << endl;

    for (int i = 0; i < 2; i++) {
        if (stillHave[i] < stillHave[i + 1]) {
            still = stillHave[i];
            stillHave[i] = stillHave[i + 1];
            stillHave[i + 1] = still;
            for (int j = 1; j < 1; j++) {
                still = stillHave[j];
                stillHave[j] = stillHave[j + 1];
                stillHave[j + 1] = still;
            }
        }
    }
    for (int i = 0; i < 3; i++) cout << stillHave[i] << endl;


    getchar();
    return 0;
}