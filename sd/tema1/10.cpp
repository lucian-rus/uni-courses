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

// incomplet -> trateaza `+++` ca fiind valid
void determinare_rpn(std::string linie) {
    std::stack<char>  op_stack;
    std::vector<char> polish;

    for (char c : linie) {
        if ('0' <= c && c <= '9') {
            polish.push_back(c);
            polish.push_back(' ');
            continue;
        }

        if (c == '(') {
            op_stack.push(c);
        }
        else if (c == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                polish.push_back(op_stack.top());
                op_stack.pop();
                polish.push_back(' ');
            }

            if (op_stack.empty()) {
                std::cout << "eroare de parantezare!\n";
                return;
            }
            op_stack.pop();
        }
        else {
            while (!op_stack.empty() && op_stack.top() != '(' && prioritate(op_stack.top()) >= prioritate(c)) {
                polish.push_back(op_stack.top());
                op_stack.pop();
                polish.push_back(' ');
            }
            op_stack.push(c);
        }
    }

    while (!op_stack.empty()) {
        if (op_stack.top() == '(') {
            std::cout << "eroare de parantezare!\n";
            return;
        }
        polish.push_back(op_stack.top());
        op_stack.pop();
        polish.push_back(' ');
    }

    for (char c : polish) {
        std::cout << c;
    }
    std::cout << '\n';
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