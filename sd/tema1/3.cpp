#include <iostream>
#include <stack>
#include <string>
#include <vector>

// exemple:
// ()[]{[()]}       - valid
// [()()]           - valid
// ([])             - invalid 
// [{}()]           - invalid
// ()[{}]{[()]}     - invalid

int main() {
    bool valid = true;

    // improvizatie -> folosim doi vectori cu rol de "map", pentru a putea respecta precedenta parantezelor {[()]}
    // ca sa nu folosim un map conventional sau array-uri alocate static, folosim un vector al carui size ne
    // va da numarul de paranteze rotunde sau patrate deschise la orice moment dat.
    // nu stocam numarul de acolade deschise deoarece nu avem nevoie, acolada avand cea mai mare precedenta
    std::vector<char> rotunda;
    std::vector<char> patrata;

    std::stack<char> paranteze;

    std::string input = "()[{}]{[()]}";
    for (char c : input) {
        // verificam precedenta in momentul adaugarii in stiva
        // daca precedenta e incalcata, ne oprim aici
        // daca precedenta nu e incalcata, incrementam size-ul vectorului, in functie de tipul de paranteza
        if (c == '(') {
            paranteze.push(c);
            rotunda.push_back(c);
            continue;
        }

        if (c == '[') {
            if (rotunda.size() != 0) {
                valid = false;
                break;
            }

            paranteze.push(c);
            patrata.push_back(c);
            continue;
        }

        if (c == '{') {
            if (patrata.size() != 0) {
                valid = false;
                break;
            }
            paranteze.push(c);
            continue;
        }

        // daca trecem de faza de adaugare, putem sa dam pop

        // daca size-ul stivei e deja 0, oprim si iesim
        if (paranteze.size() == 0) {
            valid = false;
            break;
        }

        // verificam elementul cel mai de sus din stiva potriveste cu elementul curent
        // tratam si precedenta
        if (c == ')' && paranteze.top() == '(') {
            paranteze.pop();
            rotunda.pop_back();
        }
        else if (c == ']' && paranteze.top() == '[') {
            paranteze.pop();
            patrata.pop_back();
        }
        else if (c == '}' && paranteze.top() == '{') {
            paranteze.pop();
        }
        else {
            valid = false;
            break;
        }
    }

    if (valid == false || paranteze.size() != 0) {
        std::cout << "setul de paranteze NU este valid\n";
    }
    else {
        std::cout << "setul de paranteze este valid\n";
    }

    return 0;
}