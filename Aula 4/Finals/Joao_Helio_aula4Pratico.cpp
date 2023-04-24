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

// Fonte: Professor André Backes em https://youtu.be/spywQ2ix_Co

int particiona(int *V, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = V[inicio]; // pivo no inicio do vetor
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
    float tShell[10], tHeap[10], tQuick[10], tMerge[10]; // arrays para guardar os tempos de execução

    cout << "Tempos de execucao para vetor aleatorio\n\n";

//gerar 10 execuções

    for(int i = 0; i < 10; i++){
        cout << "\nExecucao em vetor aleatorio " << i + 1 << ": \n";
    // gerar vetor com 100000 números aleatórios

        int array[100000];
        srand(time(NULL));

        for(int j = 0; j < 100000; j++) {
            array[j] = rand() % 100000; // gerar um número aleatório entre 0 e 99999
        }

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
        printf("Tempo de Execucao Shell Sort: %.3f ms\n", durationShell.count() / 1000.0);

        auto startHeap = high_resolution_clock::now();
        heapSort(heapSorted, n);
        auto stopHeap = high_resolution_clock::now();
        auto durationHeap = duration_cast<microseconds>(stopHeap - startHeap);
        printf("Tempo de Execucao Heap Sort: %.3f ms\n", durationHeap.count() / 1000.0);

        auto startQuick = high_resolution_clock::now();
        quickSort(quickSorted, 0, n - 1);
        auto stopQuick = high_resolution_clock::now();
        auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);
        printf("Tempo de Execucao Quick Sort: %.3f ms\n", durationQuick.count() / 1000.0);

        auto startMerge = high_resolution_clock::now();
        mergeSort(mergeSorted, n);
        auto stopMerge = high_resolution_clock::now();
        auto durationMerge = duration_cast<microseconds>(stopMerge - startMerge);
        printf("Tempo de Execucao Merge Sort: %.3f ms\n", durationMerge.count() / 1000.0);

        tShell[i] = durationShell.count() / 1000.0;
        tHeap[i] = durationHeap.count() / 1000.0;
        tQuick[i] = durationQuick.count() / 1000.0;
        tMerge[i] = durationMerge.count() / 1000.0;
    }
    cout << "\n\n---------------------------------------------------\n\n";
    cout << "\n\nMedias de tempo para vetor aleatorio:\n\n";

    float mediaShell, mediaHeap, mediaQuick, mediaMerge;

    mediaShell = mediaDez(tShell);
    mediaHeap = mediaDez(tHeap);
    mediaQuick = mediaDez(tQuick);
    mediaMerge = mediaDez(tMerge);

    cout << "Tempo medio Shell Sort: " << mediaShell << " ms\n";
    cout << "Tempo medio Heap Sort: " << mediaHeap << " ms\n";
    cout << "Tempo medio Quick Sort: " << mediaQuick << " ms\n";
    cout << "Tempo medio Merge Sort: " << mediaMerge << " ms\n";

    cout << "\n\n###################################################\n\n";
    cout << "\n\nTempos de execucao para vetor ordenado\n\n";

