// DATE - 01/08/2022
// WAP to search an element using linear search in an array

#include <iostream>
#include "headers/Arrays.h"

using namespace std;

int linearSearch(int arr[], int size, int target) {
  int pos = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      pos = i;
      break;
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

  int pos = linearSearch(arr, size, target);
  if (pos != -1) {
    cout << target << " found at " << pos << " index." << endl;
  } else {
    cout << target << " is not found in the array" << endl;
  }

  return 0;
}