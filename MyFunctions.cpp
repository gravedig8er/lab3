#include <iostream> 
#include <fstream>
#include "String.h"
#include "MyFunctions.h"
#include "ForwardList.h"

int GetFileSize(std::fstream& input) {
  input.open("input.txt", std::ios::in);
  if (!input.is_open()) return 0;

  int counter = 0;
  char ch;
  bool flag = 0;

  while (input.get(ch)) {
    if (ch == '\n') {
      counter++;
      flag = 0; 
    } 
    else {
      flag = 1; 
    }
  }

  if (flag) {
    counter++;
  }

  input.clear();                 
  input.seekg(0); 
  
  return counter;
}

int GetLineSize(std::fstream& input, int& start) {
  input.seekg(start);
  int counter = 0;
  char ch; 

  while (input.get(ch) && !input.eof() && ch != '\r') {  
    if (ch == '\n') break; 
    counter++;
  }
  
  input.clear(); 
  return counter;
}


void Fill(std::fstream& input, String& string, int& start) {
  input.seekg(start);
  char* line = string.GetLine();
  char ch;

  for (int i = 0; i < string.GetLength() - 1; i++) { // заполнили строку
      input.get(ch);
      line[i] = ch;
  }
  start++; // пропустили символ
  // Обновляем `start` после заполнения строки
  start += string.GetLength();
}
void Print(std::fstream& out, List& lst) {
  int i = 0; 
  List::Node* temp = lst.GetHead();
  while (i < lst.GetSize()) {
    String string = temp->string;

    char* line = string.GetLine();
    for (int j = 0; j < string.GetLength(); j++) {
      out << line[j];
    }
    out << '\n';
    if (i != lst.GetSize() - 1) out << "    \\|/";
    else {out << "    \\|/\n"; out << "   null"; }
    out << '\n';
    temp = temp->pNext;
    i++;
  }
  out << '\n';
}