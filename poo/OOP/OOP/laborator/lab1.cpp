/*
Sa se scrie un program c++ care sa permita lucrul cu numere complexe: z = a+bi = (a,b)
cu a si b
nr reale.
Programul trebuie sa permita:
1. afisarea unui numar complex in forma de pereche ordonata sau forma algebrica;
2. calculul modulului numarului complex ( |z| = sqrt ( a^2 + b^2))
3. Determinarea conjugatului numarului complex ( conj(z) = a-bi)
4. operatiile aritmetice cu numere complexe ( adunare, scadere, inmultire, impartire)
z1 = a1 + b1i; z2=a2 + b2i
z1 + z2 = (a1+a2) + (b1+b2)i;
z1 - z2 = (a1-a2) + (b1-b2)i;
5. 5+4i - 7;
*/
#include <iostream>
#include <cmath>
struct Complex
{
    float a, b; // descriu starea obiectului
    // metodele descriu comportamenul obiectului
    void afisarePer()
    {
        std::cout << "(" << a << ";" << b << ")"; // a si b vor fi atributele obiectului care apeleaza metoda
    }
    void afisareFA()
    {
        std::cout << a;
        if (b > 0)
        {
            std::cout << "+" << b << "i";
        }
        else if (b < 0)
        {
            std::cout << b << "i";
        }
    }
    float modul()
    {
        return sqrt(a * a + b * b);
    }
    Complex conjugat()
    {
        return Complex{a, -b};
    }
    Complex aduna(Complex z2)
    {
        return Complex{a + z2.a, b + z2.b};
    }
    Complex scade(Complex z2)
    {
        return Complex{a - z2.a, b - z2.b};
    }
    /*
    supraincarcarea operatorilor poate fi facuta pentru a imbunatati lizibilitatea codului
    -> extinderea functionalitatii unui operator astfel incat sa poata fi folosit si pentru
    tipuri de date noi;
    */
    // supraincarcare in struct
    Complex operator+(Complex z2)
    {
        return Complex{a + z2.a, b + z2.b};
    }
    Complex operator+(float r)
    {
        return Complex{a + r, b};
    }
    /* pentru orice metoda (supraincarcare de op) scrisa intr-o clasa sau struc, la
    compilare se transmite ca si parametru,
    in mod implicit, obiectul curent ( obiectul care apeleaza metoda) - ca si prim
    parametru
    DIn acest motiv nu putem avea acelasi operator supraincarcat ca membru al
    clasei si in afara ei, daca tipurile parametrilor sunt la fel */
    Complex operator-(Complex z2)
    {
        return Complex{a - z2.a, b - z2.b};
    }
    Complex operator-(float r)
    {
        return Complex{a - r, b};
    }
    bool operator==(Complex z1)
    {
        return (a == z1.a && b == z1.b);
    }
};
void afisarePer(Complex c)
{
    std::cout << "(" << c.a << ";" << c.b << ")";
}
Complex aduna(Complex c1, Complex c2)
{
    return Complex{c1.a + c2.a, c1.b + c2.b};
}
Complex scade(Complex c1, Complex c2)
{
    return Complex{c1.a - c2.a, c1.b - c2.b};
}
// supraincarcarea op in afara struct/clasei
// Complex operator + (Complex c1, Complex c2)
//{
// return Complex{c1.a + c2.a, c1.b + c2.b};
//}
// Complex operator - (Complex c1, Complex c2)
//{
// return Complex{c1.a - c2.a, c1.b - c2.b};
//}
Complex operator-(float r, Complex z)
{
    return Complex{r - z.a, -z.b};
}
int main()
{
    Complex c = {3, -4}, z = {2, 3};
    c.afisareFA();
    std::cout << "\n";
    std::cout << c.modul() << "\n";
    // Complex conj_c = c.conjugat();
    // conj_c.afisareFA();
    c.conjugat().afisareFA();
    std::cout << "\n";
    std::cout << "Adunarea nr complexe: \n";
    aduna(c, z).afisareFA();
    std::cout << "\n";
    z.aduna(c).afisareFA();
    std::cout << "\n";
    Complex z1 = {1, -1}, z2 = {2.5, 4};
    // z1+z2+c+z
    z1.aduna(z2.aduna(c.aduna(z))).afisareFA();
    std::cout << "\n";
    (z1 + z2 + c + z).afisareFA();
    std::cout << "\n";
    // c-z1-z2+z
    // z+ c - (z1 + z2 )
    z.aduna(c.scade(z1.aduna(z2))).afisareFA();
    std::cout << "\n";
    // z1+z2
    (z1 + z2).afisareFA();
    std::cout << "\n";
    (z1 + 7).afisareFA();
    std::cout << "\n";
    (z1 - 7).afisareFA();
    std::cout << "\n";
    (7 - z1).afisareFA();
    std::cout << "\n";
    if (z1 == z2)
        std::cout << "numere egale \n";
    else
        std::cout << "numere diferite \n";
    return 0;
}