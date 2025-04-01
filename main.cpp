#include <iostream> 
#include <fstream> 
#include "ForwardList.h"
#include "String.h"
#include "MyFunctions.h"

int main() {
  List lst; // список из строк 
  std::fstream input, out; 
  out.open("out.txt", std::ios::out);
  if (!out.is_open()) return 0;
  lst.SetSize(GetFileSize(input)); // количество непустых строчек в файле
  if (lst.GetSize() == 0) {out << "empty list"; return 0;}

  int start = 0;
  for (int i = 0; i < lst.GetSize(); i++) {
    String temp; // строка хранит в себе \0 последним. 
    temp.SetLength(GetLineSize(input, start) + 1);
    temp.Reserve();

    Fill(input, temp, start);
    lst.push_back(temp);
  }

  out << "List before process!\n";
  out << "SIZE: " << lst.GetSize() << "\n\n";
  Print(out, lst);

  lst.unique();
  out << "\nList after process!\n";
  out << "SIZE: " << lst.GetSize() << "\n\n";
  Print(out, lst);

  input.close();
  out.close();
  return 0;
}
