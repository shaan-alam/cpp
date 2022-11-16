#include <iostream>
#include "headers/Arrays.h"
using namespace std;

int binarySearch(int arr[], int size, int target) {
  int start = 0, end = size - 1;
  
  while (start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (target < arr[mid]) {
      end = mid - 1;
    } else if (target > arr[mid]) {
      start = mid + 1;
    }
  }

  return -1;
}

int main() {
  int arr[] = { 1, 2, 3, 4, 5 };

  int target = 3;

  cout << "Original Array: " << endl;
  Arrays::printArray(arr, 5);

  int pos = binarySearch(arr, 5, target);
  if (pos == -1) {
    cout << "Element not found" << endl;
  } else {
    cout << "Element found" << endl;
  }
  return 0;
}