#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Pets {
private:
    static int contorId;
    const int idPet;
    char* numePet;
    string tipPet;
    char rasa;
    int nrLuni;
    float* petsAdoptateNLuni;
    int adoptat;
    bool eDeRasa;
    int nrAnimale;

public:
    //Constructori
    Pets();  // Constructor fara parametrii
    Pets(char* numePet, string tipPet, char rasa, int nrLuni,
        float* petsAdoptateNLuni, bool eDeRasa,int nrAnimale); // Constructor parametrizat
    Pets(const Pets& obj);   // Copy constructor

    //Operator
    Pets& operator = (const Pets&);
    friend ostream& operator <<(ostream& out, const Pets& obj);
    friend istream& operator >>(istream& in, Pets& obj);
    Pets& operator++();
    Pets operator++(int);
    Pets operator+(const Pets& obj);
    Pets operator+(int);
    friend Pets operator+(int, Pets obj);
    bool operator==(const Pets&);
    float operator[](int);
    operator int();
    operator int() const {return this->nrAnimale;}


    //Metode
    //void afisare();
    //void citire();

    //Get+Set


    void settipPet(string tipPet){this->tipPet = tipPet;}
    void setNrLuni(int nrLuni){this->nrLuni =nrLuni;}
    void setrasa(char rasa){this->rasa = rasa;}
    void setnumePet(char* numePet);
    void setnrAnimale(int nrAnimale) {this->nrAnimale= nrAnimale;}
    void setPetsAdoptateNLuni(float* PetsAdoptate);
    void seteDeRasa(bool eDeRasa) {this->eDeRasa=eDeRasa;}

    static int getContorId() {return Pets::contorId;}
    string gettipPet() {return tipPet;}
    int getNrLuni() {return nrLuni;}
    char getrasa(){return rasa;}
    char* getnumePet(){return numePet;}
    const float* getPetsAdoptateNLuni() const {this->petsAdoptateNLuni;}
    int getnrAnimale(){return nrAnimale;}
    bool geteDeRasa(){return eDeRasa;}
    int animaleAdoptate();

    //Destructor
    ~Pets();

};
void Pets::setPetsAdoptateNLuni(float* petsAdoptateNLuni){
    if(this->petsAdoptateNLuni != NULL){
        delete[] this->petsAdoptateNLuni;
        this->petsAdoptateNLuni = NULL;
    }
    this->petsAdoptateNLuni= new float[this->nrLuni];
    for(int i = 0 ; i < this->nrLuni ; i++)
        this->petsAdoptateNLuni[i] = petsAdoptateNLuni[i];

}

void Pets::setnumePet(char* numePet){//setter
    if(this->numePet != NULL){
        delete[] this->numePet;
        this->numePet= NULL;
    }
    this->numePet = new char[strlen(numePet)+1];
    strcpy(this->numePet , numePet);

}

int Pets::animaleAdoptate(){
    int suma = 0;
    for(int i = 0 ; i < this->nrLuni ; i++){
        suma = suma + this->petsAdoptateNLuni[i]; //fucntie care calculeaza nr de animale adoptate in total in n luni.
    }
    return suma;
}



int Pets::contorId = 1000;

Pets::Pets():idPet(contorId++) {
    numePet = new char[strlen("Anonim") + 1]; // Alocat memorie fara sa initializam
    strcpy(numePet, "Anonim");  // Initializam variabila
    tipPet = "Anonim";
    rasa = '-';
    nrLuni = 0;
    petsAdoptateNLuni = NULL;
    eDeRasa = false;
}

Pets::Pets(char* numePet, string tipPet, char rasa, int nrLuni,
float* petsAdoptateNLuni, bool eDeRasa,int nrAnimale): idPet(contorId++){
    this->numePet = new char[strlen(numePet) + 1];
    strcpy(this->numePet, numePet);
    this->tipPet = tipPet;
    this->rasa = rasa;
    this->nrLuni = nrLuni;
    this->petsAdoptateNLuni = petsAdoptateNLuni;
    this->eDeRasa = eDeRasa;
    this->nrAnimale=nrAnimale;
}

