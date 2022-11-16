#include <iostream>
using namespace std;

#define size 5

class Queue {
  int *arr;
  int front, back;

  public: 
    Queue() {
      arr = new int[size];
      front = back = -1;
    }

    void push(int x) {
      if (isFull()) {
        cout << "Queue is full" << endl;
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
        cout << "Queue is empty" << endl;
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
      return (back + 1) % size == front;
    }

    void display() {
      int f = front, b = back;
      if (f > b) {
        while(f <= size - 1) {
          cout << arr[f] << " ";
          f++;
        }
        f = 0;
        while (f <= b) {
          cout << arr[f] << " ";
          f++;
        }
      } else {
        while (f <= b) {
          cout << arr[f] << " ";
          f++;
        }
      }
    }
};


int main() {

  Queue q;
  q.push(10);
  q.push(20);
  q.push(30);

  q.push(40);
  q.push(50);
  q.dequeue();
  q.push(60);

  q.display();

}