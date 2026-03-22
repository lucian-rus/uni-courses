#include <iostream>
#include <stack>
#include <string>

// exemple:
// ()[]{[()]}       - valid
// [()()]           - valid
// ([])             - invalid
// [{}()]           - invalid
// ()[{}]{[()]}     - invalid

int main() {
    std::stack<char> s;
    std::string      input = "()[(){}]{[()]}";
    bool             valid = true;

    for (char c : input) {
        if (c == '(' || c == '[' || c == '{') {
            // verificam precedenta in momentul adaugarii in stiva
            // daca precedenta e incalcata, ne oprim aici
            // daca precedenta nu e incalcata, incrementam size-ul vectorului, in functie de tipul de paranteza
            if (!s.empty()) {
                // verificam paranteza precedenta. conditionam corectitudinea
                // () nu poate contine [] sau {} 
                // [] nu poate contine {}
                char prev = s.top();
                if ((prev == '(' && (c == '[' || c == '{')) || (prev == '[' && c == '{')) {
                    valid = false;
                    break;
                }
            }
            s.push(c);
        }
        else {
            // daca size-ul stivei e deja 0, oprim si iesim
            if (s.empty() || (c == ')' && s.top() != '(') || (c == ']' && s.top() != '[') || (c == '}' && s.top() != '{')) {
                valid = false;
                break;
            }
            s.pop();
        }
    }

    valid = valid && s.empty();

    if (valid) {
        std::cout << "setul de paranteze este valid\n";
    }
    else {
        std::cout << "setul de paranteze NU este valid\n";
    }

    return 0;
}