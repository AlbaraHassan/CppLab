#include <iostream>
#include <string>

using namespace std;


bool checkIfNumber(string str) {
    for (char i : str)
        if (!isdigit(i))
            return false;
    return true;
}


int ifLeap(int year, int count) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                cout << year << " is a leap year" << endl<<endl;
                count = 1;
            } else cout << year << " is not a leap year" << endl<<endl;

        } else {
            cout << year << " is a leap year" << endl<<endl;
            count = 1;
        }
    } else cout << year << " is not a leap year" << endl<<endl;
    return count;
}

void monthCount(string month, int count) {
    bool correctMonth = false;
    string months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october",
                       "november", "december"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 12; i++) {
        if (month == months[i]) {
            if (count == 1 && i == 1) days[i]++;
            cout << month << " has " << days[i] << " days" << endl << endl;
            correctMonth = true;
        }
    }
    if (!correctMonth) cout << "There is no month named " << month << ", please try again " << endl << endl;
}

void monthCountNum(string month, int count) {

    bool correctMonth = false;
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
                       "November", "December"};
    string monthsNum[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 12; i++) {
        if (month == monthsNum[i]) {
            if (count == 1 && i == 1) days[i]++;
            cout << months[i] << " has " << days[i] << " days" << endl << endl;
            correctMonth = true;
        }
    }
    if (!correctMonth) cout << "There is no " << month << "." << " months" << endl << endl;
}


int main() {
    while (true) {
        int year, count = 0;
        string month;
        cout << "Type the year (0 to exit): " << endl;
        cin >> year;
        while(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Bad entry.  Enter a NUMBER: "<<endl;
            cin >> year;
        }
        if(year == 0) break;
        count = ifLeap(year, count);
        cout << "Enter the name or number of the month: " << endl;
        cin >> month;
        if (checkIfNumber(month)) {
            monthCountNum(month, count);
        } else {
            for_each(month.begin(), month.end(), [](char &c) {
                c = tolower(c);
            });
            monthCount(month, count);
        }
    }
    getchar();
    return 0;
}