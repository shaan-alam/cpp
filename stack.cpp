#include <iostream>
using namespace std;

class Stack {
  private:
    int arr[100];
    int MAX;
    int top;

  public:
    Stack(int size) {
      this->arr[size];
      this->top = -1;
      this->MAX = size;
    }

    void push(int value) {
      if (this->top == this->MAX - 1) {
        cout << "Stack overflow!!" << endl;
        return;
      }

      this->arr[++this->top] = value;
    }

    int pop() {
      if (this->top == -1) {
        cout << "Stack underflow!!" << endl;
        return -1;
      }

      return this->arr[this->top--];
    }

    int peek() {
      if (this->top == -1) {
        cout << "Stack underflow!" << endl;
        return -1;
      }

      return this->arr[this->top];
    }

    void display() {
      for (int i = 0; i <= this->top; i++) {
        cout << this->arr[i] << endl;
      }
    }

    void clear() {
      this->top = -1;
    }
};

int main() {
  Stack stk(10);

  stk.push(10);
  stk.push(10);
  stk.push(10);
  stk.push(10);

  stk.display();

  return 0;
}