// ShellSort

#include<iostream>
using namespace std;

// vetor com os valores para h
int inc[3] = {3,2,1};

void shellSort(int v[], int n, int incrementos[], int numinc){
    int incr, i, j, h, aux;
    for (incr = 0; incr < numinc; incr++) {
        h = incrementos[incr];
        for (i = h; i < n; i++) {
            aux = v[i];
            for (j = i - h; j >= 0 && v[j] > aux; j -= h) {
                v[j + h] = v[j];
                v[j] = aux; // ajuste --> no slide estava v[j+h] = aux
            }
        }
    }
}

// Helper function to print the array
void printArray(int arr[]) {
    int n = 7;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main () {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = 7;
    cout << "Original array: ";
    printArray(arr);
    shellSort(arr, n, inc, 3);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
