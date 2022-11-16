using namespace std;

class Stack {
  private:
    char arr[500];
    int MAX = 500;
    int top;

  public:
    Stack() {
      this->top = -1;
    }

    void push(char value) {
      if (this->top == MAX - 1) {
        cout << "Stack overflow..." << endl;
        return;
      }

      this->arr[++this->top] = value;
    }

    char pop() {
      if (this->top != -1) {
        return this->arr[this->top--];
      }

      cout << "Stack underflow" << endl;
      return ' ';
    }

    char peek() {
      if (this->top != -1) {
        return this->arr[this->top];
      }

      cout << "Stack underflow" << endl;
      return ' ';
    }

    bool isEmpty() {
      return this->top < 0;
    }

    bool isFull() {
      return this->top == MAX - 1;
    }

    void display() {
      string str = "[";

      for (int i = 0; i <= top; i++) {
        str.push_back(arr[i]);
      }
      
      cout << str << "]" << endl;
    }
};