Pets::Pets(const Pets& obj): idPet(contorId++){
    this->numePet = new char[strlen(obj.numePet) + 1];
    strcpy(this->numePet, obj.numePet);
    this->tipPet = obj.tipPet;
    this->rasa = obj.rasa;
    this->nrLuni = obj.nrLuni;
    this->petsAdoptateNLuni = new float[obj.nrLuni];
    for(int i = 0; i < obj.nrLuni; i++)
        this->petsAdoptateNLuni[i] = obj.petsAdoptateNLuni[i];  // Pentru a avea o zona de memorie diferita
    this->eDeRasa = obj.eDeRasa;
    this->nrAnimale=obj.nrAnimale;
}

Pets& Pets::operator = (const Pets& obj){
    if(this != &obj){
        if(this->numePet != NULL){
        delete[] this->numePet;
        this->numePet = NULL;
        }

        if(this->petsAdoptateNLuni != NULL){
            delete[] this->petsAdoptateNLuni;
            petsAdoptateNLuni = NULL;
        }

        this->numePet = new char[strlen(obj.numePet) + 1];
        strcpy(this->numePet, obj.numePet);
        this->tipPet = obj.tipPet;
        this->rasa = obj.rasa;
        this->nrLuni = obj.nrLuni;
        this->petsAdoptateNLuni = new float[obj.nrLuni];
        for(int i = 0; i < obj.nrLuni; i++)
            this->petsAdoptateNLuni[i] = obj.petsAdoptateNLuni[i];  // Pentru a avea o zona de memorie diferita
        this->eDeRasa = obj.eDeRasa;
        this->nrAnimale=obj.nrAnimale;

    }
    return *this;
}
Pets& Pets::operator++(){
    this->nrAnimale++;
    return *this;
}

Pets Pets::operator++(int){
    Pets aux(*this);
    ///this->nrAnimale++;
    ++*this;
    return aux;
}

Pets Pets::operator+(const Pets& obj){
    Pets aux(*this);
    aux.tipPet += obj.tipPet;
    aux.nrAnimale += obj.nrAnimale;
    return aux;
}



Pets Pets::operator+(int x){
    Pets aux(*this);
    aux.nrAnimale += x;
    return aux;
}

Pets operator+(int x, Pets obj){
    return obj+x;
}

bool Pets::operator==(const Pets& obj){
    return this->tipPet == obj.tipPet;
}

float Pets::operator[](int i){
    if(this-> petsAdoptateNLuni == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > this->nrLuni){
        throw runtime_error("Index invalid");
    }
    else
        return this-> petsAdoptateNLuni[i];
}

Pets::operator int(){
    return this->nrAnimale;
}



ostream& operator <<(ostream& out, const Pets& obj){
    out << "ID: " << obj.idPet << endl;
    out << "Nume animal: " << obj.numePet << endl;
    out << "Tip animal: " << obj.tipPet << endl;
    out << "Rasa animalului: " << obj.rasa << endl;
    out << "Nr luni: " << obj.nrLuni << endl;
    out << "Cate animale au fost adoptate in n luni: ";
    for(int i = 0; i < obj.nrLuni; i++)
        out << obj.petsAdoptateNLuni[i] << " ";
    out << endl;
    out << "Este de rasa: " << obj.eDeRasa << endl;
    out << "Nr animale: " << obj.nrAnimale << endl;

    return out;
}

istream& operator >>(istream& in, Pets& obj){
    cout << "Introduceti numele animalului: " << endl;
    char numePet[100];
    in >> numePet;
    if(obj.numePet != NULL){
        delete obj.numePet;
        obj.numePet = NULL;
    }
    obj.numePet = new char[strlen(numePet) + 1];
    strcpy(obj.numePet, numePet);

    cout << "Introduceti tipul animalului: " << endl;
    in >> obj.tipPet;

    cout << "Introduceti rasa animalului: " << endl;
    in >> obj.rasa;

    cout << "Introduceti nr luni: " << endl;
    in >> obj.nrLuni;

    cout << "Introduceti cate animale au fost adoptate in n luni: " << endl;
    if(obj.petsAdoptateNLuni != NULL){
        delete[] obj.petsAdoptateNLuni;
        obj.petsAdoptateNLuni = NULL;
    }

    obj.petsAdoptateNLuni = new float[obj.nrLuni];
    for(int i = 0; i < obj.nrLuni; i++)
        in >> obj.petsAdoptateNLuni[i];

    cout << "Este un animal de rasa?: " << endl;
    in >> obj.eDeRasa;
    return in;
}

