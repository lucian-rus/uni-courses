// Problema 5: Stiva de caractere implementata dinamic cu pointeri catre struct.
// Operatii: push, pop, afisare, eliberare memorie.

#include <iostream>

struct Nod {
    char data;
    Nod *next;
};

void push(Nod *&varf, char c) {
    Nod *nou  = new Nod;
    nou->data = c;
    nou->next = varf;
    varf      = nou;
}

bool pop(Nod *&varf, char &c) {
    if (varf == nullptr)
        return false;
    Nod *temp = varf;
    c         = varf->data;
    varf      = varf->next;
    delete temp;
    return true;
}

void afiseaza(Nod *varf) {
    std::cout << "Stiva (de la varf la baza): ";
    Nod *p = varf;
    while (p != nullptr) {
        std::cout << p->data << ' ';
        p = p->next;
    }
    std::cout << '\n';
}

void elibereaza(Nod *&varf) {
    while (varf != nullptr) {
        Nod *temp = varf;
        varf      = varf->next;
        delete temp;
    }
}

int main() {
    Nod *stiva = nullptr;

    push(stiva, 'A');
    push(stiva, 'B');
    push(stiva, 'C');
    push(stiva, 'D');
    afiseaza(stiva);

    char c;
    if (pop(stiva, c)) {
        std::cout << "Element scos: " << c << '\n';
    }
    afiseaza(stiva);

    elibereaza(stiva);
    std::cout << "Memorie eliberata.\n";
    afiseaza(stiva);

    return 0;
}
