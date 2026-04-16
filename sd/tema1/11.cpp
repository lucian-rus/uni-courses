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

void expresie_valida(std::string &linie) {
    std::string aux = "";
    for (char c : linie) {
        if (c == ' ' || c == '\t') {
            continue;
        }
        // scapam de caracterele albe acum, astfel facem parcurgerea asta o singura data
        aux += c;
    }

    linie = aux;
}

void citeste_expresii_din_fisier(std::vector<std::string> &expresii) {
    std::ifstream fin("sd/input/expresii2.txt");

    std::string linie;
    while (std::getline(fin, linie)) {
        expresie_valida(linie);
        expresii.push_back(linie);
    }

    fin.close();
}

void determinare_rpn(std::string linie, std::vector<char> &polish) {
    std::stack<char> op_stack;

    for (int i = 0; i < linie.size(); i++) {
        char c = linie[i];

        // functie care verifica daca avem o cifra sau un numar
        if (isalnum(c)) {
            polish.push_back(c);
        }
        else if (c == '(') {
            // op_stack.push(c);
            continue;
        }
        else if (c == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                polish.push_back(op_stack.top());
                op_stack.pop();
            }
            if (!op_stack.empty())
                op_stack.pop();
        }
        else {
            while (!op_stack.empty() && prioritate(op_stack.top()) >= prioritate(c)) {
                polish.push_back(op_stack.top());
                op_stack.pop();
            }
            op_stack.push(c);
        }
    }

    while (!op_stack.empty()) {
        polish.push_back(op_stack.top());
        op_stack.pop();
    }

    // refacem ecuatia
    std::stack<std::pair<std::string, int>> op_stack_pair;
    for (char c : polish) {
        if (isalnum(c)) {
            op_stack_pair.push({std::string(1, c), 4});
        }
        else {
            // luam operanzii si prioritatea
            std::pair<std::string, int> dreapta = op_stack_pair.top();
            op_stack_pair.pop();
            std::pair<std::string, int> stanga = op_stack_pair.top();
            op_stack_pair.pop();

            // vedem prioritatea curenta -> ne ajuta sa decidem daca avem nevoie de paranteze
            int curr_prio = prioritate(c);

            std::string stanga_str, dreapta_str;
            if (stanga.second < curr_prio) {
                stanga_str = "(" + stanga.first + ")";
            }
            else {
                stanga_str = stanga.first;
            }

            if (dreapta.second < curr_prio) {
                dreapta_str = "(" + dreapta.first + ")";
            }
            else {
                dreapta_str = dreapta.first;
            }

            op_stack_pair.push({stanga_str + c + dreapta_str, curr_prio});
        }
    }

    if (!op_stack_pair.empty()) {
        std::cout << op_stack_pair.top().first << '\n';
    }
}

int main() {
    std::vector<std::string> expresii;
    std::vector<char>        polish;

    citeste_expresii_din_fisier(expresii);
    for (auto item : expresii) {
        std::cout << item << '\n';
        determinare_rpn(item, polish);
    }

    return 0;
}