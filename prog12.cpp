/**
 * @file prog12.cpp
 * @brief Implementing Stack functions in a menu-driven manner.
 * @date 31-08-2022
 */

#include <iostream>
#include <iomanip>
#include "headers/Arrays.h"
using namespace std;

class Stack {
  private:
    int arr[10];
    int MAX;
    int top;

  public:
    Stack(int size) {
      this->arr[size];
      this->MAX = size;
      this->top = -1;
    }

    void push(int value) {
      if (this->top == MAX - 1) {
        cout << "Stack overflow..." << endl;
        return;
      }

      this->arr[++this->top] = value;
    }

    int pop() {
      if (this->top != -1) {
        return this->arr[this->top--];
      }

      cout << "Stack underflow" << endl;
      return -1;
    }

    int peek() {
      if (this->top != -1) {
        return this->arr[this->top];
      }

      cout << "Stack underflow" << endl;
      return -1;
    }

    bool isEmpty() {
      return this->top < 0;
    }

    bool isFull() {
      return this->top == MAX - 1;
    }

    void display() {
      string str = "[";

      for (int i = this->top; i >= 0; i--) {
        if (i != 0) {
          str += to_string(arr[i]) + ", ";
        } else {
          str += to_string(arr[i]);
        }
      }
      
      cout << str << "]" << endl;
    }
};

void displayCurrentState(Stack stk) {
  cout << "=======================================================" << endl;
  cout << setw(30) << "CURRENT STACK STATE: ";
  stk.display();
  cout << "=======================================================" << endl;
}

int main() {
  
  int size;
  cout << "Enter the size of the stack: " << endl;
  cin >> size;

  // Creating a stack of size "size"
  Stack stk(size);

  system("clear");

  while(1) {
    
    displayCurrentState(stk);

    cout << setw(20) << "\nMENU" << endl;
    cout << "1. Push: " << endl;
    cout << "2. Pop: " << endl;
    cout << "3. Peek: " << endl;
    cout << "4. Check If Empty: " << endl;
    cout << "5. Check If Full: " << endl;
    cout << "6. Display Stack Elements: " << endl;
  
    int choice, value;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    switch(choice) {
      case 1:
        cout << "Enter the value: ";
        cin >> value;

        if (!stk.isFull()) {
          stk.push(value);
        }
        else {
          cout << "Stack Overflow...." << endl;
          getchar();
          getchar();
        }
        system("clear");

        break;
      
      case 2:
        if (!stk.isEmpty()) {
          cout << "Top element: " << stk.pop() << endl;
          cout << "NEW STACK STATE: ";
          stk.display();
        } else {
          cout << "Stack is empty!!" << endl;
        }
        getchar();
        getchar();
        system("clear");
        break;
      
      case 3:
        if (!stk.isEmpty()) {
          cout << "Top element: " << stk.peek() << endl;
        } else {
          cout << "Stack is empty!!" << endl;
        }
        getchar();
        getchar();
        system("clear");
        break;
      
      case 4:
        if (stk.isEmpty()) {
          cout << "Stack is Empty" << endl;
        } else {
          cout << "Stack is not Empty" << endl;
        }
        getchar();
        getchar();
        system("clear");
        break;
      case 5:
        if (stk.isFull()) {
          cout << "Stack is Full" << endl;
        } else {
          cout << "Stack is not Full" << endl;
        }
        getchar();
        getchar();
        system("clear");
        break;
      case 6:
        if (!stk.isEmpty()) {
          cout << "Stack elements are: " << endl;
          stk.display();
        } else {
          cout << "Stack is currently empty!" << endl;
        }

        getchar();
        getchar();

        system("clear");
        break;
      default: {
        cout << "Wrong choice..." << endl;
        getchar();
        getchar();
        system("clear");
      }
    }
  }
  
  return 0;
}