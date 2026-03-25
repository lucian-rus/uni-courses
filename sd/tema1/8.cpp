#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef struct Node {
    int          key  = 0;
    struct Node *next = nullptr;
    struct Node *prev = nullptr;
} Node_t;

typedef struct {
    Node_t *head = nullptr;
    Node_t *tail = nullptr;

    void push_front(int key) {
        Node_t *node = new Node_t;
        node->key    = key;
        node->prev   = nullptr;
        node->next   = head;

        if (head != nullptr) {
            head->prev = node;
        }
        head = node;

        if (tail == nullptr) {
            tail = node;
        }
    };

    void push_back(int key) {
        Node_t *node = new Node_t;
        node->key    = key;
        node->prev   = tail;
        node->next   = nullptr;

        if (tail != nullptr) {
            tail->next = node;
        }
        tail = node;

        if (head == nullptr) {
            head = node;
        }
    };

    void pop_front(void) {
        if (size() == 0) {
            std::cout << "lista este goala!\n";
            return;
        }

        Node_t *aux = head;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head       = head->next;
            head->prev = nullptr;
        }

        delete aux;
    };

    void pop_back(void) {
        if (size() == 0) {
            std::cout << "lista este goala!\n";
            return;
        }

        Node_t *aux = tail;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail       = tail->prev;
            tail->next = nullptr;
        }

        delete aux;
    };

    Node_t *find(int key) {
        if (size() == 0) {
            std::cout << "lista este goala!\n";
            return nullptr;
        }

        Node_t *node = head;
        while (node != nullptr && node->key != key) {
            node = node->next;
        }

        return node;
    };

    void erase(Node_t *node) {
        if ((head == tail) && (head == node)) {
            head = nullptr;
            tail = nullptr;
        }
        else if (node == head) {
            head       = node->next;
            head->prev = nullptr;
        }
        else if (node == tail) {
            tail       = node->prev;
            tail->next = nullptr;
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
    };

    void remove(int key) {
        Node_t *node = head;
        while (node != nullptr) {
            Node_t *aux = node->next;
            if (node->key == key) {
                erase(node);
            }

            node = aux;
        }
    };

    void insert_after(int key1, int key2) {
        Node_t *node = find(key1);
        if (node == nullptr) {
            std::cout << "nu avem cheia data in lista!\n";
            return;
        }

        if (node == tail) {
            push_back(key2);
        }
        else {
            Node_t *newnode = new Node_t;
            newnode->key    = key2;

            newnode->next    = node->next;
            node->next->prev = newnode;
            node->next       = newnode;
            newnode->prev    = node;
        }
    };

    bool empty(void) {
        if (head == nullptr) {
            return true;
        }

        return false;
    };

    void clear(void) {
        while (head != nullptr) {
            pop_front();
        }
    };

    void print(void) {
        if (size() == 0) {
            std::cout << "lista este goala!\n";
            return;
        }

        std::cout << "continut lista: ";
        Node_t *curr = head;
        while (curr != nullptr) {
            std::cout << curr->key << ' ';
            curr = curr->next;
        }
        std::cout << '\n';
    };

    int size(void) {
        Node_t *curr = head;

        int size = 0;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }

        return size;
    };
} LinkedList_t;

bool palindrom(const LinkedList_t &ll) {
    Node_t *head = ll.head;
    Node_t *tail = ll.tail;

    // conditie aditionala pentru liste de lungime para
    while (head != tail && head->prev != tail) {
        if (head->key != tail->key) {
            return false;
        }

        head = head->next;
        tail = tail->prev;
    }

    return true;
}

bool compare(LinkedList_t &ll1, LinkedList_t &ll2) {
    if (ll1.size() != ll2.size()) {
        return false;
    }

    Node_t *ll1_node = ll1.head;
    Node_t *ll2_node = ll2.head;

    while (ll1_node != nullptr && ll2_node != nullptr) {
        if (ll1_node->key != ll2_node->key) {
            return false;
        }

        ll1_node = ll1_node->next;
        ll2_node = ll2_node->next;
    }

    return true;
}

