#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

vector<string> read_grammar(string gramatica_fisier) {
    vector<string> gramatica;
    ifstream infile(gramatica_fisier);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            gramatica.push_back(line);
        }
        infile.close();
    }
    return gramatica;
}

bool verificaCuvant(vector<string>gramatica , char simbol, string cuvant) {
     if(cuvant.size()==0) //se verifica daca cuvantul null apartine gramaticii
     {
         for (auto regula:gramatica )
                {


            if(regula[0]==simbol && regula.substr(3)=="lambda"){
            return true;}
         }
           return false;
     }

     if(cuvant.size()==1) //in cazul cuvantul are doar un caracter, se verifica daca acesta poate fi produs de gramatica
     {
         for (auto regula:gramatica)
                {


            if(regula[0]==simbol && regula[3]==cuvant[0]){
            return true;}
         }
         return false;
     }
     // In cazul in care cuvantul are o lungime>1,se verifica daca exista reguli care pot forma cuvantul recursiv
      for (auto regula:gramatica)
      {
          if(regula[0] == simbol && regula[3] == cuvant[0])
              {
                  if (verificaCuvant(gramatica, regula[4], cuvant.substr(1))) {
                return true;
            }

          }

      }
          return false;


}



int main() {
 string gramatica_fisier;
    cout << "Fisier gramatica : ";
    cin >> gramatica_fisier;
    vector<string> gramatica = read_grammar(gramatica_fisier);

    char simbol = 'S';
    string cuvinte_fisier;
    cout << "Cuvinte : ";
    cin >> cuvinte_fisier;

    ifstream infile(cuvinte_fisier);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            string cuvant = line;
            if (verificaCuvant(gramatica, simbol, cuvant)) {
                cout << "Cuvantul " << cuvant << " este acceptat." << endl;
            } else {
                cout << "Cuvantul " << cuvant << " nu este acceptat." << endl;
            }
        }
        infile.close();
    }

    return 0;
}