//gerar 10 execuções para aplicar algoritmos em um vetor ordenado crescente

    for(int i = 0; i < 10; i++){

        int array[100000];
        srand(time(NULL));

        for(int j = 0; j < 100000; j++) {
            array[j] = rand() % 100000;
        }

        quickSort(array, 0, n - 1); // ordena o vetor com o QuickSort, que obteve o melhor desempenho no aleatorio

        cout << "\nExecucao em Vetor Ordenado " << i + 1 << ": \n";

        auto startShell = high_resolution_clock::now();
        shellSort(array, n, inc, 8);
        auto stopShell = high_resolution_clock::now();
        auto durationShell = duration_cast<microseconds>(stopShell - startShell);
        printf("Tempo de Execucao Shell Sort: %.3f ms\n", durationShell.count() / 1000.0);

        auto startHeap = high_resolution_clock::now();
        heapSort(array, n);
        auto stopHeap = high_resolution_clock::now();
        auto durationHeap = duration_cast<microseconds>(stopHeap - startHeap);
        printf("Tempo de Execucao Heap Sort: %.3f ms\n", durationHeap.count() / 1000.0);

        auto startQuick = high_resolution_clock::now();
        quickSort(array, 0, n - 1);
        auto stopQuick = high_resolution_clock::now();
        auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);
        printf("Tempo de Execucao Quick Sort: %.3f ms\n", durationQuick.count() / 1000.0);

        auto startMerge = high_resolution_clock::now();
        mergeSort(array, n);
        auto stopMerge = high_resolution_clock::now();
        auto durationMerge = duration_cast<microseconds>(stopMerge - startMerge);
        printf("Tempo de Execucao Merge Sort: %.3f ms\n", durationMerge.count() / 1000.0);

        tShell[i] = durationShell.count() / 1000.0;
        tHeap[i] = durationHeap.count() / 1000.0;
        tQuick[i] = durationQuick.count() / 1000.0;
        tMerge[i] = durationMerge.count() / 1000.0;
    }
    cout << "\n\n---------------------------------------------------\n\n";
    cout << "\n\nMedias de tempo para vetor ordenado crescente:\n\n";

    mediaShell = mediaDez(tShell);
    mediaHeap = mediaDez(tHeap);
    mediaQuick = mediaDez(tQuick);
    mediaMerge = mediaDez(tMerge);

    cout << "Tempo medio Shell Sort: " << mediaShell << " ms\n";
    cout << "Tempo medio Heap Sort: " << mediaHeap << " ms\n";
    cout << "Tempo medio Quick Sort: " << mediaQuick << " ms\n";
    cout << "Tempo medio Merge Sort: " << mediaMerge << " ms\n";

    cout << "\n\n###################################################\n\n";
    cout << "\n\nTempos de execucao para vetor ordenado\n\n";

    //gerar 10 execuções para aplicar algoritmos em um vetor ordenado decrescente

    for(int i = 0; i < 10; i++){

        int array[100000];
        srand(time(NULL));

        for(int j = 0; j < 100000; j++) {
            array[j] = rand() % 100000;
        }

        shellSort(array, n, inc, 8); // ordena o vetor com o ShellSort, que obteve o melhor desempenho no vetor ordenado
        inverter(array, n);            // inverte o array para aplicar os algoritmos no vetor ordenado de formadecrescente

        cout << "\nExecucao Ordenado Decrescente " << i + 1 << " :\n";

        auto startShell = high_resolution_clock::now();
        shellSort(array, n, inc, 8);
        auto stopShell = high_resolution_clock::now();
        auto durationShell = duration_cast<microseconds>(stopShell - startShell);
        printf("Tempo de Execucao Shell Sort: %.3f ms\n", durationShell.count() / 1000.0);

        auto startHeap = high_resolution_clock::now();
        heapSort(array, n);
        auto stopHeap = high_resolution_clock::now();
        auto durationHeap = duration_cast<microseconds>(stopHeap - startHeap);
        printf("Tempo de Execucao Heap Sort: %.3f ms\n", durationHeap.count() / 1000.0);

        auto startQuick = high_resolution_clock::now();
        quickSort(array, 0, n - 1);
        auto stopQuick = high_resolution_clock::now();
        auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);
        printf("Tempo de Execucao Quick Sort: %.3f ms\n", durationQuick.count() / 1000.0);

        auto startMerge = high_resolution_clock::now();
        mergeSort(array, n);
        auto stopMerge = high_resolution_clock::now();
        auto durationMerge = duration_cast<microseconds>(stopMerge - startMerge);
        printf("Tempo de Execucao Merge Sort: %.3f ms\n", durationMerge.count() / 1000.0);

        tShell[i] = durationShell.count() / 1000.0;
        tHeap[i] = durationHeap.count() / 1000.0;
        tQuick[i] = durationQuick.count() / 1000.0;
        tMerge[i] = durationMerge.count() / 1000.0;
    }
    cout << "\n\n---------------------------------------------------\n\n";
    cout << "\n\nMedias de tempo para vetor ordenado decrescente:\n\n";

    mediaShell = mediaDez(tShell);
    mediaHeap = mediaDez(tHeap);
    mediaQuick = mediaDez(tQuick);
    mediaMerge = mediaDez(tMerge);

    cout << "Tempo medio Shell Sort: " << mediaShell << " ms\n";
    cout << "Tempo medio Heap Sort: " << mediaHeap << " ms\n";
    cout << "Tempo medio Quick Sort: " << mediaQuick << " ms\n";
    cout << "Tempo medio Merge Sort: " << mediaMerge << " ms\n";

    return 0;
}
