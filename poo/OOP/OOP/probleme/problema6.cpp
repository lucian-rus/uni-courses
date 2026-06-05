// Problema 6: Clasa Cerc cu raza si centru.
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

class Cerc {
  private:
    Punct  centru;
    double raza;

  public:
    Cerc(Punct c = Punct(), double r = 1) : centru(c), raza(r) {
    }

    Punct getCentru() const {
        return centru;
    }
    double getRaza() const {
        return raza;
    }
    void setCentru(const Punct &c) {
        centru = c;
    }
    void setRaza(double r) {
        if (r > 0)
            raza = r;
    }

    double perimetru() const {
        return 2 * M_PI * raza;
    }

    double arie() const {
        return M_PI * raza * raza;
    }

    bool contine(const Punct &p) const {
        double dx = p.getX() - centru.getX();
        double dy = p.getY() - centru.getY();
        return dx * dx + dy * dy <= raza * raza;
    }

    void afiseaza() const {
        std::cout << "Cerc cu centrul (" << centru.getX() << ", " << centru.getY() << ") si raza " << raza << '\n';
        std::cout << "  Perimetru: " << perimetru() << '\n';
        std::cout << "  Arie: " << arie() << '\n';
    }
};

int main() {
    Cerc c(Punct(2, 3), 5);
    c.afiseaza();

    c.setRaza(10);
    std::cout << "\nDupa setRaza(10):\n";
    c.afiseaza();

    Punct p(4, 5);
    std::cout << "\nPunctul (4, 5) este in cerc? " << (c.contine(p) ? "DA" : "NU") << '\n';

    return 0;
}
