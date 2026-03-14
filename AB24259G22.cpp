/*
Autors: Arnolds Bērziņš ab24259
Veidots: 14/3/2026


Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas (piemēram, elementu pievienošanai), kā arī pēc tā izmantošanas korekti jāatbrīvo izdalītā atmiņa.

G2. Uzrakstīt funkciju, kas salīdzina, vai divi saraksti ir vienādi.
**/
//2) uzdevums
#include <iostream>
#include <list>
using namespace std;
/**
bool vienadi(list<int> a,list<int>b);
Funkcija vienadi(a,b) -
atgriež true, ja divi STL  saraksti ir vienādi, savādāk atgriež false.
**/
bool vienadi(list<int> a, list<int> b){

    if(a.size() != b.size()) return false;

    auto it1 = a.begin();
    auto it2 = b.begin();

    while(it1 != a.end()){
        if(*it1 != *it2) return false;
        ++it1;
        ++it2;
    }
    return true;
}
int main(){
    int ok = 1;
    do {
       list<int> a;
       list<int> b;
       int x;

       /// pirmais saraksts
       cout << "Ievadiet pirmo sarakstu! (0, lai beigtu ievadīt)" << endl;
       cin >> x;
       while(x != 0){
           a.push_back(x);
           cin >> x;
       }

       /// otrais saraksts
       cout << "Ievadiet otro sarakstu! (0, lai beigtu ievadīt)" << endl;
       cin >> x;
       while(x != 0){
           b.push_back(x);
           cin >> x;
       }

       if(vienadi(a,b))
           cout << "Vienadi" << endl;
       else
           cout << "Nav vienadi" << endl;
       cout << "Vai turpināt(1) vai beigt(0)?" << endl;
       cin >> ok;
    }while(ok==1);
}
/**
                                             Testa Plāns
            Ievade(1. saraksts)                Ievade (2. saraksts)                 Paredzētais rezultāts             Rezultāts
            1 2 3 0                            1 2 3 0                              Vienādi                               +
            1 2 4 0                            1 2 3 0                              Nav vienādi                           +
            1 0                                1 2 0                                Nav vienādi                           +
            0                                  0                                    Vienādi                               +


**/
