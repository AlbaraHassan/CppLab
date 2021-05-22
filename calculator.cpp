#include <iostream>
#include <string>
using namespace std;

//ova funkcija služi za određivanje brojeva i operacija koje je korisnik unio
double mn(char *pok, char *pok2, double x) {
    double x1 = 0, y1 = 1;
    char j = '*';
    //ova gornja petlja određuje kada zaustaviti prvi pokazivač
    for (int i = 0; *pok != '*' && *pok != '/' && *pok != '+' && *pok != '-' && *pok != '\0'; i++) {
       //ova petlja služi za ignoriranje slučajnih praznih prostora koje je korisnik unio
        while (*pok2 == ' '){
            pok2++;
            pok++;
        }
        //ova petlja određuje koliko cifara ima broj
        while (*pok2 != '*' && *pok2 != '/' && *pok2 != '+' && *pok2 != '-' && *pok2 != '\0' && *pok2 !=' ') {
            x *= 10;
            pok2++;
        }
        //ovdje se sprema broj unesenog niza od strane korisnika
        x1 += x;
        pok++;
        pok2 = pok + 1;
        x = (*pok - 48);
        //ovdje određuje jesu li svi brojevi u potpunosti utvrđeni i koju operaciju korisnik želi
        if (*pok == '*' || *pok == '/' || *pok == '+' || *pok == '-' || *pok == '\0') {
            int kraj = 0;
            if (*pok == '\0') kraj = 1;
            if (j == '*') y1 *= x1;
            if (j == '/') y1 /= x1;
            if (j == '+') y1 += x1;
            if (j == '-') y1 -= x1;
            j = *pok;
            pok++;
            pok2++;
            //ova petlja služi za ignoriranje slučajnih praznih prostora koje je korisnik unio
            while (*pok == ' ') {
                pok2++;
                pok++;
            }
            x = (*pok - 48);
            x1 = 0;
            if (kraj == 1) return y1;
        }
    }
}


//main funkcija
int main() {
    char *pok, *pok2;
    char c[50];
    double x, ans;
//ovdje je petlja za provjeru želi li korisnik zatvoriti program
    while (c[0] != 'i'){
        cout << "za mnozenje '*' , za djelenje '/' , za dodavanje '+' , za uzimanje '-' , "<<"kada želite završiti, otkucajte 'izaci'"<<endl;
        cin.getline(c, ' ');
        if(c[0] == 'i')break;
        pok = &c[0];
        pok2 = pok + 1;
    //ova petlja služi za ignoriranje slučajnih praznih prostora koje je korisnik unio
        while (*pok == ' '){
            pok++;
            pok2++;
        }
        x = (*pok - 48);
        ans = mn(pok, pok2, x);
        cout << c<<"="<<ans<<endl<<endl<<endl;
    }
    getchar();
    return 0;
}
