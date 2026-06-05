#include "ProdusAlimentar.h"

ProdusAlimentar::ProdusAlimentar(const std::string &nume, double pret, Data data, double cantitate)
    : Produs(nume, pret), termenValabilitate(data), cantitate(cantitate) {
    std::cout << "Constructor ProdusAlimentar\n";
}

ProdusAlimentar::~ProdusAlimentar() {
    std::cout << "Destructor ProdusAlimentar\n";
}

void ProdusAlimentar::afisare() {
    Produs::afisare();
    std::cout << "Termen valabilitate: " << termenValabilitate << std::endl;
    std::cout << "Cantitate: " << cantitate << std::endl;
}