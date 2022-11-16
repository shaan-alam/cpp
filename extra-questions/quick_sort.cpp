#include <iostream>
#include "../headers/Arrays.h"
using namespace std;

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i += 1;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high) {
	if (low >= high) return;

	int pivot = partition(arr, low, high);
	quickSort(arr, low, pivot - 1);
	quickSort(arr, pivot + 1, high);
}

int main() {
	int size;
	
	cout << "Enter the size of the array: " << endl;
	cin >> size;

	int arr[size];

	cout << "Enter array elements: " << endl;
	Arrays::readArray(arr, size);

	cout << "Unsorted Array: " << endl;
	cout << Arrays::toString(arr, size) << endl;	

	quickSort(arr, 0, size - 1);

	cout << "Sorted Array: " << endl;
	cout << Arrays::toString(arr, size) << endl;	

	return 0;
}