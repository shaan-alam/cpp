/**
 * @file prog15.cpp
 * @brief WAP to convert infix expression to postfix expression
 * @date 07-09-2022
 */

#include <bits/stdc++.h>
using namespace std;

int getPrecedence(char x) {
  if (x == '^') {
    return 3;
  } else if (x == '*' || x == '/') {
    return 2;
  } else if (x == '+' || x == '-') {
    return 1;
  }

  return -1;
}

bool isOperand(char x) {
  return x >= '0' && x <= '9' || x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z';
}

string convertToPostfix(string infix) {
  string result = "";
  stack<char> stk;

  for (int i = 0; i < infix.length(); i++) {
    char ch = infix[i];

    if (isOperand(ch)) {
      result += ch;
    } else if(ch == '(') {
      stk.push(ch);
    } else if (ch == ')') {
      while (stk.top() != '(') {
        result += stk.top();
        stk.pop();
      }
      stk.pop();
    } else {
      while (!stk.empty() && getPrecedence(ch) <= getPrecedence(stk.top())) {
        result += stk.top();
        stk.pop();
      }
      stk.push(ch);
    }
  }

  while (!stk.empty()) {
    result += stk.top();
    stk.pop();
  }

  return result;
}

int main() {
  string infix;

  cout << "Enter the Infix expression: " << endl;
  cin >> infix;

  string postfix = convertToPostfix(infix);

  cout << "Infix Expression: " << infix << endl;
  cout << "Postfix Expression: " << postfix << endl;

  return 0;
}