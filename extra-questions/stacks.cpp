#include <iostream>
using namespace std;

#define MAX 10

class Stack {
  private:
    int top;
    int arr[MAX];

  public:
    Stack() {
      top = -1;
    }

    bool push(int value) {
      if (top >= (MAX - 1)) {
        cout << "Stack overflow.." << endl;
        return false;
      } else {
        arr[++top] = value;
        return true;
      }
    }

    int pop() {
      if (top < 0) {
        cout << "Stack underflow" << endl;
        return -1;
      }

      int x = arr[top--];
      return x;
    }

    void display() {
      if (top < 0) {
        cout << "Stack is empty!" << endl;
        return;
      }

      for (int i = 0; i <= top; i++) {
        cout << arr[i] << endl;
      }
    }

    int peek() {
      if (top < 0) {
        cout << "Stack is empty" << endl;
        return -1;
      } 
              
      return arr[top];
    }
};

int main() {

  Stack stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  stack.push(50);
  stack.push(60);
  stack.push(70);
  stack.push(80);
  stack.push(90);
  stack.push(100);

  cout << "stack elements are: " << endl;
  stack.display();

  cout << "Pop: " << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;

  cout << "stack elements are: " << endl;
  stack.display();

  cout << "Peek: " << stack.peek() << endl;

  return 0;
}