// functie pentru a ne asigura ca nu folosim alti indecsi inafara de 1 si 2, lucru care ne-ar cauza un crash
int index_lista(int idx) {
    if (idx != 1 && idx != 2) {
        return 0;
    }

    return idx - 1;
}

bool meniu(const std::string &input, std::vector<LinkedList_t> &ll) {
    // stocam comenzile
    // un map ar fi mai eficient decat ce se face aici, dar ne folosim doar de structurile predate
    std::vector<std::string> commands = {
        "push_front", "push_back", "pop_front", "pop_back", "erase",     "remove",  "insert_after",
        "empty",      "clear",     "print",     "size",     "palindrom", "compare", "exit",
    };

    int idx = -1;
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == input) {
            idx = i;
            break;
        }
    }

    Node_t *node = nullptr;

    // doar trei variabile auxiliare. le folosim in toate situatiile
    int aux0, aux1, aux2;
    switch (idx) {
        case 0:
            std::cin >> aux2 >> aux0;
            ll[index_lista(aux2)].push_front(aux0);
            ll[index_lista(aux2)].print();
            break;

        case 1:
            std::cin >> aux2 >> aux0;
            ll[index_lista(aux2)].push_back(aux0);
            ll[index_lista(aux2)].print();
            break;

        case 2:
            ll[index_lista(aux2)].pop_front();
            ll[index_lista(aux2)].print();
            break;

        case 3:
            ll[index_lista(aux2)].pop_back();
            ll[index_lista(aux2)].print();
            break;

        case 4:
            std::cin >> aux2 >> aux0;
            node = ll[index_lista(aux2)].find(aux0);
            if (node != nullptr) {
                ll[index_lista(aux2)].erase(node);
            }
            ll[index_lista(aux2)].print();
            break;

        case 5:
            std::cin >> aux2 >> aux0;
            ll[index_lista(aux2)].remove(aux0);
            ll[index_lista(aux2)].print();
            break;

        case 6:
            std::cin >> aux2 >> aux0 >> aux1;
            ll[index_lista(aux2)].insert_after(aux0, aux1);
            ll[index_lista(aux2)].print();
            break;

        case 7:
            if (ll[index_lista(aux2)].empty()) {
                std::cout << "lista ll este goala\n";
            }
            else {
                std::cout << "lista ll NU este goala\n";
            }
            break;

        case 8:
            ll[index_lista(aux2)].clear();
            ll[index_lista(aux2)].print();
            break;

        case 9:
            ll[index_lista(aux2)].print();
            break;

        case 10:
            std::cout << "dimensiunea listei: " << ll[index_lista(aux2)].size() << '\n';
            break;

        case 11:
            std::cin >> aux2;
            if (palindrom(ll[index_lista(aux2)]) == true) {
                std::cout << "lista " << aux2 << " este palindrom!\n";
            }
            else {
                std::cout << "lista " << aux2 << " NU este palindrom!\n";
            }

            break;

        case 12:
            if (compare(ll[0], ll[1]) == true) {
                std::cout << "listele sunt egale!\n";
            }
            else {
                std::cout << "listele NU sunt egale!\n";
            }
            break;

        case 13:
            std::cout << "goodbye!\n";
            return false;

        default:
            std::cout << "comanda selectata este incorecta!\n";
            break;
    }

    if (node != nullptr) {
        delete node;
    }
    return true;
}

int main() {
    std::vector<LinkedList_t> ll;
    LinkedList_t              ll1;
    LinkedList_t              ll2;
    // punem doua liste in vector
    ll.push_back(ll1);
    ll.push_back(ll2);

    std::string command;
    bool        continua = true;
    while (continua) {
        std::cout << "> ";
        std::cin >> command;
        continua = meniu(command, ll);
    }

    return 0;
}