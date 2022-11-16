#include "./Arrays.h"
using namespace std;

class Sorting {
  public:

  /* SELECTION SORT BEGINS HERE */
  static void selectionSort(int arr[], int size) {
    int min_index;
    int i = 0;

    cout << "STEPS: " << endl;
    for (int i = 0; i < size - 1; i++) {
      min_index = i;

      for (int j = i + 1; j < size; j++) {
        if (arr[j] < arr[min_index]) min_index = j;
      }

      if (min_index != i) {
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
      }

      cout << "Pass " << i + 1 << " : ";
      cout << Arrays::toString(arr, size) << endl;
    }
  }
  /* SELECTION SORT ENDS HERE */
  

  /* BUBBLE SORT BEGINS HERE */
  static void bubbleSort(int arr[], int size) {
    cout << "STEPS: " << endl;
    int i = 0;

    for (int i = 0; i < size - 1; i++) {
      bool flag = false;
      cout << "Pass: " << i + 1 << " : ";
      
      for (int j = 0; j < size - (i + 1); j++) {
        if (arr[j] > arr[j + 1]) {
          flag = true;
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }

      if (!flag) return;
      cout << Arrays::toString(arr, size) << endl;
    }
  }
  /* BUBBLE SORT ENDS HERE */


  /* INSERTIONS SORT BEGINS HERE */
  static void insertionSort(int arr[], int size) {
    int key, j;
    int i = 0;

    cout << "STEPS: " << endl;
    for (int i = 1; i < size; i++) {
      key = arr[i];
      j = i - 1;

      // Shifting the key value to the left in its proper place.
      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = key;
      cout << "Pass " << i << " : " << endl;
      cout << Arrays::toString(arr, size) << endl;
    }
  }
  /* INSERTIONS SORT ENDS HERE */

  /* MERGE SORT BEGINS HERE */
  static void conquer(int arr[], int start, int mid, int end) {
    int i = start, j = mid + 1, x = 0;
    int merged[end - start + 1];

    while (i <= mid && j <= end) {
      if (arr[i] <= arr[j]) {
        merged[x++] = arr[i++];
      } else {
        merged[x++] = arr[j++];
      }
    }

    while (i <= mid) 
      merged[x++] = arr[i++];

    while (j <= end) 
      merged[x++] = arr[j++];

    for (int i = 0, j = start; i < (end - start + 1); i++, j++) {
      arr[j] = merged[i];
    }
  }

  static void mergeSort(int arr[], int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    conquer(arr, start, mid, end);
    cout << Arrays::toString(arr, start, end) << endl;
  }
  /* MERGE SORT ENDS HERE */



  /* QUICK SORT BEGINS HERE */
  static int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
      if (arr[j] < pivot) {
        i += 1;
        swap(arr[i], arr[j]);
      }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
  }

  static void quickSort(int arr[], int start, int end) {
    if (start >= end) return;

    int pivot = partition(arr, start, end);
    cout << Arrays::toString(arr, start, end) << endl;

    
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
    
  }

  /* QUICK SORT ENDS HERE */
};