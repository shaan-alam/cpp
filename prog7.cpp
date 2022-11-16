/**
 * @file prog7.cpp
 * @brief WAP to sort an array using bubble sort algorithm
 * @date 21-08-2022
 */
#include <iostream>
#include "headers/Arrays.h"

using namespace std;

void conquer(int arr[], int start, int mid, int end) {
  int i = start, j = mid + 1, x = 0;
  int merged[end - start + 1];

  // Loop over both the arrays and copy the elements in the merged array in sorted manner.
  while (i <= mid && j <= end) {
    if (arr[i] <= arr[j]) {
      merged[x++] = arr[i++];
    } else {
      merged[x++] = arr[j++];
    }
  }

  // At a time only one of the two conditions below will be true
  // and hence either of the two loops will be executed.

  // Copy the remaining elements in the resultant array (if any)
  while (i <= mid) 
    merged[x++] = arr[i++];

  // Copy the remaining elements in the resultant array (if any)
  while (j <= end) 
    merged[x++] = arr[j++];

  // Copy the merged array elements into the original array.
  for (int i = 0, j = start; i < (end - start + 1); i++, j++) {
    arr[j] = merged[i];
  }
}

void divide (int arr[], int start, int end) {
  if (start >= end) return;

  int mid = (start + end) / 2;

  // Recursively divide the array into two subparts LEFT & RIGHT.
  // NOTE - The array isn't physically divided, only the start, mid & end indexes are known.
  divide(arr, start, mid); 
  divide(arr, mid + 1, end);

  conquer(arr, start, mid, end);
}

void mergeSort(int arr[], int size) {
  divide(arr, 0, size - 1);
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

  mergeSort(arr, size);

  cout << "Sorted Array: " << endl;
  Arrays::printArray(arr, size);

  return 0;
}