Pets::~Pets(){
    if(this->numePet != NULL){
        delete[] this->numePet;
        this->numePet = NULL;
    }

    if(this->petsAdoptateNLuni != NULL){
        delete[] this->petsAdoptateNLuni;
        petsAdoptateNLuni = NULL;
    }
}

class Locatii {
private:
    static int contorId;
    const int idLoc;
    char* numeLoc;
    string oras;
    int nrr;
    int* nrLocOras;
    int resp;
    bool prgWk;
    int nrOras;
public:
    //Constructori
    Locatii();  // Constructor fara parametrii
    Locatii(char* numeLoc, string oras, int nrr,int* nrLocOras,int resp,bool prgWk,int nrOras); // Constructor parametrizat
    Locatii(const Locatii& obj);   // Copy constructor

    //Operator
    Locatii& operator = (const Locatii&);
    friend ostream& operator <<(ostream& out, const Locatii& obj);
    friend istream& operator >>(istream& in, Locatii& obj);
    Locatii& operator++();
    Locatii operator++(int);
    Locatii operator+(const Locatii& obj);
    Locatii operator+(int);
    friend Locatii operator+(int, Locatii obj);
    bool operator==(const Locatii&);
    char operator[](int);
    operator int();
    operator int() const {return this->nrOras;}





    //Metode
    //void afisare();
    //void citire();

    //Get+Set

    void setoras(string oras){this->oras= oras;}
    void setnrLocOras(int* nrLocOras);
    void setnumeLoc(char* numeLoc);
    void setnrr(int nrr){this->nrr=nrr;}
    void setnrOras(int nrOras) {this->nrOras= nrOras;}
    void setresp(int resp) {this->resp=resp;}


    static int getContorId() {return Locatii::contorId;}
    string getoras() {return oras;}
    int* getnrLocOras() {return nrLocOras;}
    char* getnumeLoc(){return numeLoc;}
    int getnrr() {return nrr;}
    int getnrOras(){return nrOras;}
    int getresp(){return resp;}
    int locTotal();


    //Destructor
    ~Locatii();

};

void Locatii::setnumeLoc(char* numeLoc){//setter
    if(this->numeLoc != NULL){
        delete[] this->numeLoc;
        this->numeLoc = NULL;
    }
    this->numeLoc = new char[strlen(numeLoc)+1];
    strcpy(this->numeLoc , numeLoc);

}
void Locatii::setnrLocOras(int* nrLocOras){
    if(this-> nrLocOras!= NULL){
        delete[] this->nrLocOras;
        this->nrLocOras= NULL;
    }
    this->nrLocOras= new int[this->nrr];
    for(int i = 0 ; i < this->nrr; i++)
        this->nrLocOras[i] = nrLocOras[i];

}


 int Locatii::locTotal(){

     int total = 0;
    for(int j=0;j< this->nrr;j++)
          {
              total= total + this->nrLocOras[j];
    }
                                                   //functie care calculeaza nr total de magazine din tara.

    return total;
}

int Locatii::contorId = 150;

Locatii::Locatii():idLoc(contorId++) {
    numeLoc = new char[strlen("Anonim") + 1]; // Alocat memorie fara sa initializam
    strcpy(numeLoc, "Anonim");  // Initializam variabila
    oras = "Anonim";
    nrr=0;
    nrLocOras = NULL;
    resp=0;
    prgWk = false;
}

Locatii::Locatii(char* numeLoc, string oras, int nrr, int* nrLocOras ,int resp,bool prgWk,int nrOras): idLoc(contorId++){
    this->numeLoc = new char[strlen(numeLoc) + 1];
    strcpy(this->numeLoc, numeLoc);
    this->oras = oras;
    this->nrr=nrr;
    this->nrLocOras = nrLocOras;
    this->resp=resp;
    this->prgWk = prgWk;
    this->nrOras = nrOras;
}

