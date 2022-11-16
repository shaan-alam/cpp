#include <iostream>
#include "headers/Arrays.h"
using namespace std;

void insertion_sort(int arr[], int size)
{
  int key, j;

  for (int i = 1; i < size; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main()
{
  int arr[] = {5, 4, 3, 2, 1};

  cout << "Original Array: " << endl;
  Arrays::printArray(arr, 5);

  insertion_sort(arr, 5);

  cout << "Sorted Array: " << endl;
  Arrays::printArray(arr, 5);

  return 0;
}