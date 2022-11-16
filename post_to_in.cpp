#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x) {
  return x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x <= '9';
}

string findInfix(string postfix) {
  string result = "";
  int i = 0;

  stack<string> stk;

  while (postfix[i]) {
    char ch = postfix[i];
    if (isOperand(ch)) {
      string op(1, ch);
      stk.push(op);
    } else {
      string a = stk.top();
      stk.pop();

      string b = stk.top();
      stk.pop();

      stk.push("(" + b + ch + a + ")");
    }
    i += 1;
  }

  return stk.top();
}

int main() {

  string postfix;
  cout << "Enter postfix expression: " << endl;
  cin >> postfix;

  cout << "Infix expression: " << findInfix(postfix) << endl;


}