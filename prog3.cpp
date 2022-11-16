/**
 * @file prog3.cpp
 * @brief WAP to sort an array using selection sort algorithm
 * @date 08-08-2022
 */

#include <iostream>
#include "headers/Arrays.h"

using namespace std;

void selectionSort(int arr[], int size) {
  int min_index;
  
  for (int i = 0; i < size - 1; i++) {
    min_index = i;

    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[i]) min_index = j;
    }

    if (min_index != i) {
      int temp = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = temp;
    }
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

  selectionSort(arr, size);

  cout << "Sorted Array: " << endl;
  Arrays::printArray(arr, size);

  return 0;
}