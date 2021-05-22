#include <iostream>
#include <string>

void menu();

using namespace std;

void checkIfNumber(int &num) {
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Bad entry.  Enter a NUMBER: " << endl;
        cin >> num;
    }
}

bool menuPop(int &money) {
    int x;
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPOP SONGS\n\n";
    cout << "\t\t\t\t\t\t↓ Choose one of the following songs ↓\n\n";
    cout << "\t\t\t\t\t\t\t\tArtist: Black Eyed Peas\n\n\n";
    cout << "\t\t\t\t\t1. Where Is The Love?" << "\t\t\t3. Let's Get It Started\n\n";
    cout << "\t\t\t\t\t2. Pump It" << "\t\t\t\t\t\t4. Boom Boom Pow\n\n";
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tYOU HAVE " << money << " KM\n";
    if (money >= 1) {
        cin >> x;
        checkIfNumber(x);
        money --;
        return true;
    } else return false;
}

bool menuRnr(int &money) {
    int x;
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tROCK n ROLL SONGS\n\n";
    cout << "\t\t\t\t\t\t↓ Choose one of the following songs ↓\n\n";
    cout << "\t\t\t\t\t\t\t\tArtist: Imagine Dragons\n\n\n";
    cout << "\t\t\t\t\t1. Where Is The Love?" << "\t\t\t3. Let's Get It Started\n\n";
    cout << "\t\t\t\t\t2. Pump It" << "\t\t\t\t\t\t4. Boom Boom Pow\n\n";
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tYOU HAVE " << money << " KM\n";
    if (money >= 1) {
        cin >> x;
        checkIfNumber(x);
        money --;
        return true;
    } else return false;
}

bool menuTeh(int &money) {
    int x;
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tTECHNO SONGS\n\n";
    cout << "\t\t\t\t\t\t↓ Choose one of the following songs ↓\n\n";
    cout << "\t\t\t\t\t\t\t\tArtist: Daft Punk\n\n\n";
    cout << "\t\t\t\t\t1. Where Is The Love?" << "\t\t\t3. Let's Get It Started\n\n";
    cout << "\t\t\t\t\t2. Pump It" << "\t\t\t\t\t\t4. Boom Boom Pow\n\n";
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tYOU HAVE " << money << " KM\n";
    if (money >= 1) {
        cin >> x;
        checkIfNumber(x);
        money --;
        return true;
    } else return false;
}

bool menuRap(int &money) {
    int x;
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tRAP SONGS\n\n";
    cout << "\t\t\t\t\t\t↓ Choose one of the following songs ↓\n\n";
    cout << "\t\t\t\t\t\t\t\tArtist: Eminem\n\n\n";
    cout << "\t\t\t\t\t1. Where Is The Love?" << "\t\t\t3. Let's Get It Started\n\n";
    cout << "\t\t\t\t\t2. Pump It" << "\t\t\t\t\t\t4. Boom Boom Pow\n\n";
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tYOU HAVE " << money << " KM\n";
    if (money >= 1) {
        cin >> x;
        checkIfNumber(x);
        money --;
        return true;
    } else return false;
}


void toAdd(int &money) {
    int x;
    cout << "\n\n\n\t\t\t\t\t\tEnter the amount that you want to add\n\n";
    cin >> x;
    checkIfNumber(x);
    money += x;
    cout << "Now you have " << money << endl;
}

int startMenu() {
    int n;
    cout << "\n\n\n\t\t\t\t\t\t\t\tWELCOME TO THE JUKEBOX\n\n";
    cout << "\t\t\t\t\t\t↓ Choose one of the following genres ↓\n\n\n";
    cout << "\t\t\t\t\t\t\t1. POP" << "\t\t\t\t\t3. TECHNO\n\n";
    cout << "\t\t\t\t\t\t\t2. ROCK n ROLL" << "\t\t\t4. RAP\n";
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t0 to exit\n" ;
    cin >> n;
    checkIfNumber(n);
    return n;
}

int fun (bool (*x)(int &), void (*toAdd)(int &), string toadd, int &money){
    if (!x(money)) {
        cout << "\n\n\n\t\t\t\t\t\tDo you want to add credit? (Yes/No)\n\n";
        cin >> toadd;
        for_each(toadd.begin(), toadd.end(), [](char &toadd) {
            toadd = tolower(toadd);
        });
        if (toadd == "yes") toAdd(money);
        else return 0;
    }
    return 1;
}

void menu() {
    string toadd;
    int genre, money = 2;
    bool (* arr [])(int &) = {menuPop,menuRnr, menuTeh, menuRap};
    while (true) {
        genre = startMenu();
        if (genre < 0 || genre > 5) {
            cout << "\n\n\nInvalid id\n\n\n";
            continue;
        }
        if (genre == 0 || fun (arr[genre - 1] ,toAdd,toadd,money) == 0 ) return;
    }
}

int main() {
    menu();
    return 0;
}
