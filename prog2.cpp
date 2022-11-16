/**
 * @file prog2.cpp
 * @brief WAP to search an element using binary search in an array
 * @date 2022-08-04
 */

#include <iostream>
#include "headers/Arrays.h"

using namespace std;

int binarySearch(int arr[], int size, int target) {
  int pos = -1;
  int start = 0, end = size - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (target == arr[mid]) {
      pos = mid;
      // return pos;
    } else if (target > arr[mid]) {
      start = mid + 1;
    } else if (target < arr[mid]) {
      end = mid - 1;
    }
  }

  return pos;
}

int main() {
  int size, target;

  cout << "Enter the size of the array: " << endl;
  cin >> size;

  int arr[size];
  
  cout << "Enter elements in the array: " << endl;
  Arrays::readArray(arr, size);

  cout << "Enter the element you want to search: " << endl;
  cin >> target;

  int pos = binarySearch(arr, size, target);
  if (pos != -1) {
    cout << target << " found at " << pos << " index." << endl;
  } else {
    cout << target << " is not found in the array" << endl;
  }


  return 0;
}

