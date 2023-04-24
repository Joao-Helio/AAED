#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

//------------------------------------------------------------
// ShellSort

// Fonte: Slides da Aula 4 - Profª Lilian Berton
// vetor com os valores para h
int inc[8] = {3280,1093,364,121,40,13,4,1};

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
//------------------------------------------------------------
//------------------------------------------------------------

// HeapSort

// Fonte: André Backes em https://youtu.be/zSYOMJ1E52A

void criaHeap(int *vet, int i, int f){
    int aux = vet[i];   // pai = i
    int j = 2 * i + 1;  // primeiro filho = j
    while (j <= f){     // enquanto o filho for menor que o final do vetor
        if(j < f){
            if(vet[j] < vet[j+1]) // qual filho é maior?
                j = j + 1;
        }
        if(aux < vet[j]){       // se o filho é maior que o pai
            vet[i] = vet[j];    // filho se torna o pai
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    vet[i] = aux;   // antigo pai ocupa lugar do último filho analisado
}

void heapSort(int *vet, int N) {
        int i, aux;
        for(i=(N-1)/2; i >= 0; i--){
            criaHeap(vet, i, N-1);  //-criar heap a partir dos dados
        }
        for (i = N-1; i>= 1; i--){
            aux = vet[0];           // -pegar o maior elemento da heap
            vet[0] = vet[i];        //  e colocar na sua posição
            vet[i] = aux;           //  correspondente no array;
            criaHeap(vet, 0, i-1);  // -reconstruir heap
        }
}
//------------------------------------------------------------
//------------------------------------------------------------

// QuickSort

// Fonte: https://sortvisualizer.com/quicksort/

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

//------------------------------------------------------------
//------------------------------------------------------------

// MergeSort

// Fonte: https://sortvisualizer.com/mergesort/ (adaptado para forma iterativa)

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

//------------------------------------------------------------
//------------------------------------------------------------
// Função auxiliar para exibir e conferir arrays

void printArray(int arr[]) {
    int n = 100000;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

// gerar vetor com 100000 números aleatórios

  int array[100000];
  srand(time(NULL));

  for(int i = 0; i < 100000; i++) {
    array[i] = rand() % 100000; // gerar um número aleatório entre 0 e 99999
  }

  int n = 100000;

 // cout << "Original array: ";
 // printArray(array);

  // Copiar o array para utilizar o mesmo em todos os algoritmos

  int shellSorted[100000], heapSorted[100000], quickSorted[100000], mergeSorted[100000];

  for(int i = 0; i < 100000; i++){
        shellSorted[i] = array[i];
        heapSorted[i] = array[i];
        quickSorted[i] = array[i];
        mergeSorted[i] = array[i];
  }

  // Start measuring time
  auto startShell = high_resolution_clock::now();

  shellSort(shellSorted, n, inc, 8);

  // Stop measuring time
  auto stopShell = high_resolution_clock::now();
  // Calculate the duration of the execution
  auto durationShell = duration_cast<microseconds>(stopShell - startShell);

  // Print the duration in milliseconds
  printf("Tempo de Execucao Shell Sort: %.6f ms\n", durationShell.count() / 1000.0);

 // cout << "Sorted array: ";
 // printArray(shellSorted);

  // Start measuring time
  auto startHeap = high_resolution_clock::now();

  heapSort(heapSorted, n);

  // Stop measuring time
  auto stopHeap = high_resolution_clock::now();
  // Calculate the duration of the execution
  auto durationHeap = duration_cast<microseconds>(stopHeap - startHeap);

 // cout << "Sorted array: ";
 // printArray(heapSorted);


  // Print the duration in milliseconds
  printf("Tempo de Execucao Heap Sort: %.6f ms\n", durationHeap.count() / 1000.0);

  // Start measuring time
  auto startQuick = high_resolution_clock::now();

  quickSort(quickSorted, 0, n - 1);

  // Stop measuring time
  auto stopQuick = high_resolution_clock::now();
  // Calculate the duration of the execution
  auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);

 // cout << "Sorted array: ";
 // printArray(quickSorted);

  // Print the duration in milliseconds
  printf("Tempo de Execucao Quick Sort: %.6f ms\n", durationQuick.count() / 1000.0);

  // Start measuring time
  auto startMerge = high_resolution_clock::now();

  mergeSort(mergeSorted, n);

  // Stop measuring time
  auto stopMerge = high_resolution_clock::now();
  // Calculate the duration of the execution
  auto durationMerge = duration_cast<microseconds>(stopMerge - startMerge);

 // cout << "Sorted array: ";
 // printArray(mergeSorted);
  // Print the duration in milliseconds
  printf("Tempo de Execucao Merge Sort: %.6f ms\n", durationMerge.count() / 1000.0);
  return 0;
}
