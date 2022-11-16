#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
  return x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x <= '9';
}

bool isOperator(char x)
{
  return x == '+' || x == '-' || x == '/' || x == '*';
}

bool check(string postfix)
{
  int operators = 0, operands = 0;
  string temp = "";

  for (int i = 0; postfix[i]; i++)
  {
    if (isdigit(postfix[i]))
    {
      temp = temp + postfix[i];
    }
    else if (postfix[i] == ' ' && isdigit(postfix[i - 1]))
    {
      temp = "";
      operands += 1;
    }
    else if (isOperator(postfix[i]))
    {
      operators++;
    }
  }

  if (operators >= operands)
  {
    return false;
  }
  else
  {
    return true;
  }
}

int stoin(string str) {
  int result = 0;
  for (int i = 0; i < str.length(); i++) {
    result = result * 10 + (str[i] - '0');
  }
  return result;
}

int evaluate(string postfix)
{
  stack<int> stk;
  string temp;

  for (int i = 0; postfix[i]; i++)
  {
    if (isdigit(postfix[i]))
    {
      temp = temp + postfix[i];
    }
    else if (postfix[i] == ' ' && isdigit(postfix[i - 1]))
    {
      stk.push(stoin(temp));
      temp = "";
    }
    else if (isOperator(postfix[i]))
    {
      int value1 = stk.top();
      stk.pop();
      int value2 = stk.top();
      stk.pop();

      switch (postfix[i])
      {
      case '+':
        stk.push(value2 + value1);
        break;
      case '-':
        stk.push(value2 - value1);
        break;
      case '*':
        stk.push(value2 * value1);
        break;
      case '/':
        stk.push(value2 / value1);
        break;
      }
    }
  }

  return stk.top();
}

int main()
{

  string expression = "15 20 +";
  if (check(expression))
  {
    cout << "OUTPUT: " << evaluate(expression) << endl;
  }
  else
  {
    cout << "invalid" << endl;
  }

  return 0;
}