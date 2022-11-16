#include <iostream>
#include "headers/Arrays.h"
using namespace std;

int partition(int arr[], int low, int high)
{
  int pivot = arr[low];
  int count = 0;

  for (int i = low + 1; i <= high; i++)
  {
    if (arr[i] <= pivot)
      count++;
  }

  int pivotIndex = low + count;
  swap(arr[pivotIndex], arr[low]);

  int i = low, j = high;
  while (i < pivotIndex && j > pivotIndex)
  {
    while (arr[i] <= pivot)
      i++;
    while (arr[j] > pivot)
      j++;
    if (i < pivotIndex && j > pivotIndex)
    {
      swap(arr[i++], arr[j--]);
    }
  }

  return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
  if (low >= high)
    return;

  int pivot = partition(arr, low, high);
  quick_sort(arr, low, pivot - 1);
  quick_sort(arr, pivot + 1, high);
}

int main()
{
  int arr[] = {4, 5, 3, 1, 2};

  cout << "Original Array: " << endl;
  Arrays::printArray(arr, 5);

  quick_sort(arr, 0, 4);

  cout << "Sorted Array: " << endl;
  Arrays::printArray(arr, 5);

  return 0;
}