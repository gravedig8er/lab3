#pragma once
#include "String.h"

class List {
private: 
  
  class Node {
  public:
    String string; // информация
    Node* pNext; 

    Node();
    ~Node();
  };

  int size; // размер списка
  Node* head; // указатель на начало списка

public: 
  List();
  ~List();
  void GetLength() const;
  int SetLength(int size);
};