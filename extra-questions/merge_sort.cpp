#include <iostream>
#include "../headers/Arrays.h"
using namespace std;

void conquer(int arr[], int start, int mid, int end) {
  int i = start, j = mid + 1, x = 0;
  int merged[end - start + 1];

  while (i <= mid && j <= end) {
    if (arr[i] <= arr[j]) {
      merged[x++] = arr[i++];
    } else {
      merged[x++] = arr[j++];
    }
  }

  while (i <= mid) {
    merged[x++] = arr[i++];
  }

  while (j <= end) {
    merged[x++] = arr[j++];
  }

  x = start;
  for (int i = 0; i < (end - start + 1); i++) {
    arr[x++] = merged[i];
  }
}

void divide(int arr[], int start, int end) {
  if (start >= end) return;

  int mid = (start + end) / 2;
  divide(arr, start, mid);
  divide(arr, mid + 1, end);

  conquer(arr, start, mid, end);
}

void mergeSort(int arr[], int size) {
  divide(arr, 0, size - 1);
}

int main() {
  int size;

  cout << "Enter array size: " << endl; 
  cin >> size;

  int arr[size];

  cout << "Enter array elements: " << endl;
  Arrays::readArray(arr, size);

  cout << "Unsorted Array: " << endl;
  cout << Arrays::toString(arr, size); << endl;

  mergeSort(arr, size);

  cout << "Sorted Array: " << endl;
  cout << Arrays::toString(arr, size); << endl;

  return 0;
}