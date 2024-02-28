#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <set>
#include <map>
#include<typeinfo>

using namespace std;


template <typename S,typename F>
class Ingredient{
    S nume1;
    F pret;

public:

    Ingredient(S nume1=" ", F pret=F());
    Ingredient(const Ingredient&);

    Ingredient& operator =(const Ingredient&);
    friend istream& operator >>(istream&, Ingredient&);
    friend ostream& operator <<(ostream&, const Ingredient&);

    F getPret() const {return this->pret;}
    S getNume1() const{ return this->nume1;}
    void setNume1( S nume1){this->nume1 = nume1;}
};

template <typename S,typename F>
Ingredient<S,F>::Ingredient(S nume1, F pret){
    this->nume1 = nume1;
    this->pret = pret;
}

template <typename S,typename F>
Ingredient<S,F>::Ingredient(const Ingredient& obj){
    this->nume1 = obj.nume1;
    this->pret = obj.pret;
}
template <typename S,typename F>
Ingredient<S,F>& Ingredient<S,F>::operator =(const Ingredient& obj){
    if(this != &obj){
        this->nume1 = obj.nume1;
        this->pret = obj.pret;
    }
    return *this;
}

//template <typename S,typename F>
istream& operator >>(istream& in, Ingredient<string,float>& obj){
    cout << "Introduceti numele\n";
    in >> obj.nume1;
    cout << "Introduceti pretul\n";
    in >> obj.pret;
    return in;
}

//template <typename S,typename F>
ostream& operator <<(ostream& os, const Ingredient<string,float>& obj){
    os << "Nume: " << obj.nume1 << endl;
    os << "Pret: " << obj.pret << endl;
    return os;
}

class IOinterface{
public:
    virtual istream& citire(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
};

class Mancare: public IOinterface{
protected:
    string nume;
    map<string,float> listaIng;
    float calorii;

public:
    Mancare();
    Mancare(string nume, const map<string,float>& listaIng, float calorii);
    Mancare(const Mancare&);

    Mancare& operator=(const Mancare&);
    friend istream& operator >>(istream&, Mancare&);
    friend ostream& operator <<(ostream&, const Mancare&);
    bool esteValida() const;
    float total() const;

     istream& citire(istream& in) {
        cout << "Introduceti numele\n";
        in.ignore();
        getline(in, this->nume);

        this->listaIng.clear();  // Golește map-ul de ingrediente existente

        cout << "1. Add ing\n";
        cout << "2. Inceteaza sa adaugi\n";
        int k;

        while (cin >> k && k != 2) {
            string numeIng;
            float pret;
            cout << "Introduceti numele ingredientului\n";
            in.ignore();
            getline(in, numeIng);
            cout << "Introduceti pretul ingredientului\n";
            in >> pret;

            // Adaugă ingredientul în map
            this->listaIng[numeIng] = pret;

            cout << "1. Add ing\n";
            cout << "2. Inceteaza sa adaugi\n";
        }

        cout << "Introduceti caloriile\n";
        in >> this->calorii;
        return in;
    }

    ostream& afisare(ostream& os) const {
        os << "Nume: " << this->nume << endl;
        os << "Lista de ingrediente: \n";
        for (const auto& ingredient : this->listaIng) {
            os << "Ingredient: " << ingredient.first << ", Pret: " << ingredient.second << endl;
        }
        os << "Calorii: " << this->calorii << endl;
        os << "Pret total: " << this->total() << " lei" << endl;

        return os;
    }

    string getNume() const { return this->nume; }
    void setNume(const string& nume) { this->nume = nume; }
    void setCalorii(float calorii) { this->calorii = calorii; }
    float getCalorii() const { return this->calorii; }
    const map<string, float>& getlistaIng() const { return this->listaIng; }
    void setlistaIng(const map<string, float>& listaIng) { this->listaIng = listaIng; }
    virtual float pret() const = 0;


