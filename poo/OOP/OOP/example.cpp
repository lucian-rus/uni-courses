#include <iostream>
#include <cstring>
using namespace std;

// =========================================================
// 1. CLASĂ ȘABLON (TEMPLATE)
// =========================================================
template <class T>
class Stiva {
private:
    T* elemente;
    int dimensiune;
    int capacitate;

public:
    // Constructor
    Stiva(int cap = 10) {
        capacitate = cap;
        dimensiune = 0;
        elemente = new T[capacitate];
    }

    // Destructor
    ~Stiva() {
        delete[] elemente;
    }

    // Supraîncărcarea operatorului += ca metodă membră
    Stiva<T>& operator+=(const T& element) {
        if (dimensiune < capacitate) {
            elemente[dimensiune++] = element;
        }
        return *this; // Returnarea obiectului curent prin pointerul this
    }

    // Metodă inline
    int getDimensiune() const { return dimensiune; }
};

// =========================================================
// 2. CLASĂ DE BAZĂ ABSTRACTĂ (CU MEMBRI STATICI)
// =========================================================
class Entitate {
protected:
    static int contorInstante; // Membru static (comun tuturor obiectelor)

public:
    Entitate() { contorInstante++; }
    
    // Destructor virtual pentru ierarhii polimorfice
    virtual ~Entitate() { contorInstante--; }

    // Funcție pur virtuală (face clasa abstractă)
    virtual void afiseazaDetalii() const = 0;

    // Metodă statică
    static int getContor() { return contorInstante; }
};

// Inițializarea membrului static în afara clasei
int Entitate::contorInstante = 0;

// =========================================================
// 3. O ALTĂ CLASĂ DE BAZĂ PENTRU MOȘTENIRE MULTIPLĂ
// =========================================================
class Printabil {
public:
    virtual void printeazaEticheta() const = 0;
    virtual ~Printabil() {}
};

// =========================================================
// 4. CLASĂ DERIVATĂ (MOȘTENIRE MULTIPLĂ ȘI VIRTUALĂ)
// =========================================================
class Produs : virtual public Entitate, public Printabil {
private:
    char* nume;   // Alocare dinamică necesită constructor de copiere
    double pret;

    // Clasă imbricată (Nested class)
    class CodBara {
    public:
        int cod;
        CodBara(int c = 0) : cod(c) {}
    } codBara;

public:
    // Constructor cu parametri și valori implicite
    Produs(const char* n = "Anonim", double p = 0.0, int cod = 100);

    // Constructor de copiere (Deep copy)
    Produs(const Produs& altul);

    // Destructor
    ~Produs() override;

    // Supraîncărcarea operatorului de atribuire (folosind this)
    Produs& operator=(const Produs& altul);

    // Suprascrierea funcțiilor virtuale din clasele de bază
    void afiseazaDetalii() const override;
    void printeazaEticheta() const override;

    // Funcție prietenă (friend) externă clasei
    friend ostream& operator<<(ostream& os, const Produs& p);
};

// =========================================================
// DESCRIEREA FUNCȚIILOR MEMBRE ÎN AFARA CLASEI (OUT-OF-LINE)
// =========================================================

// Constructor
Produs::Produs(const char* n, double p, int cod) : pret(p), codBara(cod) {
    nume = new char[strlen(n) + 1];
    strcpy(nume, n);
}

// Constructor de copiere
Produs::Produs(const Produs& altul) : pret(altul.pret), codBara(altul.codBara.cod) {
    nume = new char[strlen(altul.nume) + 1];
    strcpy(nume, altul.nume);
}

// Destructor
Produs::~Produs() {
    delete[] nume;
}

// Operator=
Produs& Produs::operator=(const Produs& altul) {
    if (this != &altul) { // Pointerul this protejează împotriva auto-atribuirii
        delete[] nume;
        pret = altul.pret;
        codBara.cod = altul.codBara.cod;
        nume = new char[strlen(altul.nume) + 1];
        strcpy(nume, altul.nume);
    }
    return *this;
}

void Produs::afiseazaDetalii() const {
    cout << "Produs: " << nume << " | Pret: " << pret << endl;
}

void Produs::printeazaEticheta() const {
    cout << "[Eticheta] Nume: " << nume << " | Cod: " << codBara.cod << endl;
}

// =========================================================
// FUNCȚIE PRIETENĂ (SUPRAÎNCĂRCARE OPERATOR <<)
// =========================================================
ostream& operator<<(ostream& os, const Produs& p) {
    // Are acces direct la membrul privat 'nume' datorită cuvântului 'friend'
    os << p.nume << " (" << p.pret << " RON)";
    return os;
}

// =========================================================
// PROGRAMUL PRINCIPAL
// =========================================================
int main() {
    cout << "--- Testare Concepte POO ---" << endl;

    // 1. Instanțierea claselor și testarea constructorilor
    Produs p1("Laptop", 3500.50, 101);
    Produs p2("Telefon", 2100.00, 102);

    // 2. Testare Constructor de copiere
    Produs p3 = p1; 

    // 3. Testare funcție prietenă (operator <<)
    cout << "Produs copiat: " << p3 << endl;

    // 4. Testare Polimorfism și Funcții Virtuale
    Entitate* ent = &p2;
    ent->afiseazaDetalii(); 

    Printabil* printabil = &p2;
    printabil->printeazaEticheta();

    // 5. Testare Clasă Șablon (Template)
    Stiva<Produs*> stivaProduse(5);
    stivaProduse += &p1; // Testare operator+= suprascris
    stivaProduse += &p2;

    // 6. Testare Membri Statici
    cout << "Numar total de entitati active: " << Entitate::getContor() << endl;

    return 0;
}