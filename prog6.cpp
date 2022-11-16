/**
 * @file prog6.cpp
 * @brief WAP to find the address of an element in a matrix using row-major and col-major technique.
 * @date 11-08-2022
 */

#include <iostream>
#include "headers/Arrays.h"
using namespace std;

void findElement(int arr[][10], int row, int col, int target, int &i, int &j)
{
  for (int x = 0; x < row; x++)
  {
    for (int y = 0; y < col; y++)
    {
      if (arr[x][y] == target)
      {
        i = x;
        j = y;
        break;
      }
    }
  }
}

int main()
{
  int row, col, matrix[10][10], i = -1, j = -1, target;

  cout << "Enter row and col size: " << endl;
  cin >> row >> col;

  matrix[row][col];

  cout << "Enter matrix elements: " << endl;
  Arrays::readMatrix(matrix, row, col);

  cout << "Enter target: " << endl;
  cin >> target;

  // To find where the element actually exists in the matrix
  // and get the row and col number stored in variable i & j.
  findElement(matrix, row, col, target, i, j);

  // Make sure element exists in the matrix,
  // otherwise just return 0 and exit.
  if (i == -1 || j == -1)
  {
    cout << target << " is not present in the 2D array..." << endl;
    return 0;
  }

  cout << "Matrix: " << endl;
  Arrays::printMatrix(matrix, row, col);

  int *BA = &matrix[0][0];
  int *result1 = BA + sizeof(int) * (i * col + j); // ROW MAJOR
  int *result2 = BA + sizeof(int) * (j * row + i); // COL MAJOR

  cout << endl;

  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Base Address: " << &matrix[0] << endl;
  cout << "Address (Row-major wise): " << result1 << endl;
  cout << "Address (Col-major wise): " << result2 << endl;

  return 0;
}