Locatii::Locatii(const Locatii& obj): idLoc(contorId++){
    this->numeLoc = new char[strlen(obj.numeLoc) + 1];
    strcpy(this->numeLoc, obj.numeLoc);
    this->oras = obj.oras;
    this->nrr=obj.nrr;
     this->nrLocOras = new int[obj.nrr];
    for(int i = 0; i < obj.nrr; i++)
        this->nrLocOras[i] = obj.nrLocOras[i];
    this->resp= obj.resp;
    this->prgWk = obj.prgWk;
    this->nrOras = obj.nrOras;
}

Locatii& Locatii::operator = (const Locatii& obj){
    if(this != &obj){
        if(this->numeLoc != NULL){
        delete[] this->numeLoc;
        this->numeLoc = NULL;
        }
     if(this->nrLocOras != NULL){
            delete[] this->nrLocOras;
            nrLocOras= NULL;
        }
        this->numeLoc = new char[strlen(obj.numeLoc) + 1];
        strcpy(this->numeLoc, obj.numeLoc);
        this->oras = obj.oras;
        this->nrr= obj.nrr;
        this->nrLocOras = new int[obj.nrr];
        for(int i = 0; i < obj.nrr; i++)
            this->nrLocOras[i] = obj.nrLocOras[i];
        this->resp= obj.resp;
        this->prgWk = obj.prgWk;
        this->nrOras = nrOras;
    }
    return *this;
}

Locatii& Locatii::operator++(){
    this->nrOras++;
    return *this;
}

Locatii Locatii::operator++(int){
    Locatii aux(*this);
    ///this->nrOras++;
    ++*this;
    return aux;
}

Locatii Locatii::operator+(const Locatii& obj){
    Locatii aux(*this);
    aux.oras += obj.oras;
    aux.nrOras += obj.nrOras;
    return aux;
}

Locatii Locatii::operator+(int x){
    Locatii aux(*this);
    aux.nrOras += x;
    return aux;
}

Locatii operator+(int x, Locatii obj){
    return obj+x;
}

bool Locatii::operator==(const Locatii& obj){
    return this->oras == obj.oras;
}

char Locatii::operator[](int i){
    if(this->numeLoc == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > this->nrr){
        throw runtime_error("Index invalid");
    }
    else
        return this->numeLoc[i];
}

Locatii::operator int(){
    return this->nrOras;
}


ostream& operator <<(ostream& out, const Locatii& obj){
    out << "ID: " << obj.idLoc << endl;
    out << "Nume locatie: " << obj.numeLoc << endl;
    out << "Oras: " << obj.oras << endl;
    out << "Nr de magazine in orasul respectiv: ";
    out << obj.resp<< " "<<"magazine in"<<" "<<obj.oras<<endl;
    out << "Au program in weekend? " << obj.prgWk << endl;
    out<<"Cate orase din tara au astfel de petshop-uri:"<< obj.nrOras<<endl;
    return out;
}

istream& operator >>(istream& in, Locatii& obj){
    cout << "Introduceti numele petshop-ului: " << endl;
    char numeLoc[100];
    in >> numeLoc;
    if(obj.numeLoc != NULL){
        delete obj.numeLoc;
        obj.numeLoc = NULL;
    }
    obj.numeLoc = new char[strlen(numeLoc) + 1];
    strcpy(obj.numeLoc, numeLoc);

    cout << "Introduceti orasul: " << endl;
    in >> obj.oras;

    cout << "Introduceti nr de magazine din orasul respectiv: " << endl;
        in >> obj.resp;



    cout << "Introduceti daca petshop-urile au program in weekend: " << endl;
    in >> obj.prgWk;
    return in;
}

Locatii::~Locatii(){
    if(this->numeLoc != NULL){
        delete[] this->numeLoc;
        this->numeLoc = NULL;
    }

}



class Angajati {
private:
    static int contorId;
    const int idAngajat;
    char* numeAngajat;
    string functie;
    int ore;
    int* oreMunca;
    int prog;
    bool feedbackAng;
    int nrAngajati;

public:
    //Constructori
    Angajati();  // Constructor fara parametrii
    Angajati(char* numeAngajat, string functie,int ore,int* oreMunca,int prog,bool feedbackAng,int nrAngajati); // Constructor parametrizat
    Angajati(const Angajati& obj);   // Copy constructor

