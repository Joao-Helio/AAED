#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
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
    quickSort(arr, 0, n-1);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
