#include <iostream>

#include "lab2.h"

int main(void) {
    ContBancar c("IBAN1", "Ion", "Ion");

    c.depunereSuma(10);
    c.vizualizareSold();
    c.retragereSuma(3);
    c.vizualizareSold();

    c.afisareInfoCont();
    c.actualizareInfoCont("Ion", "Ioan");
    c.afisareInfoCont();

    return 0;
}

/* constructor */
ContBancar::ContBancar(std::string cont, std::string nume, std::string prenume) {
    m_cont            = cont;
    m_titular.nume    = nume;
    m_titular.prenume = prenume;

    m_sold = 0;
}

/* metode */
void ContBancar::depunereSuma(const int &suma) {
    m_sold += suma;
    std::cout << "Ati depus: " << suma << " lei\n";
}

void ContBancar::retragereSuma(const int &suma) {
    m_sold -= suma;
    std::cout << "Ati retras: " << suma << " lei\n";
}

void ContBancar::vizualizareSold(void) {
    std::cout << "Sold:     " << m_sold << '\n';
}

void ContBancar::actualizareInfoCont(const Titular_t &titular) {
    m_titular = titular;
}

void ContBancar::actualizareInfoCont(std::string nume, std::string prenume) {
    m_titular.nume    = nume;
    m_titular.prenume = prenume;
}

void ContBancar::afisareInfoCont(void) {
    std::cout << "----------\n";
    std::cout << "Cont:     " << m_cont << '\n';
    std::cout << "Nume:     " << m_titular.nume << '\n';
    std::cout << "Prenume:  " << m_titular.prenume << '\n';
}