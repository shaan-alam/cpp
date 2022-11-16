/**
 * @file prog8.cpp
 * @brief WAP to merge two sorted arrays into a single sorted array
 * @date 18-08-2022
 */
#include <iostream>
#include "headers/Arrays.h"
using namespace std;

void merge(int arr1[], int size1, int arr2[], int size2, int resultant[]) {
  int i = 0, j = 0;
  int x = 0;
  
  while (i <= size1 && j <= size2) {
    if (arr1[i] <= arr2[j]) {
      resultant[x++] = arr1[i++];
    } else {
      resultant[x++] = arr2[j++];
    }
  }
  while (i <= size1) 
    resultant[x++] = arr1[i++];

  while (j <= size2) 
    resultant[x++] = arr2[j++];

}


int main() {

  int size1, size2;

  cout << "Enter the size for first array: " << endl;
  cin >> size1;

  cout << "Enter the size for second array: " << endl;
  cin >> size2;
  
  int arr1[size1], arr2[size2], resultant[size1 + size2];

  cout << "Enter elements in the first array: " << endl;
  Arrays::readArray(arr1, size1);

  cout << "Enter elements in the second array: " << endl;
  Arrays::readArray(arr2, size2);

  cout << "First Array: " << endl;
  Arrays::printArray(arr1, size1);

  cout << "Second Array: " << endl;
  Arrays::printArray(arr2, size2);

  merge(arr1, size1, arr2, size2, resultant);

  cout << "Resultant Array: " << endl;
  Arrays::printArray(resultant, size1 + size2);

  return 0;
}