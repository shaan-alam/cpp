/**
 * @file prog5.cpp
 * @brief WAP to sort an array using bubble sort algorithm
 * @date 11-08-2022
 */
#include <iostream>
#include "headers/Arrays.h"

using namespace std;

void bubbleSort(int arr[], int size) {
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
  
  int size;

  cout << "Enter the size of the array: " << endl;
  cin >> size;

  int arr[size];
  
  cout << "Enter elements in the array: " << endl;
  Arrays::readArray(arr, size);

  cout << "Original Array: " << endl;
  Arrays::printArray(arr, size);

  bubbleSort(arr, size);

  cout << "Sorted Array: " << endl;
  Arrays::printArray(arr, size);

  return 0;
}