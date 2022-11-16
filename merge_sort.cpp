#include <iostream>
#include "headers/Arrays.h"
using namespace std;

void merge(int arr[], int low, int mid, int high) {
  int i = low, j = mid + 1;
  int merged[high - low + 1];
  int x = 0;

  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) {
      merged[x++] = arr[i++];
    } else {
      merged[x++] = arr[j++];
    }
  }

  while (i <= mid) {
    merged[x++] = arr[i++];
  }

  while (j <= high) {
    merged[x++] = arr[j++];
  }

  for (int i = 0, j = low; i < (high - low + 1); i++, j++) {
    arr[j] = merged[i];
  }
}

void merge_sort(int arr[], int low, int high) {
  if (low >= high) return;

  int mid = (low + high) / 2;
  merge_sort(arr, low, mid);
  merge_sort(arr, mid + 1, high);

  merge(arr, low, mid, high);
}

int main() {
  int arr[] = { 5, 4, 3, 2, 1 };

  cout << "Original Array: " << endl;
  Arrays::printArray(arr, 5);

  merge_sort(arr, 0, 4);

  cout << "Sorted Array: " << endl;
  Arrays::printArray(arr, 5);

  return 0;
}