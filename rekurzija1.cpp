#include <iostream>

using namespace std;

int fun(int a, int b) {
    if (a == b) return a;
    return fun(a + 1, b) + a;
}


int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    while (a > b)  {
        cout << "First number can't be bigger than the last number. Try again: ";
        cin >> a >> b;
    }
    cout << fun(a, b);
    return 0;
}