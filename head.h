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
void skaityti_is_failo(string eilute, studentas& stud);
std::vector<std::string> split(std::string strToSplit, char delimeter);
