#include <iostream>
using namespace std;

// Fonte: sortvisualizer.com/mergesort

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];

   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];

   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];

   i = 0; j = 0; k = l;

   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      } else {
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {
      array[k] = rarr[j];
      j++; k++;
   }
}

void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;

      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

// Helper function to print the array
void printArray(int arr[]) {
    int n = 12;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main () {
    int arr[] = {10, 80, 30, 350, 90, 40, 50, 70, 45, 20, 110, 25};
    // int n = 7;
    cout << "Original array: ";
    printArray(arr);
    mergeSort(arr, 0, 11);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
