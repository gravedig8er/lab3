#pragma once
#include "String.h"

class List {
public: 
  
  class Node {
  public:
    String string; // информация
    Node* pNext; 

    Node();
    Node(String string = String(), Node* pNext = nullptr);
    ~Node();
  };

private:
  int size; // размер списка
  Node* head; // указатель на начало списка

public: 
  List();
  ~List();
  int GetSize() const;
  void SetSize(int size);
  void push_back(const String string);
  Node* GetHead() const; 
  void SetHead(Node* pNext);
  void clear();
  void erase(int index);
  void unique(); 
};