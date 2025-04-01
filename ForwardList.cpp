#include "ForwardList.h"
#include "String.h"

List::List(): size{0}, head{nullptr} {}

List::~List() {
  clear();
}

int List::GetSize() const {
  return size;
}

void List::SetSize(int size) {
  this->size = size;
}

void List::push_back(const String string) {
  if (head == nullptr) head = new Node(string);
  else {
    Node* temp = head; 

    while (temp->pNext) temp = temp->pNext;

    temp->pNext = new Node(string);
  }
}

void List::erase(int index) {
  if (index < 0 || index >= size) return; // проверка границ

  if (index == 0) {
    Node* temp = head;
    head = head->pNext;
    delete temp;
  } 
  else {
    Node* prev = head;
    for (int i = 0; i < index - 1; ++i) {
        prev = prev->pNext;
    }

    Node* del = prev->pNext;
    prev->pNext = del->pNext;
    delete del;
  }
  size--; 
}

void List::unique() {
  if (head == nullptr) return;

  Node* temp = head;
  while (temp != nullptr && temp->pNext != nullptr) {
    Node* second = temp;

    while (second->pNext != nullptr) {
      if (temp->string == second->pNext->string) { 
        Node* del = second->pNext;

        second->pNext = del->pNext;
        delete del;
        size--;
      } 
      else {
        second = second->pNext;
      }
    }
    temp = temp->pNext;
  }
}

List::Node* List::GetHead() const {
  return this->head;
}

void List::SetHead(Node* pNext) {
  this->head = pNext;
}

void List::clear() {
  while (size) {
    Node* temp = head;
    head = temp->pNext;

    delete temp;
    size--;
  }
}