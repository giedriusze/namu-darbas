#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "head.h"

using namespace std;


int main ()
{
    vector<studentas> stud;
    
    ofstream failas_teig;
    ofstream failas_neig;
    failas_teig.open("geri.txt");
    failas_neig.open("blogi.txt");
    
    failas_neig << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_neig << "-----------------------------------------------------------------" << endl;
    failas_teig << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_teig << "-----------------------------------------------------------------" << endl;
    
    
    ifstream pradinis_failas;
    pradinis_failas.open ("studentai.txt");
    int n = 0;
    string eilute;
    pradinis_failas >> eilute;
    while (pradinis_failas >> eilute)
    {
        skaityti_is_failo(eilute, stud[n]);
        if(ar_gera_grupe(stud[n]))
        {
            uzpildyti_eilute(stud[n], failas_teig);
        }
        else
        {
            uzpildyti_eilute(stud[n], failas_neig);
        }
        n++;
    }
    pradinis_failas.close();
    
    int kiekis = 0;
    cout << "Kiek duomenu generuoti ";
    try {
        cin >> kiekis;
    } catch(int e) {
        cout << "Klaida " << e << endl;
    }
    
    auto pradzios_laikas = chrono::steady_clock::now();
    

    for(int i = 0; i < kiekis; i++)
    {
        
        stud.push_back(gauti_studenta(i));
        skaiciuoti_galutini(stud[i]);
        if(ar_gera_grupe(stud[i]))
        {
            uzpildyti_eilute(stud[i], failas_teig);
        }
        else
        {
            uzpildyti_eilute(stud[i], failas_neig);
        }
    }
    failas_neig.close();
    failas_teig.close();
    
    auto pabaigos_laikas = chrono::steady_clock::now();
    auto laiko_skirtumas = pabaigos_laikas - pradzios_laikas;
    cout  << "Uztruko " << chrono::duration <double, milli> (laiko_skirtumas).count() << " milisekundziu" << endl;
    return 0;
}

void uzpildyti_eilute(studentas stud, ofstream& file)
{
    file << left << setw(15) << stud.vardas << setw(15) << stud.pavarde << right << setw(5) << stud.galutinis << endl;
}

studentas gauti_studenta(int i)
{
    studentas stud;
    stud.nd_vidurkis = 0;
    stud.vardas = "Vardas-" + to_string(i);
    stud.pavarde = "Pavarde-" + to_string(i);
    for(int i = 0; i < 5; i++)
    {
        int ran = rand() % 10 + 1;
        stud.nd_vidurkis += ran;
    }
    stud.egz = rand() % 10 + 1;
    stud.nd_vidurkis = stud.nd_vidurkis / 5;
    return stud;
}

bool ar_gera_grupe(studentas stud)
{
    return stud.galutinis >= 5;
}

void skaiciuoti_galutini(studentas& stud)
{
    stud.galutinis = stud.nd_vidurkis * 0.4 + stud.egz * 0.6;
}

void skaityti_is_failo(string eilute, studentas& stud)
{
    std::vector<std::string> data;
    
    data = split(eilute, ';');
    
    stud.vardas = data[0];
    stud.pavarde = data[1];
    stud.nd_vidurkis = stoi(data[2]);
    stud.egz = stoi(data[3]);
}

std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}
