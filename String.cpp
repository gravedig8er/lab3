#include "String.h"

String::String(): line{nullptr} ,length{0} {}

String::~String() {
  if (line) delete[] line; 
}

void String::SetLength(int length) {
  this->length = length;
}

int String::GetLength() const{
  return length;
}

void String::Reserve() {
  line = new char[length];
}

char* String::GetLine() const{
  return line;
}
