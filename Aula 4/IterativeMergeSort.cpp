#include <iostream>
using namespace std;

// Fonte: sortvisualizer.com/mergesort

void merge(int *array, int *aux, int l, int m, int r) {
   int i = l, j = m + 1, k= l;

   while(i <= m && j <= r) {
        if(array[i] <= array[j]){
            aux[k] = array[i];
            i++;
        }else{
            aux[k] = array[j];
            j++;
        }
        k++;
   }
    while(i <= m){
        aux[k] = array[i];
        i++;
        k++;
    }
    while(j <= r){
        aux[k] = array[j];
        j++;
        k++;
    }
    for(k = l; k <= r; k++){
        array[k] = aux[k];
    }
}

void mergeSort(int *array, int n) {
   int m, l, r;
   int* aux = new int[n];
   for(int i=1; i < n; i *= 2){
        for(l = 0; l < n - i; l += 2 * i){
            m = l + i - 1;
            r = min(l + 2 * i - 1, n - 1);
            merge(array, aux, l, m, r);
        }
   }
   delete[] aux;
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
    mergeSort(arr, 12);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
