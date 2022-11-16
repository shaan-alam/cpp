#include <iostream>
using namespace std;

#define MAX 50

class Stack
{
private:
  char arr[MAX];
  int top;

public:
  Stack()
  {
    this->top = -1;
  }

  void push(char x)
  {
    if (this->top == MAX - 1)
    {
      cout << "Stack overflow" << endl;
      return;
    }

    this->arr[++this->top] = x;
  }

  char pop()
  {
    if (this->top == -1)
    {
      cout << "Stack underflow" << endl;
      return ' ';
    }

    return this->arr[this->top--];
  }

  char peek()
  {
    if (this->top == -1)
    {
      cout << "Stack underflow" << endl;
      return ' ';
    }

    return this->arr[this->top];
  }

  bool empty()
  {
    return this->top < 0;
  }
};

bool isOperand(char x)
{
  return x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x <= '9';
}

int getPrecedence(char x)
{
  if (x == '^')
  {
    return 3;
  }
  else if (x == '/' || x == '*')
  {
    return 2;
  }
  else if (x == '+' || x == '-')
  {
    return 1;
  }

  return -1;
}

string getPostfix(string infix)
{
  string result = "";

  Stack stk;

  for (int i = 0; i < infix.length(); i++)
  {
    char ch = infix[i];

    if (isOperand(ch))
    {
      result += ch;
    }
    else if (ch == '(')
    {
      stk.push(ch);
    }
    else if (ch == ')')
    {
      while (stk.peek() != '(')
      {
        result += stk.pop();
      }
      stk.pop();
    }
    else
    {
      if (ch == '^') {
        while (!stk.empty() && getPrecedence(ch) <= getPrecedence(stk.peek()))
        {
          result += stk.pop();
        }
      } else {
        while (!stk.empty() && getPrecedence(ch) < getPrecedence(stk.peek()))
        {
          result += stk.pop();
        }
      }
      stk.push(ch);
    }
  }

  while (!stk.empty())
  {
    result += stk.pop();
  }

  return result;
}

string reverse(string str) {
  string reverse = "";
  for (int i = str.length() - 1; i >= 0; i--) {
    if (str[i] == '(') {
      reverse += ')';
    } else if (str[i] == ')') {
      reverse += '(';
    } else {
      reverse += str[i];
    }
  }
  return reverse;
}

int main()
{

  string prefix;
  string infix = "";

  cout << "Enter infix expression: " << endl;
  getline(cin, prefix);

  prefix = reverse(prefix);
  prefix = getPostfix(prefix);
  infix = reverse(prefix);

  cout << "prefix expression: " << infix << endl;

  return 0;
}