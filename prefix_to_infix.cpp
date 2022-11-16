#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x) {
  return x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x <= '9';
}

string convertToInfix(string prefix)
{
  string result = "";
  stack<string> stk;
  int i = prefix.size() - 1;

  while (prefix[i]) {
    if (isOperand(prefix[i])) {
      string op(1, prefix[i]);
      stk.push(op);
    } else {
      string a = stk.top();
      stk.pop();

      string b = stk.top();
      stk.pop();

      stk.push("(" + a + prefix[i] + b + ")");
    }
    i -= 1;
  }

  return stk.top();
}

int main() {

  string prefix = "/+LM/NX";
  string infix = convertToInfix(prefix);

  cout << "Prefix expression: " << prefix << endl;
  cout << "Infix expression: " << infix << endl;
  

  return 0;
}