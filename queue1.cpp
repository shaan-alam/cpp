#include <iostream>
using namespace std;

#define n 5

class Queue {
  private:
    int *arr;
    int front, back;

  public:
    Queue() {
      arr = new int[n];
      front = back = -1;
    }

    bool isFull() {
      return front == 0 && back == n - 1;
    }

    void enqueue(int value) {
      if (isFull()) {
        cout << "Queue is full" << endl;
        return;
      }

      back++;
      arr[back] = value;
      if (front == -1) front++;
    }

    int dequeue() {
      if (front == -1 || front > back) return -1;

      return arr[front++];
    }

    int peek() {
      if (front == -1 || front > back) return -1;

      return arr[front];
    }

    void display() {
      for (int i = front; i <= back; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
};

int main() {

  Queue q;

  q.enqueue(10);
  q.enqueue(20);
  q.dequeue();
  q.dequeue();
  q.dequeue();

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(10);

  q.display();

  return 0;
}