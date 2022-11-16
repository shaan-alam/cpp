/**
 * @file prog9.cpp
 * @brief Quick Sort implementation 
 * @date 25-08-2022
 */
#include <iostream>
#include "headers/Arrays.h"
using namespace std;

int partition(int arr[], int left, int right) {
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

void quickSort(int arr[], int start, int end) {
  if (start >= end) return;

  int pivot = partition(arr, start, end);
  quickSort(arr, start, pivot - 1);
  quickSort(arr, pivot + 1, end);
}

int main() {
  
  int size;

  cout << "Enter size of the array: " << endl;
  cin >> size;

  int array[size];

  cout << "Enter array elements: " << endl;
  Arrays::readArray(array, size);

  cout << "Unsorted array: " << endl;
  Arrays::printArray(array, size);

  quickSort(array, 0, size - 1);

  cout << "Sorted array: " << endl;
  Arrays::printArray(array, size);

  return 0;
}