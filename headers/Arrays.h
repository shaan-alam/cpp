using namespace std;

class Arrays {    
  public:
    static void readArray(int arr[], int size) {
      for (int i = 0; i < size; i++) {
        cin >> arr[i];
      }
    }

    static void printArray(int arr[], int size) {
      for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
      }
    }

    static void sort(int arr[], int size) {
      for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - (i + 1); j++) {
          if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
          }
        }
      }
    }

    static bool isSorted(int arr[], int size) {
      int prev = arr[0];
      for (int i = 0; i < size; i++) {
        if (arr[i] > prev) return false;
      }

      return true;
    }

    static void readMatrix(int arr[][10], int row, int col) {
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          cin >> arr[i][j];
        }
      }
    }

    static void printMatrix(int arr[][10], int row, int col) {
      for (int i = 0; i < row; i++) { 
        for (int j = 0; j < col; j++) {
          cout << arr[i][j] << "\t";
        }
        cout << endl;
      }
    }

    static string toString(int arr[], int size) {
      string str = "[";

      for (int i = 0; i < size; i++) {
        if (i != size - 1) {
          str += to_string(arr[i]) + ", ";
        } else {
          str += to_string(arr[i]);
        }
      }
      return str + "]";
    }

    static string toString(int arr[], int start, int end) {
      string str = "[";

      for (int i = start; i <= end; i++) {
        if (i != end) {
          str += to_string(arr[i]) + ", ";
        } else {
          str += to_string(arr[i]);
        }
      }
      return str + "]";
    }
};
