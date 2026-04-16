#include <array>
#include <iostream>
#include <vector>

#define BLOCK_SIZE    8
#define LAST_ELEM_IDX (BLOCK_SIZE - 1)

// https://www.geeksforgeeks.org/cpp/vector-of-arrays-in-cpp/
typedef struct Deque {
    int head_adr = (BLOCK_SIZE / 2);
    int tail_adr = (BLOCK_SIZE / 2) - 1;

    int item_count = 0;

    // blocuri de date
    std::vector<std::array<int, BLOCK_SIZE>> blocks = {
        std::array<int, BLOCK_SIZE>{0, 0, 0, 0, 0, 0, 0, 0},
    };

    void push_front(int value) {
        // constant 0
        blocks[0][head_adr] = value;

        head_adr--;
        if (head_adr == -1) {
            blocks.insert(blocks.begin(), std::array<int, BLOCK_SIZE>{0, 0, 0, 0, 0, 0, 0, 0});
            head_adr = LAST_ELEM_IDX;
        }

        item_count++;
    }

    void push_back(int value) {
        // trebuie computat index-ul ultimului bloc
        int block_idx = blocks.size() - 1;

        blocks[block_idx][tail_adr] = value;

        tail_adr++;
        item_count++;

        if (tail_adr == BLOCK_SIZE) {
            blocks.push_back(std::array<int, BLOCK_SIZE>{0, 0, 0, 0, 0, 0, 0, 0});
            tail_adr = 0;
        }
    }

    int at(int index) {
        // eroare
        if (index >= item_count) {
            return -1;
        }

        // offset de 1 pentru head_adr
        int pozitie = head_adr + 1 + index;

        int block_idx = pozitie / BLOCK_SIZE;
        int array_idx = pozitie % BLOCK_SIZE;

        std::cout << block_idx << ' ' << array_idx << ' ';
        return blocks[block_idx][array_idx];
    }

    void pop_front(void) {
        head_adr++;

        if (head_adr == BLOCK_SIZE) {
            if (blocks.size() > 1) {
                blocks.erase(blocks.begin());
            }
            head_adr = 0;
        }

        blocks[0][head_adr] = 0;
        item_count--;
    }

    void pop_back(void) {
        tail_adr--;

        if (tail_adr == -1) {
            if (blocks.size() > 1) {
                blocks.pop_back();
            }
            tail_adr = LAST_ELEM_IDX;
        }

        blocks[blocks.size() - 1][tail_adr] = 0;
        item_count--;
    }

    int size(void) {
        return item_count;
    }

    void empty(void) {
        // resetam tot
        item_count = 0;
        tail_adr   = (BLOCK_SIZE / 2);
        head_adr   = (BLOCK_SIZE / 2) - 1;

        // ramanem doar cu doua blocuri
        while (blocks.size() > 1) {
            blocks.pop_back();
        }

        // curatam blocurile ramase
        for (auto bl : blocks) {
            for (auto it : bl) {
                it = 0;
            }
        }
    }

    void print(void) {
        std::cout << "numar total elem: " << item_count << '\n';
        for (int bl_idx = 0; bl_idx < blocks.size(); bl_idx++) {
            int idx  = 0;
            int size = BLOCK_SIZE;

            if (bl_idx == 0) {
                // eliminam offset-ul creat la adaugarea unui elem nou
                idx = head_adr + 1;
            }

            if (bl_idx == blocks.size() - 1) {
                size = (tail_adr % BLOCK_SIZE);
            }

            for (idx; idx < size; idx++) {
                std::cout << blocks[bl_idx][idx] << ' ';
            }
            std::cout << '\n';
        }
    }

} Deque_t;

int main(void) {
    Deque_t deq;

    deq.push_front(-1);
    deq.push_front(-2);
    deq.push_front(-3);
    deq.push_front(-4);
    deq.push_front(-5);
    deq.push_front(-6);
    deq.push_front(-7);
    deq.push_front(-8);

    deq.push_front(-9);
    deq.push_front(-10);

    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);
    deq.push_back(6);
    deq.push_back(7);
    deq.push_back(8);

    deq.push_back(9);
    deq.push_back(10);
    deq.print();

    deq.pop_front();
    deq.pop_front();
    deq.pop_front();

    deq.pop_back();
    deq.pop_back();
    deq.pop_back();
    deq.print();

    return 0;
}