    //Operator
    Angajati& operator = (const Angajati&);
    friend ostream& operator <<(ostream& out, const Angajati& obj);
    friend istream& operator >>(istream& in, Angajati& obj);
    Angajati& operator++();
    Angajati operator++(int);
    Angajati operator+(const Angajati& obj);
    Angajati operator+(int);
    friend Angajati operator+(int, Angajati obj);
    bool operator==(const Angajati&);
    char operator[](int);
    operator int();
    operator int() const {return this->nrAngajati;}


    //Metode
    //void afisare();
    //void citire();

    //Get+Set

    void setfunctie(string functie){this->functie= functie;}


    static int getContorId() {return Angajati::contorId;}
    string getfunctie() {return functie;}
    //int* oreMunca() {return oreMunca;}



    int totalore();


    //Destructor
    ~Angajati();

};

int Angajati::totalore(){

    int totall=0;
    for(int i=0;i<this->ore;i++)
          {totall=totall+this->oreMunca[i]; // functie care calculeaza numarul de ore totale pe care le au muncit angajatii.
          }
    return totall;
}




int Angajati::contorId = 150;

Angajati::Angajati():idAngajat(contorId++) {
    numeAngajat = new char[strlen("Anonim") + 1]; // Alocat memorie fara sa initializam
    strcpy(numeAngajat, "Anonim");  // Initializam variabila
    functie = "Anonim";
    ore=0;
    oreMunca =NULL;
    prog=0;
    feedbackAng = false;
}

Angajati::Angajati(char* numeAngajat, string functie,int ore, int* oreMunca,int prog, bool feedbackAng,int nrAngajati): idAngajat(contorId++){
    this->numeAngajat = new char[strlen(numeAngajat) + 1];
    strcpy(this->numeAngajat, numeAngajat);
    this->functie = functie;
    this->ore=ore;
    this->oreMunca = oreMunca;
    this->prog= prog;
    this->feedbackAng = feedbackAng;
    this->nrAngajati = nrAngajati;
}

Angajati::Angajati(const Angajati& obj): idAngajat(contorId++){
    this->numeAngajat = new char[strlen(obj.numeAngajat) + 1];
    strcpy(this->numeAngajat, obj.numeAngajat);
    this->functie = obj.functie;
    this->ore= obj.ore;
    this->oreMunca = new int[obj.ore];
    for(int i = 0; i < obj.ore; i++)
        this->oreMunca[i] = obj.oreMunca[i];
    this->prog= prog;
    this->feedbackAng = obj.feedbackAng;
    this->nrAngajati = obj.nrAngajati;
}

Angajati& Angajati::operator = (const Angajati& obj){
    if(this != &obj){
        if(this->numeAngajat != NULL){
        delete[] this->numeAngajat;
        this->numeAngajat = NULL;
        }
         if(this->oreMunca != NULL){
            delete[] this->oreMunca;
            oreMunca= NULL;
        }

        this->numeAngajat = new char[strlen(obj.numeAngajat) + 1];
        strcpy(this->numeAngajat, obj.numeAngajat);
        this->functie = obj.functie;
        this->ore = obj.ore;
        this->oreMunca = new int[obj.ore];
    for(int i = 0; i < obj.ore; i++)
        this->oreMunca[i] = obj.oreMunca[i];
        this->prog= prog;
        this->feedbackAng = obj.feedbackAng;
        this->nrAngajati = obj.nrAngajati;
}

    return *this;
}

Angajati& Angajati::operator++(){
    this->nrAngajati++;
    return *this;
}

Angajati Angajati::operator++(int){
    Angajati aux(*this);
    ///this->nrAngajati++;
    ++*this;
    return aux;
}

Angajati Angajati::operator+(const Angajati& obj){
    Angajati aux(*this);
    aux.ore += obj.ore;
    aux.nrAngajati += obj.nrAngajati;
    return aux;
}

Angajati Angajati::operator+(int x){
    Angajati aux(*this);
    aux.nrAngajati += x;
    return aux;
}

Angajati operator+(int x, Angajati obj){
    return obj+x;
}

