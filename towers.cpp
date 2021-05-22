#include <iostream>

using namespace std;

void fun(int n, char src, char des, char pom) {

    if (n == 1) {
        cout << "Move " << n << " from rod " << src << " to rod " << des << endl;
        return;
    }
    fun(n - 1, src, pom, des);
    cout << "Move " << n << " from rod " << src << " to rod " << des << endl;
    fun(n - 1, pom, des, src);
}


int main() {
    fun(3, 'X', 'Z', 'Y');
    return 0;
}