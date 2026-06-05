// Problema 7: Clasa Dreptunghi cu doua puncte (dreapta-sus, stanga-jos).
// Metode: getter, setter, perimetru, arie, afisare.

#include <cmath>
#include <iostream>

class Punct {
  private:
    double x, y;

  public:
    Punct(double x = 0, double y = 0) : x(x), y(y) {
    }

    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    void setX(double valoare) {
        x = valoare;
    }
    void setY(double valoare) {
        y = valoare;
    }
};

class Dreptunghi {
  private:
    Punct dreaptaSus;
    Punct stangaJos;

  public:
    Dreptunghi(Punct ds = Punct(1, 1), Punct sj = Punct(0, 0)) : dreaptaSus(ds), stangaJos(sj) {
    }

    Punct getDreaptaSus() const {
        return dreaptaSus;
    }
    Punct getStangaJos() const {
        return stangaJos;
    }
    void setDreaptaSus(const Punct &p) {
        dreaptaSus = p;
    }
    void setStangaJos(const Punct &p) {
        stangaJos = p;
    }

    double latime() const {
        return std::fabs(dreaptaSus.getX() - stangaJos.getX());
    }

    double inaltime() const {
        return std::fabs(dreaptaSus.getY() - stangaJos.getY());
    }

    double perimetru() const {
        return 2 * (latime() + inaltime());
    }

    double arie() const {
        return latime() * inaltime();
    }

    double diagonala() const {
        double l = latime();
        double h = inaltime();
        return std::sqrt(l * l + h * h);
    }

    void afiseaza() const {
        std::cout << "Dreptunghi: stanga-jos = (" << stangaJos.getX() << ", " << stangaJos.getY() << "), dreapta-sus = ("
                  << dreaptaSus.getX() << ", " << dreaptaSus.getY() << ")\n";
        std::cout << "  Latime: " << latime() << '\n';
        std::cout << "  Inaltime: " << inaltime() << '\n';
        std::cout << "  Perimetru: " << perimetru() << '\n';
        std::cout << "  Arie: " << arie() << '\n';
        std::cout << "  Diagonala: " << diagonala() << '\n';
    }
};

int main() {
    Dreptunghi d(Punct(5, 4), Punct(1, 1));
    d.afiseaza();

    d.setDreaptaSus(Punct(10, 8));
    std::cout << "\nDupa modificarea coltului dreapta-sus:\n";
    d.afiseaza();

    return 0;
}
