#include <iostream>
#include "headers/Arrays.h"
using namespace std;

class CQueue {
  int *arr;
  int front;
  int back;

  public:
    CQueue() {
      arr = new int[5];
      front = back = -1;
    }

    void push(int x) {
      if (isFull()) {
        cout << "Queue full" << endl;
        return;
      } else if (isEmpty()) {
        front = back = 0;
        arr[back] = x;
      } else {
        back = (back + 1) % 5;
        arr[back] = x;
      }
    }

    int dequeue() {
      if (isEmpty()) {
        cout << "Queue empty" << endl;
        return -1;
      } else if (back == front) {
        int x = arr[back];
        front = back = -1;
        return x;
      } else {
        int x = arr[front];
        front = (front + 1) % 5;
        return x;
      }
    }

    bool isEmpty() {
      return front == -1 && back == -1;
    }

    bool isFull() {
      return (back + 1) % 5 == front;
    }
};

int main() {
  CQueue q;

  q.push(10);
  q.push(10);
  q.push(10);
  q.push(10);
  q.push(10);

  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;

  return 0;
}