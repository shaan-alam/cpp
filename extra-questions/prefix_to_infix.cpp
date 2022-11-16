#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isOperand(char x) {
  return x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x <= '9';
}

string convertToInfix(string prefix) {
  stack<string> s;  
  int i = prefix.size() - 1;

  while (prefix[i]) {
    if (isOperand(prefix[i])) {
      string op(1, prefix[i]);
      s.push(op);
    } else {
      string a = s.top();
      s.pop();

      string b = s.top();
      s.pop();

      s.push("(" + a + prefix[i] + b + ")");
    }
    i -= 1;
  }

  return s.top();
}

int main() {
  
  string prefix = "/+LM/NX";
  string infix = convertToInfix(prefix);

  cout << "Prefix expression: " << prefix << endl;
  cout << "Infix expression: " << infix << endl;

  return 0;
}