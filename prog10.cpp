/**
 * @file prog10.cpp
 * @brief Write a menu driven program to implement linear and binary search.
 * @date 22-08-2022
 */

#include <iostream>
#include "headers/Arrays.h"
using namespace std;

int linearSearch(int arr[], int size, int target, int &count) {
  int pos = -1;

  for (int i = 0; i < size; i++) {
    count++;
    if (arr[i] == target) {
      pos = i;
      break;
    }
  }
  
  return pos;
}

int binarySearch(int arr[], int size, int target, int &count) {
  int start = 0, end = size - 1;
  int pos = -1;

  while (start <= end) {
    int mid = (start + end) / 2;
    count++;

    if (target == arr[mid]) {
      pos = mid;
      break;
    } else if (target > arr[mid]) {
      start = mid + 1;
    } else if (target < arr[mid]) {
      end = mid - 1;
    }
  }

  return pos;
}

int main() {
  int size, target, choice, pos;

  int linear_count = 0;
  int binary_count = 0;

  cout << "Enter size of the array: " << endl;
  cin >> size;

  int arr[size];

  cout << "Enter array elements: " << endl;
  Arrays::readArray(arr, size);

  cout << "Original array: " << endl;
  Arrays::printArray(arr, size);

  cout << "Enter the element you want to search: " << endl;
  cin >> target;

  cout << "Choose the algorithm: " << endl;
  cout << "1. Linear Search: " << endl;
  cout << "2. Binary Search: " << endl;
  cin >> choice;

  switch(choice) {
    case 1:
      pos = linearSearch(arr, size, target, linear_count);
      cout << "No of comparisons: " << linear_count << endl;
      break;
    case 2:
      pos = binarySearch(arr, size, target, binary_count);
      cout << "No of comparisons: " << binary_count << endl;
      break;
    default: {
      cout << "Wrong choice!!";
    }
  }

  if (pos != -1) {
    cout << target << " found at index " << pos << endl; 
  } else {
    cout << target << " is not present in the array." << endl;
  }

  return 0;
}