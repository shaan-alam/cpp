/**
 * @file test3.cpp
 * @brief Linear Search using recursion
 * @date 23-08-2022
 */

#include <iostream>
using namespace std;

int linearSearch(int a[], int start, int end, int target) {
  int pos = -1;

  if (start < end) {
    pos = linearSearch(a, start + 1, end, target);
  }

  if (a[start] == target) return start;

  return pos;
}

int main() {
  int a[] = { 1, 2, 3, 4, 5, 6, 7 };
  int target = 7, start = 0, end = 6;

  int pos = linearSearch(a, start, end, target);

  if (pos != -1) {
    cout << target << " found at index " << pos << endl;
  } else {
    cout << target << " isn't present in the array." << endl;
  }

  return 0;
  return 0;
}