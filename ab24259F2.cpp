/*Autors: Arnolds Bērziņš
Veidots: 18/02/2026


Uzdevums:
F2. Doti divi teksta faili. Uzrakstīt programmu, kura izveido trešo failu sekojoši:
katras pirmā faila rindiņas galā ir pierakstīta atbilstoša otrā faila rindiņa.
(Ja ieejas failos rindiņu skaits ir atšķirīgs, tad pēdējās rindiņas trešajā failā ir tādas pašas kā failā ar lielāko rindiņu skaitu).

Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā, cita starpā parādot
gan sākotnējās, gan rezultējošās vērtības. Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas (piemēram, elementu
pievienošanai), kā arī pēc tā izmantošanas korekti jāatbrīvo izdalītā atmiņa
*/
//1. programma ( 1) nosacījums)
#include <iostream>
#include <fstream>
using namespace std;
struct elem{
    string rin;
    elem *next;
};

int main(){
    elem* first = NULL, *last=NULL, *p;
    fstream fin ("F21.txt", ios::in);
    fstream fin2("F22.txt", ios::in);
    if (!fin || !fin2) {   //pārbaude
        cout << "Nevar atvērt failus!" << endl;
        return 0;
    }
    string line1, line2;
    getline(fin, line1);  //lai varētu incializēt ciklu ar sākotnējām vērtībām
    getline(fin2, line2);


    while (fin || fin2) {
        string rinda3;
        //Lai turpinātu lasīt, kad viens fails ir garāks par otru.
        if (fin && fin2) rinda3 = line1+line2;
        else if (fin) rinda3 = line1;
        else if (fin2) rinda3 = line2;
        p = new elem;
        p->rin = rinda3;
        p->next=NULL;
        if (first==NULL) first = last = p; //Ja saraksts tukšs
        else{
            last->next = p;         // Ja saraksts nav tukšs
            last = last->next;
        }
        getline(fin, line1); // Iegūst nākamo rindu nākamai cikla iterācijai.
        getline(fin2, line2);
    }
    fin.close();
    fin2.close();
    fstream fout("fails3.txt", ios::out); //trešā faila izveide
    for (p=first; p!=NULL; p=p->next) { //trešā faila rakstīšana
        fout << p->rin << endl;
    }
    fout.close();
    //atmiņas atbrīvošana
    p = first;
    while (p!=NULL) {
        first = first->next;
        delete p;
        p = first;
    }
}
/**
                                             Testa Plāns
            Teksta Fails 1 || Teksta Fails 2 ||  Paradzemais rezultāts Teksta failā 3 || Rezultāts
            --------------------------------------------------------------------------------------
            Arn            || Olds           ||  Arnolds                              ||
            Ber            || Zins           ||  Zins                                 ||  +
            --------------------------------------------------------------------------------------
            Arn            || Olds           ||  ArnOlds                              ||
                           || Ber            ||  Ber                                  ||  +
                           || Zin            ||  Zin                                  ||
            --------------------------------------------------------------------------------------
            Arn            || Ber            || ArnBer                                ||
            ber            ||                || ber                                   ||  +
            zin            ||                || zin                                   ||
            old            ||                || old                                   ||
            --------------------------------------------------------------------------------------
            neeksistē      || neeksistē      || "Nevar atvērt failus!" (konsolē)      || +
**/
