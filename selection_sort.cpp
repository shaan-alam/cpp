#include <iostream>
#include "headers/Arrays.h"
using namespace std;

void selectionSort(int arr[], int size) {
  int min_index;

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
  }
}

int main() {

  int arr[] = { 4, 3, 2, 1, 5, 7 };

  cout << "Original Array: " << endl;
  cout << Arrays::toString(arr, 6) << endl;

  selectionSort(arr, 6);

  cout << "Sorted Array: " << endl;
  cout << Arrays::toString(arr, 6) << endl;

  return 0;
}