#pragma once
#include "ForwardList.h"
int GetFileSize(std::fstream& input);
int GetLineSize(std::fstream& input, int& start);
void Fill(std::fstream& input, String& string, int& start);
void Print(std::fstream& out, List& lst);