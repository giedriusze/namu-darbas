#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>

using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    int egz;
    double galutinis;
    double nd_vidurkis;
};

studentas gauti_studenta(int i);
void skaiciuoti_galutini(studentas& stud);
bool ar_gera_grupe(studentas stud);
void uzpildyti_eilute(studentas stud, ofstream& file);

int main ()
{
    deque<studentas> stud_deque;
    vector<studentas> stud_vector;
    list<studentas> stud_list;
    
    int kiekis = 0;
    cout << "Kiek duomenu generuoti ";
    try {
        cin >> kiekis;
    } catch(int e) {
        cout << "Klaida " << e << endl;
    }
    
    ofstream failas_teig;
    ofstream failas_neig;
    failas_teig.open("geri.txt");
    failas_neig.open("blogi.txt");
    
    failas_neig << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_neig << "-----------------------------------------------------------------" << endl;
    failas_teig << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_teig << "-----------------------------------------------------------------" << endl;
    
    // ----- deque ----
    auto pradzios_laikas_deque = chrono::steady_clock::now();
    for(int i = 0; i < kiekis; i++)
    {
        stud_deque.push_back(gauti_studenta(i));
        skaiciuoti_galutini(stud_deque[i]);
        if(ar_gera_grupe(stud_deque[i]))
        {
            uzpildyti_eilute(stud_deque[i], failas_teig);
        }
        else
        {
            uzpildyti_eilute(stud_deque[i], failas_neig);
        }
    }
    auto laiko_skirtumas_deque = chrono::steady_clock::now() - pradzios_laikas_deque;
    
    // ----- vector ----
    auto pradzios_laikas_vector = chrono::steady_clock::now();
    for(int i = 0; i < kiekis; i++)
    {
        stud_vector.push_back(gauti_studenta(i));
        skaiciuoti_galutini(stud_vector[i]);
        if(ar_gera_grupe(stud_vector[i]))
        {
            uzpildyti_eilute(stud_vector[i], failas_teig);
        }
        else
        {
            uzpildyti_eilute(stud_vector[i], failas_neig);
        }
    }
    auto laiko_skirtumas_vector = chrono::steady_clock::now() - pradzios_laikas_vector;
    
    // ----- list ----
    auto pradzios_laikas_list = chrono::steady_clock::now();
    for(int i = 0; i < kiekis; i++)
    {
        studentas std = gauti_studenta(i);
        stud_list.push_back(std);
        skaiciuoti_galutini(std);
        if(ar_gera_grupe(std))
        {
            uzpildyti_eilute(std, failas_teig);
        }
        else
        {
            uzpildyti_eilute(std, failas_neig);
        }
    }
    auto laiko_skirtumas_list = chrono::steady_clock::now() - pradzios_laikas_list;
    
    
    failas_neig.close();
    failas_teig.close();
    
    cout  << "deque uztruko " << chrono::duration <double, milli> (laiko_skirtumas_deque).count() << " milisekundziu" << endl;
    cout  << "vector uztruko " << chrono::duration <double, milli> (laiko_skirtumas_vector).count() << " milisekundziu" << endl;
    cout  << "list uztruko " << chrono::duration <double, milli> (laiko_skirtumas_list).count() << " milisekundziu" << endl;
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
