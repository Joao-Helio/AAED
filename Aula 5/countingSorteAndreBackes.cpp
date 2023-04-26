#include <iostream>
using namespace std;

#define MAX 100

int* countingSort(int *A, int n) {
    int i, j, k;
    int C[MAX];
    for(i = 0; i < MAX; i++) {
        C[i] = 0;           // zerar todas as posições vetor que vai receber
    }
    for(i = 0; i < n; i++) {
        C[A[i]]++;          // incrementar o valor da posição no vetor B correspondente a cada ocorrência dos valores de A
    }
    int* B = new int[n];
    for(i = 0, j = 0; j < MAX; j++) {
        for(k = C[j]; k > 0; k--) {
            B[i++] = j;     // colocar na posição correta no vetor B
        }
    }
    return B;
}

int main(){
    int V[] = {6, 0, 2, 0, 1, 3 , 4, 6, 1, 3, 2};
    int n = sizeof(V) / sizeof(V[0]);
    int* ordenado = countingSort(V, n);

    cout << "Vetor ordenado:\n[";
    for(int i = 0; i < n; i++){
        cout << ordenado[i] << " ";
    }
    cout << "]";
    delete[] ordenado;
    return 0;
}