    /*istream& citire(istream& in){
        cout << "Introduceti numele\n";
        in.ignore();
        getline(in, this->nume);
        if(!this->listaIng.empty()){
                this->listaIng.clear();
        }
        cout << "1. Add ing\n";
        cout << "2. Inceteaza sa adaugi\n";
        int k;

        while(cin >> k && k != 2){
            ///Ingredient i;
            ///in >> i;
            ///obj.listaIng.push_back(i);
            this->listaIng.push_back(*(new Ingredient<string,float>()));
            in >> this->listaIng.back();
            cout << "1. Add ing\n";
            cout << "2. Inceteaza sa adaugi\n";
        }

        cout << "Introduceti caloriile\n";
        in >> this->calorii;
        return in;
    }


    ostream& afisare(ostream& os) const{
        os << "Nume: " << this->nume << endl;
        os << "Lista de ingredient: \n";
        for(int i = 0; i < this->listaIng.size(); i++)
            os << this->listaIng[i] << endl;
        os << "calorii: " << this->calorii << endl;
        os<<"Pret total:" << this->total()<<" lei"<<endl;

        return os;
    }
    */

   /* string getNume() {return this->nume;}
    void setNume( string nume){this->nume = nume;}
    void setCalorii( float calorii){this->calorii = calorii;}
    float getCalorii() {return this->calorii;}
    vector <Ingredient<string,float>> getlistaIng() {return this->listaIng;}
    void setlistaIng (vector <Ingredient<string,float>> listaIng){this->listaIng = listaIng;}
    virtual float pret() const = 0;  */


    void test() {cout << "Mancare\n";}

    virtual ~Mancare() {}
};
bool Mancare::esteValida() const {
    // Verifică dacă numele, ingredientele și instrucțiunile sunt nevide
    if (nume.empty()) {
        return false;
    }
    return true;
}

float Mancare::total() const {
    float pretTotal = 0;
    for (const auto& ingredient : listaIng) {
        pretTotal += ingredient.second;
    }
    return pretTotal;
}

 /*float Mancare::total()const {
     int prett=0;
     for(int i = 0; i < this->listaIng.size(); i++)
           {prett += this->listaIng[i].getPret();}
        return prett;
}*/

class MancareGluten: virtual public Mancare{
protected:
    bool veg;
public:
    MancareGluten();
    MancareGluten(string nume, const map<string,float>& listaIng, float calorii, bool veg);
    MancareGluten(const MancareGluten&);

    MancareGluten& operator =(const MancareGluten&);

    istream& citire(istream& in){
        this->Mancare::citire(in);
        cout << "Introduceti daca tipul de mancare este/nu este de post\n";
        in >> this->veg;
        return in;
    }

    ostream& afisare(ostream& os) const {
        this->Mancare::afisare(os);
        cout << "Tipul de mancare este/nu este de post: " << this->veg << endl;
        return os;
    }

    //float pret() const {float pret = 0; for(int i = 0; i < this->listaIng.size(); i++) pret += this->listaIng[i].getPret(); return pret;}
   float pret() const {
    float pret = 0;
    for (const auto& ingredient : listaIng) {
        pret += ingredient.second;
    }
    return pret;
}


    void test() {cout << "Mancare care contine gluten\n";}
    virtual ~MancareGluten() {}
};

class MancareFGluten: virtual public Mancare{
protected:
    bool prepRapid;
public:
    MancareFGluten();
    MancareFGluten(string nume, const map<string,float>& listaIng, float calorii, bool prepRapid);
    MancareFGluten(const MancareFGluten&);

    MancareFGluten& operator =(const MancareFGluten&);

    istream& citire(istream& in){
        this->Mancare::citire(in);
        cout << "Introduceti daca se prepara rapid sau nu\n";
        in >> this->prepRapid;
        return in;
    }

    ostream& afisare(ostream& os) const {
        this->Mancare::afisare(os);
        cout << "Se prepara rapid: " << this->prepRapid << endl;
        return os;
    }

    /*float pret() const {
        float pret = 0;
        for(int i = 0; i < this->listaIng.size(); i++)
            pret += this->listaIng[i].getPret();
        return pret;
    }*/
    float pret() const {
    float pret = 0;
    for (const auto& ingredient : listaIng) {
        pret += ingredient.second;
    }
    return pret;
}


    void test() {cout << "Mancare care nu contine gluten\n";}

