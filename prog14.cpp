/**
 * @file prog14.cpp
 * @brief Check if string is palindrome using stacks
 * @date 01-09-2022
*/
#include <iostream>
using namespace std;

class Stack {
  private:
    char arr[500];
    int max;
    int top;
  
  public: 
    Stack(int size) {
      this->arr[size];
      this->max = size;
      this->top = -1;
    }

    void push(char x) {
      if (this->top == this->max - 1) {
        cout << "Stack overflow..." << endl;
        return;
      }

      this->arr[++this->top] = x;
    }

    char pop() {
      if (this->top < 0) {
        cout << "Stack underflow.." << endl;
        return ' ';
      }

      return this->arr[this->top--];
    }
};

int main() {
  string originalString, reverseString = "";

  cout << "Enter the string: " << endl;
  getline(cin, originalString);

  Stack stk(originalString.size());

  // Pushing characters into the stack
  for (int i = 0; i < originalString.size(); i++) {
    stk.push(originalString[i]);
  } 
  
  // Popping out the characters from the stack
  for (int i = 0; i < originalString.size(); i++) {
    reverseString += stk.pop();
  }

  cout << "Original String: " << originalString << endl;
  cout << "Reverse String: " << reverseString << endl;

  if (originalString == reverseString) {
    cout << "The string is palindrome." << endl;
  } else {
    cout << "The string is not palindrome." << endl;
  }

  return 0;
}