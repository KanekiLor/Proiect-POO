#include <iostream>
using namespace std;


class Produs {
private:
    string nume;
    double pret;
    int stoc;
public:
    Produs(const string& n,double p,int s) : nume(n),pret(p),stoc(s){};
    void getNume(){return nume;};
    void getPret(){return pret;};
    void getStoc(){return stoc;};
};

class Client{
private:
    string nume;
    string adresa;
public:
    Client(const string& n,const string& a) : nume(n),adresa(a){};
    void getNume(){return nume;};
    void getAdresa(){return adresa;};
};


class InterfataUtilizator {
public:
    void afiseazaMeniu(){
        cout << "Meniu:\n";
        cout << "1. Vizualizare produse disponibile\n";
        cout << "2. Adăugare produs în coș\n";
        cout << "3. Vizualizare coș de cumpărături\n";
        cout << "4. Efectuare comandă\n";
        cout << "5. Ieșire\n";
    };
};


 int main()
 {
     InterfataUtilizator Interfata;
     int optiune;
     while(true){
         Interfata.afiseazaMeniu();
         cout << "Alegeți o opțiune: ";
         cin >> optiune;

         if (optiune == 5) {
             cout << "La revedere!\n";
             break;
         } else {
             cout << "Opțiune neimplementată. Vă rugăm să alegeți din nou.\n";
         }
     }

     return 0;
 }