bool Angajati::operator==(const Angajati& obj){
    return this->oreMunca == obj.oreMunca;
}

char Angajati::operator[](int i){
    if(this->numeAngajat == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > this->nrAngajati){
        throw runtime_error("Index invalid");
    }
    else
        return this-> numeAngajat[i];
}

Angajati::operator int(){
    return this->nrAngajati;
}



ostream& operator <<(ostream& out, const Angajati& obj){
    out << "ID: " << obj.idAngajat << endl;
    out << "Nume angajat: " << obj.numeAngajat << endl;
    out << "Functie angajat : " << obj.functie << endl;
    out << "Ore de lucru/zi pentru angajat: " << obj.prog <<" "<<"h/zi"<<endl;
    out << "Feedback pozitiv din partea angajatului: " << obj.feedbackAng << endl;
    out<<"Numarul total al angajatilor este:"<< obj.nrAngajati<<endl;
    return out;
}

istream& operator >>(istream& in, Angajati& obj){
    cout << "Introduceti numele angajatului: " << endl;
   char numeAngajat[100];
    in >> numeAngajat;
    if(obj.numeAngajat != NULL){
        delete obj.numeAngajat;
        obj.numeAngajat = NULL;
    }
    obj.numeAngajat = new char[strlen(numeAngajat) + 1];
    strcpy(obj.numeAngajat, numeAngajat);

    cout << "Introduceti functia angajatului: " << endl;
    in >> obj.functie;

    cout << "Introduceti numarul de ore ale angajatului/zi: " << endl;

    in >> obj.prog;

    cout << "Angajatul ofera feedback pozitiv despre locul de munca: " << endl;
    in >> obj.feedbackAng;
    return in;
}

Angajati::~Angajati(){
    if(this->numeAngajat != NULL){
        delete[] this->numeAngajat;
        this->numeAngajat = NULL;
    }

}

class ProdusePets {
private:
    static int contorId;
    const int idProdus;
    char* numeProdus;
    string tipAnimal;
    float pret;
    bool disponibilSiteMagazin;
    int nrProduse;

public:
    //Constructori
    ProdusePets();  // Constructor fara parametrii
    ProdusePets(char* numeProdus, string tipAnimal,float pret,bool disponibilSiteMagazin,int nrProduse); // Constructor parametrizat
    ProdusePets(const ProdusePets& obj);   // Copy constructor

    //Operator
    ProdusePets& operator = (const ProdusePets&);
    friend ostream& operator <<(ostream& out, const ProdusePets& obj);
    friend istream& operator >>(istream& in, ProdusePets& obj);
    ProdusePets& operator++();
    ProdusePets operator++(int);
    ProdusePets operator+(const ProdusePets& obj);
    ProdusePets operator+(int);
    friend ProdusePets operator+(int, ProdusePets obj);
    bool operator==(const ProdusePets&);
    char operator[](int);
    operator int();
    operator int() const {return this->nrProduse;}
    ProdusePets operator+(Pets& obj);


    //Metode
    //void afisare();
    //void citire();

    //Get+Set



    void settipAnimal(string tipAnimal){this->tipAnimal= tipAnimal;}
    void setnumeProdus(char* numeProdus);
    void setnrProduse(int nrProduse) {this->nrProduse=nrProduse;}
    void setPret( float pret){this->pret=pret;}

    static int getContorId() {return ProdusePets::contorId;}
    string gettipAnimal() {return tipAnimal;}
    const float getPret() const {this->pret;}
    char* getnumeProdus(){return numeProdus;}
    int getnrProduse(){return nrProduse;}





    float stotal();


    //Destructor
    ~ProdusePets();

};
void ProdusePets::setnumeProdus(char* numeProdus){//setter
    if(this->numeProdus != NULL){
        delete[] this->numeProdus;
        this->numeProdus = NULL;
    }
    this->numeProdus = new char[strlen(numeProdus)+1];
    strcpy(this->numeProdus , numeProdus);

}

float ProdusePets::stotal(){
    float sumatotal=0;
    sumatotal=this->nrProduse*this->pret;
    return sumatotal;
                                         // functia calculeaza pretul total al exemplarelor unui produs ales.

}