    virtual ~MancareFGluten() {}
};

Mancare::Mancare(){
    this->nume = "anonim";
    this->listaIng = {};
    this->calorii = 0;
    //cout << "Mancare\n";
}

Mancare::Mancare(string nume, const map<string,float>& listaIng, float calorii){
    this->nume = nume;
    this->listaIng = listaIng;
    this->calorii = calorii;
}

Mancare::Mancare(const Mancare& obj){
    this->nume = obj.nume;
    this->listaIng = obj.listaIng;
    this->calorii = obj.calorii;
}

Mancare& Mancare::operator=(const Mancare& obj){
    if(this != &obj){
        this->nume = obj.nume;
        this->listaIng = obj.listaIng;
        this->calorii = obj.calorii;
    }
    return *this;
}

istream& operator >>(istream& in, Mancare& obj){
    return obj.citire(in);
}

ostream& operator <<(ostream& os, const Mancare& obj){
    return obj.afisare(os);
}

MancareGluten::MancareGluten(): Mancare(){
    this->veg = 0;
    //cout << "Mancare care contine gluten\n";
}

MancareGluten::MancareGluten(string nume, const map<string,float>& listaIng, float calorii, bool veg):
    Mancare(nume, listaIng, calorii){
    this->veg = veg;
}

MancareGluten::MancareGluten(const MancareGluten& obj): Mancare(obj){
    this->veg = obj.veg;
}

MancareGluten& MancareGluten::operator =(const MancareGluten& obj){
    if(this != &obj){
        Mancare::operator=(obj);
        this->veg = obj.veg;
    }
    return *this;
}

MancareFGluten::MancareFGluten(): Mancare(){
    this->prepRapid = 0;
    //cout << "Mancare fara gluten\n";
}

MancareFGluten::MancareFGluten(string nume, const map<string,float>& listaIng, float calorii, bool prepRapid):
    Mancare(nume, listaIng, calorii){
    this->prepRapid = prepRapid;
}

MancareFGluten::MancareFGluten(const MancareFGluten& obj): Mancare(obj){

    this->prepRapid = obj.prepRapid;
}

MancareFGluten& MancareFGluten::operator =(const MancareFGluten& obj){
    if(this != &obj){
        Mancare::operator=(obj);
        this->prepRapid = obj.prepRapid;
    }
    return *this;
}

class Desert: public MancareGluten, public MancareFGluten {
    bool ornare;
public:
    Desert(){
        this->ornare = 1;
        //cout << "Desert\n";
    }

    Desert(string nume, const map<string,float>& listaIng, float calorii,
            bool veg, bool prepRapid, bool ornare): Mancare(nume, listaIng, calorii), MancareGluten(nume,
                listaIng, calorii, veg), MancareFGluten(nume, listaIng, calorii,prepRapid){
        this->ornare = ornare;
    }

    Desert(const Desert& obj): Mancare(obj), MancareGluten(obj), MancareFGluten(obj){
        this->ornare = obj.ornare;
    }

    Desert& operator =(const Desert& obj){
        if(this != &obj){
            MancareGluten::operator=(obj);
            MancareFGluten::operator=(obj);
            this->ornare = obj.ornare;
        }
        return *this;
    }

    istream& citire(istream& in) {
        Mancare::citire(in);
        cout << "Introduceti daca tipul de mancare este/nu este de post\n";
        in >> this->veg;
        cout << "Introduceti daca se prepara rapid sau nu\n";
        in >> this->prepRapid;
        cout << "Introduceti daca doriti sa fie ornat desertul\n";
        try{
        in >> this->ornare;
        if(this->ornare!=1)
            throw std::invalid_argument("In pretul acestui desert intra si ornarea.");
        }
         catch (const std::exception& e) {
        cout << "A aparut o exceptie: " << e.what() << endl; // Afișează mesajul de eroare din excepție
    }
        return in;
    }
    ostream& afisare(ostream& os) const {
        Mancare::afisare(os);
        os << "Tipul de mancare este/nu este de post: " << this->veg << endl;
        os << "Se prepara rapid: " << this->prepRapid << endl;
        os << "Ornare desert: " << this->ornare << endl;
        return os;
    }
    float pret() const {
        return MancareGluten::pret() +  this->ornare;
    }


    void fDesert() {cout <<this->ornare<<endl;}

    virtual ~Desert() {}
};

class ItemInventar{
    Mancare* preparate;

public:
    friend istream& operator >>(istream& in, ItemInventar& obj){
        cout << "1. Mancare cu gluten\n";
        cout << "2. Mancare fara gluten\n";
        cout << "3. Desert\n";
        int k;
        cin >> k;
        if(k == 1){
             obj.preparate = new MancareGluten();


             }

        if(k == 2){
            obj.preparate = new MancareFGluten();

        }
        if(k == 3)
            obj.preparate = new Desert();
        in >> *obj.preparate;


        return in;
    }

