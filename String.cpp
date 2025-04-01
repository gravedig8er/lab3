#include "String.h"

String::String(): line{nullptr} ,length{0} {}

String::String(const String& other) {
  this->length = other.length;
  this->line = new char[other.length];
  line[length - 1] = '\0';

  for (int i = 0; i < length - 1; i++) {
    this->line[i] = other.line[i];
  }
}

void String::operator = (const String& other) {
  this->length = other.length;

  if (this->line) delete[] this->line; 

  this->line = new char[other.length];
  line[length - 1] = '\0';

  for (int i = 0; i < other.length - 1; i++) {
    this->line[i] = other.line[i];
  }
}

bool String::operator==(const String& other) const {
  if (length != other.length) return false;

  for (int i = 0; i < length; ++i) {
    if (line[i] != other.line[i]) return false;
  }
  
  return true;
}

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
  line[length - 1] = '\0';
}

char* String::GetLine() const{
  return line;
}

void String::SetLine(char* line) {
  this->line = line;
}