ProdusePets ProdusePets::operator+(Pets& obj){
    ProdusePets copie(*this);
    {copie.nrProduse= copie.nrProduse+ obj.getnrAnimale();
    }
    return copie;
}

int ProdusePets::contorId = 150;

ProdusePets::ProdusePets():idProdus(contorId++) {
    numeProdus = new char[strlen("Anonim") + 1]; // Alocat memorie fara sa initializam
    strcpy(numeProdus, "Anonim");  // Initializam variabila
    tipAnimal = "Anonim";
    pret = 0;
    disponibilSiteMagazin = false;
}

ProdusePets::ProdusePets(char* numeProdus, string tipAnimal, float pret, bool disponibilSiteMagazin,int nrProduse): idProdus(contorId++){
    this->numeProdus = new char[strlen(numeProdus) + 1];
    strcpy(this->numeProdus, numeProdus);
    this->tipAnimal = tipAnimal;
    this->pret = pret;
    this->disponibilSiteMagazin = disponibilSiteMagazin;
    this->nrProduse = nrProduse;
}

ProdusePets::ProdusePets(const ProdusePets& obj): idProdus(contorId++){
    this->numeProdus = new char[strlen(obj.numeProdus) + 1];
    strcpy(this->numeProdus, obj.numeProdus);
    this->tipAnimal = obj.tipAnimal;
    this->pret = obj.pret;
    this->disponibilSiteMagazin = obj.disponibilSiteMagazin;
    this->nrProduse =obj.nrProduse;
}

ProdusePets& ProdusePets::operator = (const ProdusePets& obj){
    if(this != &obj){
        if(this->numeProdus != NULL){
        delete[] this->numeProdus;
        this->numeProdus = NULL;
        }

        this->numeProdus = new char[strlen(obj.numeProdus) + 1];
        strcpy(this->numeProdus, obj.numeProdus);
        this->tipAnimal = obj.tipAnimal;
        this->pret = obj.pret;
        this->disponibilSiteMagazin = obj.disponibilSiteMagazin;
        this->nrProduse =obj.nrProduse;
    }
    return *this;
}

ProdusePets& ProdusePets::operator++(){
    this->nrProduse++;
    return *this;
}

ProdusePets ProdusePets::operator++(int){
    ProdusePets aux(*this);
    ///this->nrProduse++;
    ++*this;
    return aux;
}

ProdusePets ProdusePets::operator+(const ProdusePets& obj){
    ProdusePets aux(*this);
    aux.tipAnimal += obj.tipAnimal;
    aux.nrProduse += obj.nrProduse;
    return aux;
}

ProdusePets ProdusePets::operator+(int x){
    ProdusePets aux(*this);
    aux.nrProduse += x;
    return aux;
}

ProdusePets operator+(int x, ProdusePets obj){
    return obj+x;
}

bool ProdusePets::operator==(const ProdusePets& obj){
    return this->tipAnimal == obj.tipAnimal;
}

char ProdusePets::operator[](int i){
    if(this->numeProdus == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > this->nrProduse){
        throw runtime_error("Index invalid");
    }
    else
        return this->numeProdus[i];
}

ProdusePets::operator int(){
    return this->nrProduse;
}



ostream& operator <<(ostream& out, const ProdusePets& obj){
    out << "ID: " << obj.idProdus << endl;
    out << "Nume produs: " << obj.numeProdus << endl;
    out << "Pentru ce tip de animal este : " << obj.tipAnimal << endl;
    out << "Pret produs: " << obj.pret <<" "<<"lei"<< endl;
    out << "Sunt disponibile pe site, dar si in magazine : " << obj.disponibilSiteMagazin << endl;
    out<<"Numarul total de produse de care dispune petshop-ul este de:"<< obj.nrProduse<< endl;
    return out;
}

istream& operator >>(istream& in, ProdusePets& obj){
    cout << "Introduceti numele produsului: " << endl;
   char numeProdus[100];
    in >> numeProdus;
    if(obj.numeProdus != NULL){
        delete obj.numeProdus;
        obj.numeProdus = NULL;
    }
    obj.numeProdus = new char[strlen(numeProdus) + 1];
    strcpy(obj.numeProdus, numeProdus);

    cout << "Introduceti pentru ce tip de animal este produsul: " << endl;
    in >> obj.tipAnimal;

    cout << "Introduceti pretul: " << endl;
       in >> obj.pret;

    cout << "Produsul se gaseste pe site, dar si in magazine: " << endl;
    in >> obj.disponibilSiteMagazin;
    return in;
}

