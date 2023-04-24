// ShellSort
// Fonte: Slides da Aula 4 - Profª Lilian Berton

#include <ctime>
#include <chrono>
#include<iostream>
using namespace std;
using namespace chrono;

// vetor com os valores para h
int inc[8] = {10000,6000,1000,300,60,15,3,1};

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
    float tShell[10]; // array para guardar os tempos de execução

    cout << "Tempos de execucao para h = {10000,6000,1000,300,60,15,3,1}\n";

//gerar 10 execuções

    for(int i = 0; i < 10; i++){
        cout << "\nExecucao com vetor aleatorio " << i + 1 << ": \n";

        // gerar vetor com 100000 números aleatórios
        int array[100000];
        srand(time(NULL));
        for(int i = 0; i < 100000; i++) {
            array[i] = rand() % 100000; // gerar um número aleatório entre 0 e 99999
        }

        auto startShell = high_resolution_clock::now();
        shellSort(array, n, inc, 8);
        auto stopShell = high_resolution_clock::now();
        auto durationShell = duration_cast<microseconds>(stopShell - startShell);
        printf("Tempo de Execucao Shell Sort: %.3f ms\n", durationShell.count() / 1000.0);

        tShell[i] = durationShell.count() / 1000.0;

    }
    cout << "\n---------------------------------------------------\n";
    cout << "\nMedia de tempo para vetor aleatorio:\n";

    float mediaShell;

    mediaShell = mediaDez(tShell);

    cout << "Tempo medio Shell Sort: " << mediaShell << " ms\n";

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
        shellSort(array, n, inc, 8);     // ordenar o vetor antes de contar o tempo

        auto startShell = high_resolution_clock::now();
        shellSort(array, n, inc, 8);
        auto stopShell = high_resolution_clock::now();
        auto durationShell = duration_cast<microseconds>(stopShell - startShell);
        printf("Tempo de Execucao Shell Sort: %.3f ms\n", durationShell.count() / 1000.0);

        tShell[i] = durationShell.count() / 1000.0;
    }
    cout << "\n---------------------------------------------------\n";
    cout << "\nMedia de tempo para vetor ordenado crescente:\n";

    mediaShell = mediaDez(tShell);

    cout << "Tempo medio Shell Sort: " << mediaShell << " ms\n";

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
        shellSort(array, n, inc, 8);     // ordenar o vetor antes de contar o tempo
        inverter(array, n);             //inverter o vetor ordenado

        auto startShell = high_resolution_clock::now();
        shellSort(array, n, inc, 8);
        auto stopShell = high_resolution_clock::now();
        auto durationShell = duration_cast<microseconds>(stopShell - startShell);
        printf("Tempo de Execucao Shell Sort: %.3f ms\n", durationShell.count() / 1000.0);

        tShell[i] = durationShell.count() / 1000.0;
    }
    cout << "\n---------------------------------------------------\n";
    cout << "\nMedia de tempo para vetor ordenado decrescente:\n";

    mediaShell = mediaDez(tShell);

    cout << "Tempo medio Shell Sort: " << mediaShell << " ms\n";

    return 0;
}
