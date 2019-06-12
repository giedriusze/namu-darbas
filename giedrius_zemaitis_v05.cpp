#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
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
    deque<studentas> stud;

    
    int kiekis = 0;
    cout << "Kiek duomenu generuoti ";
    try {
        cin >> kiekis;
    } catch(int e) {
        cout << "Klaida " << e << endl;
    }
    
    auto pradzios_laikas = chrono::steady_clock::now();
    
    ofstream failas_teig;
    ofstream failas_neig;
    failas_teig.open("geri.txt");
    failas_neig.open("blogi.txt");
    
    failas_neig << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_neig << "-----------------------------------------------------------------" << endl;
    failas_teig << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_teig << "-----------------------------------------------------------------" << endl;
    
    
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