ProdusePets::~ProdusePets(){
    if(this->numeProdus != NULL){
        delete[] this->numeProdus;
        this->numeProdus = NULL;
    }

}


int main(){
    Pets a;// apel constructor de initializare
    Locatii b;
    Angajati c;
    ProdusePets d;
    char numePet[] = {"Marius"};
    float n1 =3, n2=4;
    float petsAdoptateNLuni[]={n1,n2};
    char numeLoc[] = {"HappyAnimo"};
    char numeAngajat[]={"Marcel"};
    char numeProdus[]={"Pliculete cu mancare"};
    int s1=37,s2=6,s3=1,s4=4,s5=1;
    int nrLocOras[]= {s1,s2,s3,s4,s5};
    int o1=5,o2=7,o3=8,o4=10;
    int oreMunca[]= {o1,o2,o3,o4};


    Pets a2(numePet, "hamster", 'g', 2, petsAdoptateNLuni, true, 100);
    cout<<a2.animaleAdoptate()<<" "<<"animale adoptate"<<endl;
    Locatii b2(numeLoc,"Bucuresti",4, nrLocOras,10,true,29) ;
    cout<<b2.locTotal()<<" "<<"locatii in toata tara"<<endl;
    Angajati c2(numeAngajat,"casier",2,oreMunca,6,true,31);
    cout<<c2.totalore()<<" "<<"ore lucrate in total de catre angajati"<<endl;
    ProdusePets d2(numeProdus,"Caine",12.45,true,270);
    cout<<d2.stotal()<<" "<<"lei in total"<<endl;



    cout << a2 << endl;
    cout<< b2 << endl;
    cout<< c2<<endl;
    cout<< d2<<endl;




    int choice;
    do {
        cout << "---------------------" << endl;
        cout << "     PetShop   " << endl;
        cout << "---------------------" << endl;
        cout << "1.Doriti sa adoptati un pet:" << endl;
        cout << "2.Doriti sa descoperiti numele petshopului:" << endl;
        cout << "3.Doriti sa aflati daca avem locatie in orasul dumneavoastra:" << endl;
        cout << "4.Doriti sa cumparati un produs pentru un pet:" << endl;
        cout << "5. Quit" << endl;
        cout << endl << "Introduceti optiunea dorita: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {

                cout << "Introduce nume pet: "<<a2.getnumePet()<<endl;


                cout << "Introduce tipul pet-ului: "<<a2.gettipPet()<<endl;

                cout << "Petul a fost ales cu succes." << endl;
                break;
            }

            case 2: {
                cout<<"Numele petshopului este:"<<b2.getnumeLoc()<<endl;


                        break;
                    }

            case 3: {
                    cout<<"Introduceti orasul dumneavoastra:"<<endl;
                if (b2.getnrr() == 0)
                    cout << "Se pare ca nu avem locatie in orasul dumneavoastra" << endl;
                else
                    cout<<"Ne aflam in "<<" "<<b2.getresp()<<" "<<"locatii in orasul dumneavoastra"<<endl;

                break;
            }

            case 4: {
                cout << "Introduceti ce produs vreti sa cumparati: "<<d2.getnumeProdus()<<endl;
                cout<<"Introduceti pentru ce tip de pet vreti sa cumparati produsul:"<<d2.gettipAnimal()<<endl;
                if(d2.getnrProduse()==0)
                cout <<"Produsul nu este disponibil";
                else
                    cout<<"Produsul este disponibil in"<<" "<<d2.getnrProduse()<<" "<<"exemplare";
                break;
            }

            case 5: {
                cout << "La revedere!Va mai asteptam pe la noi:)" << endl;
                break;
            }

            default: {
                cout << "Alegere invalida.Mai incearca." << endl;
                break;
            }
        }

        cout << endl;

    } while (choice != 5);








    return 0;
}


