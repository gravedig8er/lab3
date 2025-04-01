#include "ForwardList.h"
#include "String.h"

List::Node::Node() {
  string.SetLine(nullptr);
  string.SetLength(0);
  pNext = nullptr;
}

List::Node::Node(String string, Node* pNext) {
  this->string = string; 
  this->pNext = pNext;
}

List::Node::~Node() {

}