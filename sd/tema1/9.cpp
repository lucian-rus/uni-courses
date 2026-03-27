#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

typedef struct Node {
    int          key  = 0;
    struct Node *next = nullptr;
} Node_t;

typedef struct {
    Node_t *head    = nullptr;
    Node_t *tail    = nullptr;
    int     nr_elem = 0;

    void push(int elem) {
        Node_t *node = new Node_t;
        node->key    = elem;
        node->next   = nullptr;

        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail       = node;
        }

        nr_elem++;
    }

    void pop(void) {
        if (head == nullptr) {
            return;
        }

        Node_t *aux = head;
        head        = head->next;

        delete aux;
        nr_elem--;

        if (head == nullptr) {
            tail = head;
        }
    }

    int front(void) {
        if (head != nullptr) {
            return head->key;
        }

        return 0;
    }

    int back(void) {
        if (tail != nullptr) {
            return tail->key;
        }

        return 0;
    }

    bool empty(void) {
        // daca head = null, lista este goala
        return (head == nullptr);
    }

    void clear(void) {
        while (nr_elem != 0) {
            pop();
        }
    }

    int size(void) {
        return nr_elem;
    }

    // pt debug
    void print(void) {
        Node_t *node = head;

        while (node != nullptr) {
            std::cout << node->key << ' ';
            node = node->next;
        }

        std::cout << '\n';
    }

} Queue_t;

void testare_coada(void) {
    Queue_t q;
    q.push(6);
    q.push(2);
    q.push(4);
    q.push(8);

    q.print();

    while (q.size() != 0) {
        std::cout << "popping\n";
        q.pop();
        q.print();
    }
}

void citire_date_fisier(int &n, int &t, std::vector<std::string> &candidati) {
    std::ifstream fin("sd/input/candidati.txt");

    fin >> t >> n;
    for (int i = 0; i < n; i++) {
        std::string aux;
        fin >> aux;
        candidati.push_back(aux);
    }

    fin.close();
}

void scriere_date_in_fisier(const int &idx, const int &n, const std::vector<std::string> &candidati) {
    std::ofstream fout("output.txt");
    fout << "candidati pentru maine:\n";
    for (int i = idx; i < n; i++) {
        fout << candidati[i] << '\n';
    }

    fout.close();
}

int main() {
    int n, t;
    // queue-ul a fost implementat pe baza unui int
    // ca sa nu mai facem modificari la el, stocam indecsii elementelor din vector
    // o sa folosim ambele structuri de date in paralel, chiar daca nu e neaparat eficient dpdv al memoriei
    Queue_t q;

    // citim candidatii si generam queue-ul de indecsi
    std::vector<std::string> candidati;
    citire_date_fisier(n, t, candidati);
    for (int i = 0; i < n; i++) {
        q.push(i);
    }

    // generam vectorul de timpi. maparea e 1 la 1 -> candidatului cu index `i` i se atribuie timpul cu valoarea prezenta la
    // indexul `i` din vectorul `timpi`
    std::vector<int> timpi;
    for (int i = 0; i < n; i++) {
        // pentru un nr. random intre 15 si 25, generam un nr. random, luam restul impartirii lui la 10 si adunam cu 15
        timpi.push_back(15 + (rand() % 10));

        std::cout << candidati[i] << " are " << timpi[i] << " minute\n";
    }

    int timp_max    = 60 * t;
    int timp_curent = 0;
    while(q.empty() == false) {
        // luam index candidat
        int idx = q.front();
        std::cout << "lui " << candidati[idx] << " i-au fost alocate " << timpi[idx] << " minute\n";

        // cumulam timpul scurs
        timp_curent += timpi[idx];
        if(timp_curent > timp_max) {
            std::cout << "\nnu ne-a mai ramas timp! oprim examinarea si continuam maine\n";
            std::cout << "examenul continua de la " << candidati[idx] << '\n';
            break;
        }

        std::cout << "> au mai ramas " << timp_max - timp_curent << '\n';
        // scoatem candidatul
        q.pop();
    }

    // idx = n - cati candidati au mai ramas in queue
    scriere_date_in_fisier(n - q.size(), n, candidati);

    return 0;
}