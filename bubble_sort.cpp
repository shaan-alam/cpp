#include <iostream>
#include "headers/Arrays.h"
using namespace std;

void bubble_sort(int arr[], int size) {
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

int main() {
  int arr[] = { 5, 4, 3, 2, 1 };

  cout << "Original Array: " << endl;
  Arrays::printArray(arr, 5);

  bubble_sort(arr, 5);

  cout << "Sorted Array: " << endl;
  Arrays::printArray(arr, 5);
  
  return 0;
}