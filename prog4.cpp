/**
 * @file prog4.cpp
 * @brief WAP to sort an array using insertion sort algorithm
 * @date 08-08-2022
 */
#include <iostream>
#include "headers/Arrays.h"

using namespace std;

void insertionSort(int arr[], int size) {
  int key, j;

  for (int i = 1; i < size; i++) {
    key = arr[i];
    j = i - 1;

    // Shifting the key value to the left in its proper place.
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  
  int size;

  cout << "Enter the size of the array: " << endl;
  cin >> size;

  int arr[size];
  
  cout << "Enter elements in the array: " << endl;
  Arrays::readArray(arr, size);

  cout << "Original Array: " << endl;
  Arrays::printArray(arr, size);

  insertionSort(arr, size);

  cout << "Sorted Array: " << endl;
  Arrays::printArray(arr, size);

  return 0;
}