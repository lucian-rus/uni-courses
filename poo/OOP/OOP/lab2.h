#pragma once

#include <string>

typedef struct {
    std::string nume;
    std::string prenume;
} Titular_t;

class ContBancar {
  public:
    /* constructor */
    ContBancar(std::string cont, std::string nume, std::string prenume);

    /* sold */
    void depunereSuma(const int &suma);
    void retragereSuma(const int &suma);
    void vizualizareSold(void);

    /* info */
    void actualizareInfoCont(const Titular_t &titular);
    void actualizareInfoCont(std::string nume, std::string prenume);
    void afisareInfoCont(void);

  private:
    unsigned int m_sold;
    std::string  m_cont;
    Titular_t    m_titular;
};
