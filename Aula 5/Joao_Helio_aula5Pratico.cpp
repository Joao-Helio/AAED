#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <random>

#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Algoritmo Radix Sort e Counting Sort baseados no que foi desenvolvido pelo professor Juliano Foleis em https://youtu.be/Lb_1R6JGD6o

#define MAX_DAYS 100000

void counting_sort(int *v, int n, int div, int base, int *temp){
    int i, t, c[base], acum = 0;
    memset(c, 0, base * sizeof(int));

    #define DIGIT(X) (X / div) % base

    for(i = 0; i < n; i++){
        c[DIGIT(v[i])]++;
    }

    for(i = 0; i < base; i++){
        t = c[i];
        c[i] = acum;
        acum += t;
    }

    for(i = 0; i < n; i++){
        temp[c[DIGIT(v[i])]] = v[i];
        c[DIGIT(v[i])]++;
    }

    memcpy(v, temp, sizeof(int) * n);
}

void radix_sort_with_count(int *dias, int *meses, int *anos, int n){
    int k, div = 1;
    int temp[MAX_DAYS];

    k = anos[0];
    for(int i = 1; i < n; i++){
        if(anos[i] > k){
            k = anos[i];
        }
    }
    while(k > 0){
        counting_sort(anos, n, div, 10, temp);
        counting_sort(meses, n, div, 10, temp);
        counting_sort(dias, n, div, 10, temp);
        div *= 10;
        k /= 10;
    }
}

void insertion_sort(int V[], int n) {
    for (int i = 1; i < n; i++) {
        int valor_atual = V[i];
        int posicao_atual = i;
        while (posicao_atual > 0 && V[posicao_atual-1] > valor_atual) {
            V[posicao_atual] = V[posicao_atual-1];
            posicao_atual -= 1;
        }
        V[posicao_atual] = valor_atual;
    }
}

void radix_sort_with_insertion(int *dias, int *meses, int *anos, int n){
    int k, div = 1;
    int temp[MAX_DAYS];

    // Sort by year
    k = anos[0];
    for(int i = 1; i < n; i++){
        if(anos[i] > k){
            k = anos[i];
        }
    }
    while(k > 0){
        insertion_sort(anos, n);
        insertion_sort(meses, n);
        insertion_sort(dias, n);
        div *= 10;
        k /= 10;
    }
}

// Função auxiliar para calcular as médias de tempo de 10 execuções

float mediaDez(float arr[]){
    float soma = 0;
    for(int i = 0; i < 10 ; i++){
        soma += arr[i];
    }
    float media = soma / 10;
    return media;
}


int main(){
    struct {        // struct para armazenar as datas
        int dias[100000];
        int meses[100000];
        int anos[100000];
    }data;

    float texecC[10], texecI[10]; //receber os tempos para calcular a media

    random_device rd; // semente do gerador de números aleatórios
    mt19937 gen(rd()); // chama o construtor da classe mt19937 e passa um objeto random_device (rd), que gera a semente inicial para o gerador
    uniform_int_distribution<> dia(1, 31); // distribuição uniforme entre 1 e 31
    uniform_int_distribution<> mes(1, 12); // distribuição uniforme entre 1 e 12
    uniform_int_distribution<> ano(2000, 2022); // distribuição uniforme entre 1 e 31

    // utilizando Counting Sort

    for(int j = 0; j < 10; j++){    // executar o algoritmo 10 vezes para observar a media dos tempos de execução

        for(int i = 0; i < 100000; i++){ // gerar os valores aleatórios
            data.dias[i] = dia(gen);    // preencher o array com dias
            data.meses[i] = mes(gen);   // preencher o array com meses
            data.anos[i] = ano(gen);    // preencher o array com anos
        }

        // Start measuring time
        auto startC = high_resolution_clock::now();

        radix_sort_with_count(data.dias, data.meses, data.anos, 100000);

        // Stop measuring time
        auto stopC = high_resolution_clock::now();
        // Calculate the duration of the execution
        auto durationC = duration_cast<microseconds>(stopC - startC);
        // Print the duration in milliseconds
        printf("Tempo de Execucao do Radix utilizando Counting Sort: %.3f ms\n", durationC.count() / 1000.0);

        texecC[j] = durationC.count() / 1000.0;
    }

    cout << "Tempo medio do Radix utilizando Counting Sort: " << mediaDez(texecC) << " ms\n";

    // utilizando Insertion Sort

    for(int j = 0; j < 10; j++){    // executar o algoritmo 10 vezes para observar a media dos tempos de execução

        for(int i = 0; i < 1000; i++){ // gerar os valores aleatórios
            data.dias[i] = dia(gen);    // preencher o array com dias
            data.meses[i] = mes(gen);   // preencher o array com meses
            data.anos[i] = ano(gen);    // preencher o array com anos
        }

        auto startI = high_resolution_clock::now();

        radix_sort_with_insertion(data.dias, data.meses, data.anos, 100000);

        auto stopI = high_resolution_clock::now();
        auto durationI = duration_cast<microseconds>(stopI - startI);

        printf("Tempo de Execucao do Radix utilizando Insertion Sort: %.3f ms\n", durationI.count() / 1000.0);

        texecI[j] = durationI.count() / 1000.0;
    }

    cout << "Tempo medio do Radix utilizando Insertion Sort: " << mediaDez(texecI) << " ms\n";



    return 0;
}
