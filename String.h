#pragma once
class String {
private:
  char* line;
  int length; 
  
public: 
  String();
  ~String();
  // get-set length
  void SetLength(int length);
  int GetLength() const;
  // 
  void Reserve();
  char* GetLine() const;
};
