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
// 1) uzdevums
#include <iostream>
using namespace std;

struct elem{
    int num;
    elem *next;
};
/**
bool vienadi(elem *a, elem *b);
Funkcija vienadi(a,b) -
atgriež true, ja divi vienvirziena saraksti ir vienādi, savādāk atgriež false.
**/

bool vienadi(elem *a, elem *b){
    while(a != NULL && b != NULL){
        if(a->num != b->num) return false;
        a = a->next;
        b = b->next;
    }
    if(a == NULL && b == NULL) return true;
    else return false;
}
int main(){
    int ok = 1;
    do {
        elem *first1=NULL, *last1=NULL, *p;
        elem *first2=NULL, *last2=NULL;
        int i;

    /// 1. saraksts
        cout << "Ievadiet pirmo sarakstu! (0, lai beigtu ievadīt)" << endl;
        cin >> i;
        while(i != 0){
           p = new elem;
           p->num = i;
           p->next = NULL;

           if(first1 == NULL) first1 = last1 = p;
           else{
               last1->next = p;
               last1 = p;
           }
           cin >> i;
       }
       /// 2. saraksts
       cout << "Ievadiet otro sarakstu! (0, lai beigtu ievadīt)" << endl;
       cin >> i;
       while(i != 0){
           p = new elem;
           p->num = i;
           p->next = NULL;

           if(first2 == NULL) first2 = last2 = p;
           else{
               last2->next = p;
               last2 = p;
           }
           cin >> i;
       }
       if(vienadi(first1, first2)) cout << "Vienādi" << endl;
       else cout << "Nav vienādi" << endl;
       /// atbrīvo atmiņu
       while(first1 != NULL){
           p = first1;
           first1 = first1->next;
           delete p;
       }
       while(first2 != NULL){
           p = first2;
           first2 = first2->next;
           delete p;
       }
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
