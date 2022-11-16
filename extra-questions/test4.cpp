#include <iostream>
#include "../headers/Arrays.h"
using namespace std;

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high) {
  int stack[high - low + 1];
  int top = -1;

  stack[++top] = low;
  stack[++top] = high;

  while (top >= 0) {
    high = stack[top--];
    low = stack[top--];

    int p = partition(arr, low, high);

    if (p - 1 > low) {
      stack[++top] = low;
      stack[++top] = p - 1;
    }

    if (p + 1 < high) {
      stack[++top] = p + 1;
      stack[++top] = high;
    }
  }
}

int main() {
  int arr[] = { 7, 4, 0, -1, 3, 2 };
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted array: " << endl;
  cout << Arrays::toString(arr, size) << endl;

  quickSort(arr, 0, size - 1);

  cout << "Sorted array: " << endl;
  cout << Arrays::toString(arr, size) << endl;  

  return 0;
}