    friend ostream& operator<<(ostream& os, const ItemInventar& obj){
       // os << "Mancare:\n" << *obj.preparate << endl;
        os << "Mancare:\n";
        if(typeid(*obj.preparate)==typeid(MancareGluten))
              os<<dynamic_cast<MancareGluten&>(*obj.preparate);
        if(typeid(*obj.preparate)==typeid(MancareFGluten))
              os<<dynamic_cast<MancareFGluten&>(*obj.preparate);
        if(typeid(*obj.preparate)==typeid(Desert))
              os<<dynamic_cast<Desert&>(*obj.preparate);

        return os;
    }

    Mancare* getMancare() {return this->preparate;}
};


class CarteRetete{
    list<ItemInventar> inventar;
    vector<Mancare*> retete;
    Mancare* reteta;
    Ingredient<string,float> ingred;
    map<string,float> ingrediente;
    set<Mancare*> alimentePotrivite;


public:
    void addInventar();
    void addIngredient();
    void showInventar();
    void actualizeazaReteta( string numeReteta,string numeNou,vector <string> ingredienteNoi);
    template<typename M>
    void addMeniu(const M& numeReteta);
    void afiseazaRetete();
    void afiseazaIngrediente();
    template <typename C>
    void calorii(const C& nrCalorii);
    void afiseazaCalorii();
    //void afiseazaCalorii();
    void citesteRetete(const string& numeFisier);

};

template<typename M>
void CarteRetete::addMeniu(const M& numeReteta){
    for(auto it = inventar.begin(); it != inventar.end(); it++){
        if(it->getMancare()->getNume() == numeReteta){
            retete.push_back(it->getMancare());

        }
    }
}

template<typename C>
void CarteRetete::calorii(const C& nrCalorii){

     for(auto it = inventar.begin(); it != inventar.end(); it++){
        if(it->getMancare()->getCalorii() <= nrCalorii){
            alimentePotrivite.insert(it->getMancare());}

    /* else{
           cout<<"Reteta nu indeplineste criteriul"<<endl;}
         */

     }
}
    void CarteRetete::afiseazaCalorii() {

         if (alimentePotrivite.empty()) {
        throw std::runtime_error("Nu exista alimente care sa indeplineasca criteriul."); // Aruncă o excepție de tip std::runtime_error
    }


     cout << "Retete care indeplinesc criteriul: "<<endl;
    for (const auto& aliment : alimentePotrivite) {
        cout << aliment->getNume() << endl;
    }


}


void CarteRetete::actualizeazaReteta(string numeReteta, string numeNou, vector<string> ingredienteNoi) {
    try {
        for (auto& reteta : retete) {
            if (reteta->getNume() == numeReteta) {
                // Actualizează numele rețetei
                if (!numeNou.empty()) {
                    reteta->setNume(numeNou);
                }

                // Actualizează ingredientele
                if (!ingredienteNoi.empty()) {
                    for (const auto& ingredient : reteta->getlistaIng()) {
                       // ingrediente[ingredient.getNume1()] = ingredient.getPret();
                       ingrediente[ingredient.first] = ingredient.second;

                    }

                    for (const auto& numeIngredient : ingredienteNoi) {
                        double pret;
                        cout << "Introduceti pretul pentru ingredientul " << numeIngredient << ": ";
                        cin >> pret;
                        ingrediente[numeIngredient] = pret;
                    }

                    reteta->setlistaIng(ingrediente);
                }

                // Verifică dacă datele actualizate sunt valide
                if (!reteta->esteValida()) {
                    throw std::logic_error("Datele actualizate nu sunt valide!");
                }

                return;
            }
        }

        // Dacă numele rețetei nu a fost găsit
        throw std::runtime_error("Numele retetei nu exista in Cartea de retete!");
    } catch (const std::exception& e) {
        cout << "A aparut o exceptie: " << e.what() << endl; // Afișează mesajul de eroare din excepție
    }
}

void CarteRetete::afiseazaRetete() {
    for (const auto& reteta : retete) {
        cout << "Numele nou al retei: " << reteta->getNume() << '\n';
         cout << "Update Ingrediente:";
        for (const auto& ingredient : reteta->getlistaIng()) {
                 //for (const auto& pair : ingredient) {
                cout << " " << ingredient.first << " - " << ingredient.second;
           // }
            //cout << " " << ingredient.getNume1();

        }
        cout << '\n';
       }
}

void CarteRetete::addInventar(){
    try {
        ItemInventar i;
        cin >> i;
        if (i.getMancare()->getCalorii()<0) {
            throw std::invalid_argument("Mancarea introdusa este invalida!"); // Aruncă o excepție de tip std::invalid_argument
        }
        inventar.push_back(i);
    } catch (const std::exception& e) {
        cout << "A aparut o exceptie: " << e.what() << endl; // Afișează mesajul de eroare din excepție
    }


   /* ItemInventar i;
    cin >> i;
    inventar.push_back(i);
    */
}

void CarteRetete::showInventar(){
    for(auto it = inventar.begin(); it != inventar.end(); it++)
        cout << *it << endl;
}


// Singleton
class Aplicatie {
private:
    static Aplicatie* instance;
    list<ItemInventar> inventar;

