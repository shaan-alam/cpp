/**
 * @file test.cpp
 * @brief WAP to sort each row of a matrix in descending order using merge sort.
 * @date 22-08-2022
 */

#include <iostream>
using namespace std;

void readMatrix(int matrix[][10], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
  }
}

void printMatrix(int matrix[][10], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
}

void conquer(int arr[], int start, int mid, int end) {
  int i = 0, j = mid + 1, x = 0;
  int merged[end - start + 1];


  while  (i <= mid && j <= end) {
    if (arr[i] >= arr[j]) {
      merged[x++] = arr[i++];
    } else {
      merged[x++] = arr[j++];
    }
  }

  while (i <= mid) {
    merged[x++] = arr[i++];
  }

  while (j <= end) {
    merged[x++] = arr[j++];
  }

  int k = 0;
  for (int i = 0; i < (end - start + 1); i++) {
    arr[k++] = merged[i];
  }

}


void sort(int arr[], int start, int end) {
  if (start >= end) return;

  int mid = (start + end) / 2;
  sort(arr, start, mid);
  sort(arr, mid + 1, end);

  conquer(arr, start, mid, end);
}

int main() {
  int row, col, matrix[10][10];

  cout << "Enter row: " << endl;
  cin >> row;

  cout << "Enter cols: " << endl;
  cin >> col;

  cout << "Enter matrix elements: " << endl;
  readMatrix(matrix, row, col);

  cout << "Original Matrix: " << endl;
  printMatrix(matrix, row, col);

  // Sorting row

  for (int i = 0; i < row; i++) {
    sort(matrix[i], 0, col - 1);
  }

  cout << "Resultant Matrix: " << endl;
  printMatrix(matrix, row, col);

  return 0;
}