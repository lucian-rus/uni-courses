#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Document {

public:
    int id;
    std::string titlu;
    std::string autor;
    Document(int id, std::string titlu, std::string autor) : id(id), titlu(titlu), autor(autor) {}

    virtual ~Document() {}

    int get_id() const { return id; }
    void set_id(int i) { id = i; }

    std::string get_titlu() const { return titlu; }
    void set_titlu(std::string t) { titlu = t; }

    std::string get_autor() const { return autor; }
    void set_autor(std::string a) { autor = a; }

    virtual void genereaza_rezultat(std::ostream& os) const = 0;
};

class Factura : public Document {

public:
    std::string client;
    double sumaFaraTVA;
    double procentTVA;
    Factura(int id = 0, std::string titlu = "", std::string autor = "", std::string client = "", double sumaFaraTVA = 0, double procentTVA = 0)
        : Document(id, titlu, autor), client(client), sumaFaraTVA(sumaFaraTVA), procentTVA(procentTVA) {}

    std::string get_client() const { return client; }
    void set_client(std::string c) { client = c; }

    double get_sumaFaraTVA() const { return sumaFaraTVA; }
    void set_sumaFaraTVA(double sfa) { sumaFaraTVA = sfa; }

    double get_procentTVA() const { return procentTVA; }
    void set_procentTVA(double pt) { procentTVA = pt; }

    void genereaza_rezultat(std::ostream& os) const override {
        os << "factura: id=" << id << ", client=" << client << ", suma fara tva=" << sumaFaraTVA;
    }

    friend std::istream& operator>>(std::istream& is, Factura& f);
    friend std::ostream& operator<<(std::ostream& os, const Factura& f);
};

class Contract : public Document {

public:
    std::string beneficiar;
    double valoareContract;
    Contract(int id = 0, std::string titlu = "", std::string autor = "", std::string beneficiar = "", double valoareContract = 0)
        : Document(id, titlu, autor), beneficiar(beneficiar), valoareContract(valoareContract) {}

    std::string get_beneficiar() const { return beneficiar; }
    void set_beneficiar(std::string b) { beneficiar = b; }

    double get_valoareContract() const { return valoareContract; }
    void set_valoareContract(double vc) { valoareContract = vc; }

    void genereaza_rezultat(std::ostream& os) const override {
        std::cout << "contract: id=" << id << ", beneficiar=" << beneficiar << ", valoare contract=" << valoareContract;
    }

    friend std::istream& operator>>(std::istream& is, Contract& c);
    friend std::ostream& operator<<(std::ostream& os, const Contract& c);
};

std::istream& operator>>(std::istream& is, Factura& factura) {
    is >> factura.id >> factura.titlu >> factura.autor >> factura.client >> factura.sumaFaraTVA >> factura.procentTVA;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Factura& factura) {
    factura.genereaza_rezultat(os);
    return os;
}

std::istream& operator>>(std::istream& is, Contract& contract) {
    is >> contract.id >> contract.titlu >> contract.autor >> contract.beneficiar >> contract.valoareContract;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Contract& contract) {
    contract.genereaza_rezultat(os);
    return os;
}

class SistemGestiune {

public:
    std::vector<Document*> documente;
    SistemGestiune() {
        std::ifstream fin("documente.in");
        int n;
        fin >> n;
        for (int i = 0; i < n; ++i) {
            std::string tip;
            fin >> tip;
            if (tip == "factura") {
                Factura* f = new Factura();
                fin >> *f;
                documente.push_back(f);
            } else if (tip == "contract") {
                Contract* c = new Contract();
                fin >> *c;
                documente.push_back(c);
            }
        }
    }

    ~SistemGestiune() {
        for (Document* document : documente) {
            delete document;
        }
    }

    void descriere(std::ostream& os) const {
        for (const Document* document : documente) {
            document->genereaza_rezultat(os);
            std::cout << std::endl;
        }
    }

    // void aplica_reducere_facturi(double discount) {
    //     for (const Document* document : documente) {
    //     }
    // }
};

int main() {
    SistemGestiune sg;
    sg.descriere(std::cout);
    return 0;
}