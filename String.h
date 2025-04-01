#pragma once
class String {
private:
  char* line;
  int length; 

public: 
  String();
  String(const String& other);
  ~String();
  // get-set length
  void SetLength(int length);
  int GetLength() const;
  // 
  void Reserve();
  char* GetLine() const;
  void SetLine(char* line);
  void operator = (const String& other);
  bool operator == (const String& other) const;
};
