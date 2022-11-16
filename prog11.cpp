/**
 * @file prog11.cpp
 * @brief Menu driven program to perform Selection sort, insertion sort, bubble sort, merge sort, quick sort
 * @date 29-08-2022
 */

#include <iostream>
#include "headers/Sorting.h"
using namespace std;

int main() {
  while(true) {
    system("clear");

    int size;

    cout << "Enter size of the array: " << endl;  
    cin >> size;

    int arr[size];

    cout << "Enter elements in the array: " << endl;
    Arrays::readArray(arr, size);


    cout << "🔹🔹🔹🔹🔹🔹 MENU 🔹🔹🔹🔹🔹🔹" << endl;
    cout << "1. Selection Sort." << endl;
    cout << "2. Bubble Sort." << endl;
    cout << "3. Insertion Sort." << endl;
    cout << "4. Merge Sort." << endl;
    cout << "5. Quick Sort." << endl;

    int choice;

    cout << "Enter your choice: ";
    cin >> choice;


    switch(choice) {
      case 1:
        cout << "Unsorted Array: " << endl;
        cout << Arrays::toString(arr, size) << endl;

        Sorting::selectionSort(arr, size);

        cout << "Sorted Array: " << endl;
        cout << Arrays::toString(arr, size) << endl;
        break;
      case 2:
        cout << "Unsorted Array: " << endl;
        cout << Arrays::toString(arr, size) << endl;

        Sorting::bubbleSort(arr, size);

        cout << "Sorted Array: " << endl;
        cout << Arrays::toString(arr, size) << endl;
        break;
      case 3:
        cout << "Unsorted Array: " << endl;
        cout << Arrays::toString(arr, size) << endl;

        Sorting::insertionSort(arr, size);

        cout << "Sorted Array: " << endl;
        cout << Arrays::toString(arr, size) << endl;
        break;
      case 4:
        cout << "Unsorted Array: " << endl;
        cout << Arrays::toString(arr, size) << endl;

        cout << "STEPS:" << endl;
        Sorting::mergeSort(arr, 0, size - 1);

        cout << "Sorted Array: " << endl;
        cout << Arrays::toString(arr, size) << endl;
        break;
      case 5:
        cout << "Unsorted Array: " << endl;
        cout << Arrays::toString(arr, size) << endl;

        cout << "STEPS:" << endl;
        Sorting::quickSort(arr, 0, size - 1);

        cout << "Sorted Array: " << endl;
        cout << Arrays::toString(arr, size) << endl;
        break;

      default:
        cout << "Wrong choice....!" << endl;
    }
    getchar();
    getchar();
  }

  
  return 0;
}