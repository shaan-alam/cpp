#include <iostream>
#include "headers/Arrays.h"
using namespace std;

#define n 10

class Queue {
  int *arr;
  int front;
  int back;

  public: 
    Queue() {
      arr = new int[n];
      front = -1;
      back = -1;
    }

    void push(int x) {
      if (back == n - 1) {
        cout << "Queue Overflow" << endl;
        return;
      }

      back++;
      arr[back] = x;
      if (front == -1) front++;
    }

    int pop() {
      if (front == -1 || front > back) return -1;

      return arr[front++];
    }

    int peek() {
      if (front == -1 || front > back)
        return -1;
      
      return arr[front];
    }

    bool isEmpty() {
      if (front == -1 || front > back) return true;

      return false;
    }
};

int main() {
  
  Queue q;
  q.push(10);
  q.push(10);
  q.push(10);
  q.push(10);

  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;

  return 0;
}