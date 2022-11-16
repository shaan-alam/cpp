#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x) {
  return x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x <= '9';
}

string convertToInfix(string infix) {
  stack<string> s;

  string postfix = "";
  int i = 0;

  while (infix[i]) {
    if (isOperand(infix[i])) {
      string op(1, infix[i]);
      s.push(op);
    } else {
      string a = s.top();
      s.pop();
      
      string b = s.top();
      s.pop();

      string result = "(" + b + infix[i] + a + ")";
      s.push(result);
    }
    i++;
  }

  return s.top();
}

int main() {

  string postfix;

  cout << "Enter postfix expression: " << endl;
  cin >> postfix;

  string infix = convertToInfix(postfix);

  cout << "Postfix Expression: " << postfix << endl;
  cout << "Infix Expression: " << infix << endl;

  return 0;
}