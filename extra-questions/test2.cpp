/**
 * @file test3.cpp
 * @brief Binary search implementation using Recursion
 * @date 23-08-2022
 */

#include <iostream>
using namespace std;

int binarySearch(int a[], int start, int end, int target) {
  int mid = (start + end) / 2;
  int pos = -1;

  if (start == end && pos == -1) return -1;
  
  if (a[mid] == target) {
    pos = mid;
    return pos;
  } else if (target < a[mid]) {
    pos = binarySearch(a, start, mid - 1, target);
  } else if (target > a[mid]) {
    pos = binarySearch(a, mid + 1, end, target);
  }

  return pos;
}

int main() {
  int a[] = { 1, 2, 3, 4, 5, 6, 7 };
  int target = 12, start = 0, end = 6;

  int pos = binarySearch(a, start, end, target);

  if (pos != -1) {
    cout << target << " found at index " << pos << endl;
  } else {
    cout << target << " isn't present in the array." << endl;
  }

  return 0;
}