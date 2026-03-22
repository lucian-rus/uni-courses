#pragma once

class MyVector {
  public:
    MyVector(int capacity = 10);
    ~MyVector();

    void push_back(const int &item);
    int  size();
    void print();

  private:
    int  m_size;
    int  m_capacity;
    int *m_list;
};