    // Constructorul și destructorul sunt private pentru a preveni crearea obiectelor Aplicatie în afara clasei
    Aplicatie() {}
    ~Aplicatie() {}

public:
    // Metodă statică pentru a obține instanța unică a clasei Aplicatie
    static Aplicatie* getInstance() {
        if (instance == nullptr) {
            instance = new Aplicatie();
        }
        return instance;
    }

    // Metodele specifice aplicației
    void showMenu() {
        cout << " 1. Add inventar\n";
        cout << " 2. Show inventar\n";
        cout << " 3. Update retete\n";
        cout << " 4. Filtrare retete dupa calorii\n ";
        cout << "5. Stop\n";
    }

      void addMancare() {
          ItemInventar i;
          cin>>i;
        inventar.push_back(i);
    }

    void showInventar1() {
        // Afișarea rețetelor din inventar
        std::cout << "Inventar retete:" << std::endl;
        for (auto it=inventar.begin();it!=inventar.end();it++) {
            std::cout << *it << std::endl;
        }
    }

    void importData(const std::string& fileName) {
        std::ifstream inputFile(fileName);

    if (inputFile.is_open()) {
        // Procesează datele importate din fișier
        // Exemplu: citirea și afișarea conținutului fișierului
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;

        }

        inputFile.close();
        std::cout << "Importul datelor din fisierul " << fileName << " a fost realizat cu succes." << std::endl;
    } else {
        std::cout << "Eroare la deschiderea fisierului " << fileName << ". Importul datelor a esuat." << std::endl;
    }

    }

    void meniu(){
    CarteRetete c;
    int option;
    bool running = true;

    while (running) {
        showMenu();
        cout << "Alegeti o optiune: ";
        cin >> option;
     try{
        switch (option) {
            case 1: {cout<<"1.Deschide fisier cu retete\n";
                    cout<<"2.Adauga o noua reteta\n";
                    int q;
                    cin>>q;
             if(q==1){
                std::string fileName;
                std::cout << "Introduceti numele fisierului de import: ";
                std::cin >> fileName;
                importData(fileName);
                break;}
             if(q==2)
             {
                  c.addInventar();
                break;
             }
            }
            case 2: {
               /* std::string fileName;
                std::cout << "Introduceti numele fisierului de export: ";
                std::cin >> fileName;
                app->exportData(fileName);
                break;
                */
                 c.showInventar();
               // app->addMancare();
              //  app->showInventar1();
             //app->showInventar();
                break;
            }
            case 3:
               {/*app->citesteMancare();
                break;
                */

               cout << "Nume reteta: ";
               string numeReteta;
               cin.ignore();
               getline(cin,numeReteta);
               //cout<<numeReteta;
                //cin >> numeReteta;

                c.addMeniu<string>(numeReteta);
                cout<<"Nume nou: ";
                string numeNou;
               getline(cin,numeNou);
              // cout<<numeNou;
               // cin>>numeNou;

                //string ingredienteNoi;
               // cin>>ingredienteNoi;

                vector<string> ingredienteNoi;
                string nou;
                cout << "Introduceti ingrediente noi pentru reteta: ";
                while (cin >> nou ) {
                             if (nou == "q") {
                             break; // opreste bucla cand se introduce 'q'
                                }
                     ingredienteNoi.push_back(nou);


                }

               c.actualizeazaReteta( numeReteta,numeNou,ingredienteNoi);
               c.afiseazaRetete();

                break;
            }

            case 4:
               {
                    try {   cout<<"nr calorii:"<<endl;
                          float nrCalorii;
                           cin>>nrCalorii;
                            c.calorii<float>(nrCalorii);
                             c.afiseazaCalorii();
                         //c.afiseazaCalorii();
                      } catch (const std::exception& e) {
                       cout << "A aparut o exceptie: " << e.what() << endl; // Afișează mesajul de eroare din excepție
                       }
               /* cout<<"nr calorii:"<<endl;
                 float nrCalorii;
                 cin>>nrCalorii;
                 c.calorii<float>(nrCalorii);
                 c.afiseazaCalorii();*/
               break;
               }
            case 5:
               {running = false;
                 cout<<"Spor la gatit si pofta buna!";
                break;
            default:
                //std::cout << "Optiune invalida. Va rugam incercati din nou." << std::endl;
                break;
               }
        }

        std::cout << std::endl;
    if(option>5){
         throw std::runtime_error("Nu exista aceasta optiune");
    }
    }
    catch (const std::exception& e) {
        cout << "A aparut o exceptie: " << e.what() << endl; // Afișează mesajul de eroare din excepție
    }
    }
    }
};

