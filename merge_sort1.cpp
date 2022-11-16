#include <iostream>
using namespace std;

void conquer(int arr[], int low, int mid, int high) {
  int i = low, j = mid + 1;
  int x = 0;
  int merged[high - low + 1];

  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) {
      merged[x++] = arr[i++];
    } else {
      merged[x++] = arr[j++];
    }
  }

  while (i <= mid)
    merged[x++] = arr[i++];

  while (j <= high)
    merged[x++] = arr[j++];

  for (int i = 0, k = low; i < (high - low + 1); i++, k++) {
    arr[k] = merged[i];
  }
}

void merge(int arr[], int low, int high) {
  if (low >= high) return;

  int mid = (low + high) / 2;
  merge(arr, low, mid);
  merge(arr, mid + 1, high);

  conquer(arr, low, mid, high);
}

int main() {

  int arr[] = { 4, 5, 2, 1, 3 };

  merge(arr, 0, 4);
  
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}