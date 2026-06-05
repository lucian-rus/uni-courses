#include <cstring>
#include <iostream>

using namespace std;

// =========================================================
// 1. CLASA DE BAZĂ ABSTRACTĂ
// =========================================================
class Dispozitiv {
  private:
    char      *denumire;
    static int contorDispozitive; // Variabilă statică

  public:
    // Constructor cu parametri
    Dispozitiv(const char *den = "Anonim") {
        denumire = new char[strlen(den) + 1];
        strcpy(denumire, den);
        contorDispozitive++;
    }

    // Constructor de copiere (Deep Copy)
    Dispozitiv(const Dispozitiv &altul) {
        denumire = new char[strlen(altul.denumire) + 1];
        strcpy(denumire, altul.denumire);
        contorDispozitive++;
    }

    // Destructor (Virtual - crucial pentru lucrul cu pointeri la clasa de bază)
    virtual ~Dispozitiv() {
        delete[] denumire;
        contorDispozitive--;
    }

    // Supraîncărcarea operatorului de atribuire cu protecție via this
    Dispozitiv &operator=(const Dispozitiv &altul) {
        if (this != &altul) { // Evităm auto-atribuirea (ex: obj = obj)
            delete[] denumire;
            denumire = new char[strlen(altul.denumire) + 1];
            strcpy(denumire, altul.denumire);
        }
        return *this;
    }

    // Gettere
    const char *getDenumire() const {
        return denumire;
    }

    // Metodă statică pentru accesarea membrului static
    static int getContor() {
        return contorDispozitive;
    }

    // Funcție pur virtuală (Transformă clasa în una abstractă)
    virtual void afiseazaDetalii() const = 0;
};

// Inițializarea membrului static în afara clasei
int Dispozitiv::contorDispozitive = 0;

// =========================================================
// 2. MOȘTENIRE VIRTUALĂ (Pentru a preveni ierarhia "Romb")
// =========================================================
class Senzor : virtual public Dispozitiv {
  protected:
    float precizie;

  public:
    Senzor(const char *den = "Senzor", float prec = 0.1) : Dispozitiv(den), precizie(prec) {
    }
};

class Controler : virtual public Dispozitiv {
  protected:
    int numarCanale;

  public:
    Controler(const char *den = "Controler", int nrC = 1) : Dispozitiv(den), numarCanale(nrC) {
    }
};

// =========================================================
// 3. MOȘTENIRE MULTIPLĂ (Din Senzor și Controler)
// =========================================================
class TermostatSmart : public Senzor, public Controler {
  public:
    // ATENȚIE: La moștenirea virtuală, clasa cel mai jos în ierarhie trebuie
    // să apeleze EXPLICIT constructorul clasei de bază virtuale (Dispozitiv)
    TermostatSmart(const char *den, float prec, int nrC) : Dispozitiv(den), Senzor(den, prec), Controler(den, nrC) {
    }

    // Suprascrierea funcției pur virtuale
    void afiseazaDetalii() const override {
        cout << "Termostat: " << getDenumire() << " | Precizie: " << precizie << " | Canale: " << numarCanale << endl;
    }

    // Supraîncărcarea operatorului << printr-o funcție prietenă (friend)
    friend ostream &operator<<(ostream &os, const TermostatSmart &t) {
        os << "[" << t.getDenumire() << " - Prec: " << t.precizie << ", Canale: " << t.numarCanale << "]";
        return os;
    }
};

// =========================================================
// 4. CLASĂ ȘABLON (TEMPLATE) ȘI EXCEPȚII
// =========================================================
template <class T> class Catalog {
  private:
    T  *elemente;
    int dimensiune;
    int capacitate;

  public:
    Catalog(int cap = 10) : capacitate(cap), dimensiune(0) {
        elemente = new T[capacitate];
    }

    ~Catalog() {
        delete[] elemente;
    }

    // Supraîncărcare operator+= cu aruncare de excepții
    Catalog<T> &operator+=(const T &element) {
        if (dimensiune >= capacitate) {
            throw "Eroare: Capacitate depasita! Nu se pot adauga alte dispozitive.";
        }
        elemente[dimensiune++] = element;
        return *this;
    }

    // Metode ajutătoare
    int getDimensiune() const {
        return dimensiune;
    }
    T getElement(int i) const {
        return elemente[i];
    }
};

// =========================================================
// 5. PROGRAMUL PRINCIPAL (MAIN)
// =========================================================
int main() {
    cout << "--- Sistem Smart Home ---" << endl;

    // Instantiem un catalog cu capacitate maxima de 2 elemente
    Catalog<Dispozitiv *> catalog(2);

    // Alocam dinamic dispozitive
    TermostatSmart *t1 = new TermostatSmart("Termostat Living", 0.5f, 2);
    TermostatSmart *t2 = new TermostatSmart("Termostat Dormitor", 0.1f, 1);
    TermostatSmart *t3 = new TermostatSmart("Termostat Baie", 0.2f, 1);

    try {
        cout << "Adaugam dispozitive in catalog..." << endl;
        catalog += t1;
        catalog += t2;

        cout << "Dispozitive adaugate cu succes. Testam polimorfismul:" << endl;
        // Demonstram Polimorfismul si Late-Binding-ul (Apelul se rezolva la executie)
        for (int i = 0; i < catalog.getDimensiune(); i++) {
            cout << " - ";
            catalog.getElement(i)->afiseazaDetalii();
        }

        cout << "\nNumar total dispozitive active: " << Dispozitiv::getContor() << endl;

        // Testam functia friend si operatorul <<
        cout << "\nAfisare detaliata prin friend operator<< : " << *t1 << endl;

        cout << "\nIncercam sa adaugam al 3-lea dispozitiv (peste capacitate)..." << endl;
        catalog += t3; // Aici se va arunca exceptia

    } catch (const char *mesajEroare) {
        // Prindem si afisam exceptia
        cout << "\n>>> EXCEPTIE PRISA: " << mesajEroare << " <<<" << endl;
    }

    // Eliberarea memoriei alocate pentru obiectele propriu-zise
    // (Catalogul elibereaza doar vectorul de pointeri, nu si zonele pointate)
    delete t1;
    delete t2;
    delete t3;

    cout << "\nNumar total dispozitive dupa curatare: " << Dispozitiv::getContor() << endl;

    return 0;
}