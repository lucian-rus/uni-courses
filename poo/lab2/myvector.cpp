#include <iostream>

// include class header
#include "myvector.h"

int main(void) {
    MyVector m;
    m.push_back(1);
    m.push_back(3);
    m.push_back(4);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(12);
    m.push_back(5);

    std::cout << "size: " << m.size() << '\n';
    m.print();

    return 0;
}

MyVector::MyVector(int capacity) {
    m_capacity = capacity;
    m_size     = 0;
    m_list     = new int[capacity];
}

MyVector::~MyVector() {
    delete[] m_list;
}

void MyVector::push_back(const int &item) {
    m_list[m_size] = item;
    m_size++;

    // if not needed to update capacity, return
    if (m_capacity > m_size) {
        return;
    }

    m_capacity = m_capacity * 2;
    int *aux   = new int[m_capacity];

    // copy
    for (int i = 0; i < m_size; i++) {
        aux[i] = m_list[i];
    }

    delete[] m_list;
    m_list = aux;
}

int MyVector::size() {
    return m_size;
}

void MyVector::print() {
    for (int i = 0; i < m_size; i++) {
        std::cout << m_list[i] << ' ';
    }
    std::cout << '\n';
}
