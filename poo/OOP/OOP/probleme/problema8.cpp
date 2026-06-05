// Problema 8: Clasa Angajat cu ID, nume, salariu.
// Metode: getter, setter, crestere/scadere salariu (procentual sau cu suma).

#include <iostream>
#include <string>

class Angajat {
  private:
    int         id;
    std::string nume;
    double      salariu;

  public:
    Angajat(int id = 0, const std::string &nume = "", double salariu = 0) : id(id), nume(nume), salariu(salariu) {
    }

    int getId() const {
        return id;
    }
    std::string getNume() const {
        return nume;
    }
    double getSalariu() const {
        return salariu;
    }

    void setId(int valoare) {
        id = valoare;
    }
    void setNume(const std::string &valoare) {
        nume = valoare;
    }
    void setSalariu(double valoare) {
        if (valoare >= 0)
            salariu = valoare;
    }

    void cresteSalariu(double procent) {
        if (procent > 0) {
            salariu += salariu * procent / 100.0;
        }
    }

    void scadeSalariu(double procent) {
        if (procent > 0 && procent <= 100) {
            salariu -= salariu * procent / 100.0;
        }
    }

    void afiseaza() const {
        std::cout << "Angajat #" << id << " - " << nume << ", salariu: " << salariu << '\n';
    }
};

int main() {
    Angajat a(1, "Popescu Ion", 3000);
    a.afiseaza();

    a.cresteSalariu(15);
    std::cout << "Dupa crestere cu 15%:\n";
    a.afiseaza();

    a.scadeSalariu(10);
    std::cout << "Dupa scadere cu 10%:\n";
    a.afiseaza();

    a.setNume("Ionescu Maria");
    a.setSalariu(5000);
    std::cout << "Dupa setteri:\n";
    a.afiseaza();

    return 0;
}
