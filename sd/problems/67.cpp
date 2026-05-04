#include <iostream>
#include <string>

std::string addBinary(std::string a, std::string b) {
    std::string st = "";

    if (a.size() < b.size()) {
        std::string aux = a;

        a = b;
        b = aux;
    }

    int atail     = a.size() - 1;
    int carryover = 0;
    for (int i = b.size() - 1; i >= 0; i--) {
        bool shalladd = false;
        if (a[atail] == '1' && b[i] == '1') {
            shalladd = true;
        }
        

        if (shalladd == true) {
            st = "1" + st;
        }

        std::cout << a << '\n';
        atail--;
    }

    return a;
}

int main(void) {

    std::string s1 = "1011";
    std::string s2 = "101";
    std::cout << addBinary(s1, s2) << '\n';
    return 0;
}