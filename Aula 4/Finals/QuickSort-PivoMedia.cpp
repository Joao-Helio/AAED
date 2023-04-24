// código do professor André Backes (UFU) em https://youtu.be/spywQ2ix_Co
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

int particiona(int *V, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = V[((inicio + fim - 1)/2)]; // pivo no meio do vetor
    while(esq < dir){
        while(V[esq] <= pivo){
            esq++;
        }
        while(V[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void quickSort(int *V, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}

// Função auxiliar para calcular as médias de tempo
float mediaDez(float arr[]){
    float soma = 0;
    for(int i = 0; i < 10 ; i++){
        soma += arr[i];
    }
    float media = soma / 10;
    return media;
}

// Função auxiliar para inverter a ordem e gerar vetor decrescente

void inverter(int arr[], int n){
    int i = 0;
    int f = n - 1;

    while (i < f) {
        int aux = arr[i];
        arr[i] = arr[f];
        arr[f] = aux;
        i++;
        f--;
    }
}


int main() {
    int n = 100000;
    float tQuick[10]; // array para guardar os tempos de execução

    cout << "Tempos de execucao para pivo no meio do vetor\n\n";

//gerar 10 execuções

    for(int i = 0; i < 10; i++){
        cout << "\nExecucao com pivo no meio " << i + 1 << ": \n";

        // gerar vetor com 100000 números aleatórios
        int array[100000];
        srand(time(NULL));
        for(int i = 0; i < 100000; i++) {
            array[i] = rand() % 100000; // gerar um número aleatório entre 0 e 99999
        }

        auto startQuick = high_resolution_clock::now();
        quickSort(array, 0, n - 1);
        auto stopQuick = high_resolution_clock::now();
        auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);
        printf("Tempo de Execucao Quick Sort: %.3f ms\n", durationQuick.count() / 1000.0);

        tQuick[i] = durationQuick.count() / 1000.0;

    }
    cout << "\n---------------------------------------------------\n";
    cout << "\nMedia de tempo para pivo no meio:\n";

    float mediaQuick;

    mediaQuick = mediaDez(tQuick);

    cout << "Tempo medio Quick Sort: " << mediaQuick << " ms\n";

    cout << "\n###################################################\n";
    cout << "\nTempos de execucao para vetor ordenado\n";

//gerar 10 execuções para aplicar algoritmo em um vetor ordenado crescente

    for(int i = 0; i < 10; i++){

        cout << "\nExecucao em Vetor Ordenado " << i + 1 << ": \n";

        // gerar vetor com 100000 números aleatórios
        int array[100000];
        srand(time(NULL));
        for(int i = 0; i < 100000; i++) {
            array[i] = rand() % 100000; // gerar um número aleatório entre 0 e 99999
        }
        quickSort(array, 0, n - 1);     // ordenar o vetor antes de contar o tempo

        auto startQuick = high_resolution_clock::now();
        quickSort(array, 0, n - 1);
        auto stopQuick = high_resolution_clock::now();
        auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);
        printf("Tempo de Execucao Quick Sort: %.3f ms\n", durationQuick.count() / 1000.0);

        tQuick[i] = durationQuick.count() / 1000.0;
    }
    cout << "\n---------------------------------------------------\n";
    cout << "\nMedia de tempo para vetor ordenado crescente:\n";

    mediaQuick = mediaDez(tQuick);

    cout << "Tempo medio Quick Sort: " << mediaQuick << " ms\n";

    cout << "\n###################################################\n";
    cout << "\nTempos de execucao para vetor ordenado decrescente\n";

//gerar 10 execuções para aplicar algoritmo em um vetor ordenado decrescente

    for(int i = 0; i < 10; i++){

        cout << "\nExecucao em Vetor Ordenado Decrescente " << i + 1<< ": \n";

        // gerar vetor com 100000 números aleatórios
        int array[100000];
        srand(time(NULL));
        for(int i = 0; i < 100000; i++) {
            array[i] = rand() % 100000; // gerar um número aleatório entre 0 e 99999
        }
        quickSort(array, 0, n - 1);     // ordenar o vetor antes de contar o tempo
        inverter(array, n);             //inverter o vetor ordenado

        auto startQuick = high_resolution_clock::now();
        quickSort(array, 0, n - 1);
        auto stopQuick = high_resolution_clock::now();
        auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);
        printf("Tempo de Execucao Quick Sort: %.3f ms\n", durationQuick.count() / 1000.0);

        tQuick[i] = durationQuick.count() / 1000.0;
    }
    cout << "\n---------------------------------------------------\n";
    cout << "\nMedia de tempo para vetor ordenado decrescente:\n";

    mediaQuick = mediaDez(tQuick);

    cout << "Tempo medio Quick Sort: " << mediaQuick << " ms\n";

    return 0;
}