Aplicatie* Aplicatie::instance = nullptr;

int main()
{
    string fileName = "input.txt"; // Numele fisierului cu datele retetelor

   // CarteRetete carteRetete;
   // carteRetete.afiseazaRetete();
    CarteRetete c;
   // c.citesteRetete(numeFisier);
    Aplicatie* meniu;
     meniu=meniu->getInstance();
     meniu->meniu();

    Mancare* p = new Desert();
   dynamic_cast<Desert*>(p)->fDesert();

   // Aplicatie* app = Aplicatie::getInstance();

   // void meniu{
   // int option;
    //bool running = true;

    //while (running) {
      //  app->showMenu();
       // cout << "Alegeti o optiune: ";
      //  cin >> option;
    // try{
        /*switch (option) {
            case 1: {cout<<"1.Deschide fisier cu retete\n";
                    cout<<"2.Adauga o noua reteta\n";
                    int q;
                    cin>>q;
             if(q==1){
                std::string fileName;
                std::cout << "Introduceti numele fisierului de import: ";
                std::cin >> fileName;
                app->importData(fileName);
                break;}
             if(q==2)
             {
                  c.addInventar();
                break;
             }
            }
            case 2: {
               /* std::string fileName;
                std::cout << "Introduceti numele fisierului de export: ";
                std::cin >> fileName;
                app->exportData(fileName);
                break;

                 c.showInventar();
               // app->addMancare();
              //  app->showInventar1();
             //app->showInventar();
                break;
            }
            case 3:
               {/*app->citesteMancare();
                break;


               cout << "Nume reteta: ";
               string numeReteta;
               cin.ignore();
               getline(cin,numeReteta);
               //cout<<numeReteta;
                //cin >> numeReteta;

                c.addMeniu<string>(numeReteta);
                cout<<"Nume nou: ";
                string numeNou;
               getline(cin,numeNou);
              // cout<<numeNou;
               // cin>>numeNou;

                //string ingredienteNoi;
               // cin>>ingredienteNoi;

                vector<string> ingredienteNoi;
                string nou;
                cout << "Introduceti ingrediente noi pentru reteta: ";
                while (cin >> nou ) {
                             if (nou == "q") {
                             break; // opreste bucla cand se introduce 'q'
                                }
                     ingredienteNoi.push_back(nou);


                }

               c.actualizeazaReteta( numeReteta,numeNou,ingredienteNoi);
               c.afiseazaRetete();

                break;
            }

            case 4:
               {
                    try {   cout<<"nr calorii:"<<endl;
                          float nrCalorii;
                           cin>>nrCalorii;
                            c.calorii<float>(nrCalorii);
                             c.afiseazaCalorii();
                         //c.afiseazaCalorii();
                      } catch (const std::exception& e) {
                       cout << "A aparut o exceptie: " << e.what() << endl; // Afișează mesajul de eroare din excepție
                       }
               /* cout<<"nr calorii:"<<endl;
                 float nrCalorii;
                 cin>>nrCalorii;
                 c.calorii<float>(nrCalorii);
                 c.afiseazaCalorii();
               break;
               }
            case 5:
               {running = false;
                 cout<<"Spor la gatit si pofta buna!";
                break;
            default:
                //std::cout << "Optiune invalida. Va rugam incercati din nou." << std::endl;
                break;
               }
        }

        std::cout << std::endl;

    if(option>5){
         throw std::runtime_error("Nu exista aceasta optiune");
    }
    }
    catch (const std::exception& e) {
        cout << "A aparut o exceptie: " << e.what() << endl; // Afișează mesajul de eroare din excepție
    }
    } */
 //   }
    // delete app;
    return 0;
}



