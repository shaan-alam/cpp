#include <iostream>
#include "headers/Stacks.h"
#include <fstream>
using namespace std;

bool checkForBrackets(string brackets) {
  Stack stk;

  for (int i = 0; i < brackets.size(); i++) {
    char ch = brackets[i];
  
    if (!stk.isEmpty() && ((stk.peek() == '(' && ch == ')') || (stk.peek() == '{' && ch == '}') || (stk.peek() == '[' && ch == ']'))) {
      stk.pop();
    } else {
      stk.push(ch);
    }
    
  }

  return stk.isEmpty();
}

string extractBracketsFromFile(string fileName) {
  fstream file(fileName);
  string brackets = "";
  string text;  


  while (getline(file, text)) {
    for (int i = 0; i < text.size(); i++) {
      char ch = text[i];
      if (ch == '[' || ch == '{' || ch == '(' || ch == ')' || ch == '}' || ch == ']') {
        brackets.push_back(ch);
      }
    }
  }

  return brackets;
}

int main() {
  string brackets = extractBracketsFromFile("./prog12.cpp");

  cout << brackets << endl;

  if (!checkForBrackets(brackets)) {
    cout << "The file is unbalanced!!" << endl;
  } else {
    cout << "All Perfect!!" << endl;
  }

  
  
  return 0;
}