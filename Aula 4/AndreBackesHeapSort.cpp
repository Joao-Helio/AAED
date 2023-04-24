#include <iostream>
using namespace std;

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
    heapSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
