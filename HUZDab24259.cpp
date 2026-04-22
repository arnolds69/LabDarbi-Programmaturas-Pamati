/**
Izveidot programmu valodā C++.  Ar faila komponenti tiek saprasts fiksēta garuma ieraksts.
Sīkākas prasības sk. Laboratorijas darbu noteikumos.

H2. Dots teksta fails. Saskaitīt tekstā vārdus pēc to garumiem (1-burtīgie, 2-burtīgie utt.).
Programmai statistika pa vārdu garumiem jāsaliek tabulā, kas realizēta kā vārdnīca (STL map).
Programmas rezultātā iegūt failu, kas sastāv no skaitļu pārīšiem, kurā katram vārdu garumam
dots vārdu skaits (piemēram, 1 110, 2 406, 3 632 utt.). Par vārdiem tiek uzskatītas simbolu
virknes, kas atdalītas ar tukšumiem un pieturzīmēm.
**/
//Arnolds Bērziņš ab24259
//Veidots 4/22/2026


#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin)
    {
        cout << "Nevar atvērt teksta failu!" << endl;
        return 1;
    }
    map<int, int> stlmap;

    char c;
    int VardaGarums = 0;

    while (fin.get(c))
    {
        //ja nav atstarpe vai pieurzime
        if (c != ' ' && c != ',' && c != '?' && c != '.' && c != ';' && c != ':' && c != '-' && c!= '\n')
        {
            VardaGarums++;
        }
        else
        {
            if (VardaGarums > 0)
            {
                stlmap[VardaGarums]++;
                VardaGarums = 0;
            }
        }
    }
    // Ja pēdejais simbols ir burts, cikls beidzās un else{}, kas ievada STL map vērtības, neizpildās.
    if (VardaGarums > 0)
    {
        stlmap[VardaGarums]++;
    }
    for (auto it = stlmap.begin(); it != stlmap.end(); ++it)
    {
        fout << it->first << " " << it->second << "," << " ";
    }
    fin.close();
    fout.close();

    return 0;
}



/**
                          Testa plāns
        Input file     |     Output file     |     rezultāts
        aaa, a52; a:   |   1 1, 2 1, 3 2, 5 1|        +
        l2156.33,      |                     |
 -----------------------------------------------------------
        a a a a a a a  |   1 21,             |      +
        b b b b b b b  |                     |
        1 1 1 1 1 1 1  |                     |
**/
