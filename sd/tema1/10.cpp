#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int prioritate(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
        default:
            break;
    }

    return 1;
}

// validare initiala care elimina expresiile cu caractere indoielnice
bool expresie_valida(std::string &linie) {
    const std::string caractere_valide = "1234567890+-*/^()";
    const std::string operatori        = "+-*/^";

    std::string aux = "";
    for (char c : linie) {
        if (c == ' ' || c == '\t') {
            continue;
        }

        // daca nu gasim un caracter in lista de caractere valide, returnam
        if (caractere_valide.find(c) == std::string::npos) {
            std::cout << "caracter invalid : \"" << c << "\"\n";
            return false;
        }

        // nu permitem doi operatori consecutivi (ex: ++)
        if (!aux.empty() && operatori.find(aux.back()) != std::string::npos && operatori.find(c) != std::string::npos) {
            std::cout << "prea multi operatori: " << aux.back() << c << "\n";
            return false;
        }

        // scapam de caracterele albe acum, astfel facem parcurgerea asta o singura data
        aux += c;
    }

    linie = aux;
    return true;
}

void citeste_expresii_din_fisier(std::vector<std::string> &expresii) {
    std::ifstream fin("sd/input/expresii.txt");

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

float calculeaza_rpn(const std::vector<std::string> &polish) {
    std::stack<float> stiva;

    for (std::string s : polish) {
        if (s == " ") {
            continue;
        }

        if (isdigit(s[0])) {
            stiva.push(std::stof(s));
        }
        else {
            float b = stiva.top();
            stiva.pop();
            float a = stiva.top();
            stiva.pop();

            if (s == "+") {
                stiva.push(a + b);
            }
            else if (s == "-") {
                stiva.push(a - b);
            }
            else if (s == "*") {
                stiva.push(a * b);
            }
            else if (s == "/") {
                stiva.push(a / b);
            }
            else if (s == "^") {
                stiva.push(std::pow(a, b));
            }
        }
    }

    return stiva.top();
}

// incomplet -> trateaza `+++` ca fiind valid
void determinare_rpn(std::string linie) {
    // string ca sa putem stoca mai multe caractere -> ne ajuta cu formare de numere
    std::stack<char>         op_stack;
    std::vector<std::string> polish;

    std::string number = "";
    for (int i = 0; i < linie.size(); i++) {
        // regula folosita pentru conversie din char in str
        if ('0' <= linie[i] && linie[i] <= '9') {
            number += linie[i];
            continue;
        }
        else if (number != "") {
            polish.push_back(number);
            polish.push_back(" ");
            number = "";
        }

        char c = linie[i];
        // https://stackoverflow.com/questions/17201590/how-can-i-create-a-string-from-a-single-character#comment83182095_17201751
        std::string aux = "";

        if (c == '(') {
            op_stack.push(c);
        }
        else if (c == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                polish.push_back(aux + op_stack.top());
                op_stack.pop();
                polish.push_back(" ");
            }

            if (op_stack.empty()) {
                std::cout << "eroare de parantezare!\n";
                return;
            }
            op_stack.pop();
        }
        else {
            while (!op_stack.empty() && op_stack.top() != '(' && prioritate(op_stack.top()) >= prioritate(c)) {
                polish.push_back(aux + op_stack.top());
                op_stack.pop();
                polish.push_back(" ");
            }
            op_stack.push(c);
        }
    }

    // fix pentru problema in care nu adauga ultimul numar
    if (number != "") {
        polish.push_back(number);
        polish.push_back(" ");
    }

    while (!op_stack.empty()) {
        std::string aux = "";
        if (op_stack.top() == '(') {
            std::cout << "eroare de parantezare!\n";
            return;
        }
        polish.push_back(aux + op_stack.top());
        op_stack.pop();
        polish.push_back(" ");
    }

    std::cout << "expresie corecta, forma poloneza: ";
    for (std::string s : polish) {
        std::cout << s;
    }

    std::cout << "\nrezultat: " << calculeaza_rpn(polish) << '\n';
}

int main() {
    std::vector<std::string> expresii;
    citeste_expresii_din_fisier(expresii);

    for (auto item : expresii) {
        std::cout << item << '\n';
        determinare_rpn(item);
    }

    return 0;
}