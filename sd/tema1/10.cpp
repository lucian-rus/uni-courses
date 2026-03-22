#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

// validare initiala care elimina expresiile cu caractere indoielnice
bool expresie_valida(const std::string &linie) {
    const std::string caractere_valide = "1234567890+-*/^()";

    for (char c : linie) {
        if(c == ' ' || c == '\t') {
            continue;
        }

        // daca nu gasim un caracter in lista de caractere valide, returnam
        if(caractere_valide.find(c) == std::string::npos) {
            return false;
        }
    }

    return true;
}

void citeste_expresii_din_fisier(std::vector<std::string> &expresii) {
    std::ifstream fin("expresii.txt");

    std::string linie;
    while (std::getline(fin, linie)) {
        if (expresie_valida(linie) == true) {
            expresii.push_back(linie);
        }
        else {
            std::cout << linie << " -> expresia nu este corecta\n";
        }
    }

    fin.close();
}

int main() {
    std::vector<std::string> expresii;
    citeste_expresii_din_fisier(expresii);

    for (auto item : expresii) {
        std::cout << item << '\n';
    }

    return 0;
}