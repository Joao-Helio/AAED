import random

# Gerar 100000 numeros aleatorios em um vetor

vetor = []

for i in range(100000):
    num_aleatorio = random.randint(0,100000)
    vetor.append(num_aleatorio)

#algoritmo para busca sequencial:
    
def busca_sequencial(lista, element, index=0):
    if index == len(lista):
        # elemento nao encontrado
        return -1
    elif lista[index] == element:
        # elemento encontrado na posicao atual
        return index
    else:
        # recursao -> proximo indice
        return busca_sequencial(lista, element, index+1)

#algoritmo para busca binaria:
    
def busca_binaria(lista, element, start=0, end=None):
    if end is None:
        end = len(lista) - 1

    if end < start:
        # element nao encontrado
        return -1

    mid = (start + end) // 2

    if lista[mid] == element:
        # posicao do meio da lista
        return mid
    elif element < lista[mid]:
        # recursao - metade esquerda da lista
        return busca_binaria(lista, element, start, mid-1)
    else:
        # recursao - metade direita da lista
        return busca_binaria(lista, element, mid+1, end)

# Algoritmo para ordenação do vetor com QuickSort

# Algoritmo para QuickSort de Andre Backes em: https://www.facom.ufu.br/~backes/wordpress/proj_ordenacao.py

def particiona(V, inicio, final):
    esq = inicio
    dir = final
    pivo = V[inicio]
    while(esq < dir):
        while(esq <= final and V[esq] <= pivo):
            esq = esq + 1

        while(dir >= 0 and V[dir] > pivo):
            dir = dir - 1

        if(esq < dir):
            aux = V[esq]
            V[esq] = V[dir]
            V[dir] = aux
            
    V[inicio] = V[dir]
    V[dir] = pivo
    return dir

def quickSort(V, inicio, fim):
    if(fim > inicio):
        pivo = particiona(V, inicio, fim)
        quickSort(V, inicio, pivo-1)
        quickSort(V, pivo+1, fim)

# Algoritmo para inserção em árvore binária

from binaryTreeAB import *

# Algoritmo para inserção em árvore AVL

from avlTreeAB import *

# Execução e medições de tempo

import sys
sys.setrecursionlimit(1000000)

from datetime import datetime

# Vetor aleatório - Inserção 100000 elementos

vetaux = []

inicioT1 = datetime.now() # início contagem de tempo T1

for i in range(0, len(vetor)):
    vetaux.append(vetor[i])

finalT1 = datetime.now() # fim contagem de tempo T1

# Vetor aleatório - Pesquisar elemento 50

inicioT2 = datetime.now() # início contagem de tempo T2

busca_sequencial(vetaux, 50)

finalT2 = datetime.now() # fim contagem de tempo T2

# Vetor aleatório - Pesquisar elemento 50000

inicioT3 = datetime.now() # início contagem de tempo T3

busca_sequencial(vetaux, 50000)

finalT3 = datetime.now() # fim contagem de tempo T3

tempoT1 = finalT1-inicioT1
tempoT2 = finalT2-inicioT2
tempoT3 = finalT3-inicioT3

print('T1 = ' + '%02d.%06d'%(tempoT1.seconds, tempoT1.microseconds))
print('T2 = ' + '%02d.%06d'%(tempoT2.seconds, tempoT2.microseconds))
print('T3 = ' + '%02d.%06d'%(tempoT3.seconds, tempoT3.microseconds))

# Vetor ordenado - Inserção 100000 elementos

vetor_ordenado = []

inicioT4 = datetime.now() # início contagem de tempo T4

for i in range(len(vetor)):
    vetor_ordenado.append(vetor[i])

quickSort(vetor_ordenado, 0, len(vetor) - 1)

finalT4 = datetime.now() # fim contagem de tempo T4

# Vetor ordenado - Pesquisar elemento 50

inicioT5 = datetime.now() # início contagem de tempo T5

busca_binaria(vetor_ordenado, 50)

finalT5 = datetime.now() # fim contagem de tempo T5

# Vetor ordenado - Pesquisar elemento 50000

inicioT6 = datetime.now() # início contagem de tempo T6

busca_binaria(vetor_ordenado, 50000)

finalT6 = datetime.now() # fim contagem de tempo T6

tempoT4 = finalT4-inicioT4
tempoT5 = finalT5-inicioT5
tempoT6 = finalT6-inicioT6

print('T4 = ' + '%02d.%06d'%(tempoT4.seconds, tempoT4.microseconds))
print('T5 = ' + '%02d.%06d'%(tempoT5.seconds, tempoT5.microseconds))
print('T6 = ' + '%02d.%06d'%(tempoT6.seconds, tempoT6.microseconds))

# print(busca_binaria(vetor_ordenado, 50000))
# print(busca_binaria(vetor_ordenado, 50))

# Árvore Binária - Inserção 100000 elementos

arv_binaria = ArvBin()

inicioT7 = datetime.now() # início contagem de tempo T7

for i in range(len(vetor)):
    arv_binaria.insere(vetor[i])

finalT7 = datetime.now() # fim contagem de tempo T7

# Árvore Binária - Pesquisar elemento 50

inicioT8 = datetime.now() # início contagem de tempo T8

arv_binaria.busca(50)

finalT8 = datetime.now() # fim contagem de tempo T8

# Árvore Binária - Pesquisar elemento 50000

inicioT9 = datetime.now() # início contagem de tempo T9

arv_binaria.busca(50000)

finalT9 = datetime.now() # fim contagem de tempo T9

tempoT7 = finalT7-inicioT7
tempoT8 = finalT8-inicioT8
tempoT9 = finalT9-inicioT9

print('T7 = ' + '%02d.%06d'%(tempoT7.seconds, tempoT7.microseconds))
print('T8 = ' + '%02d.%06d'%(tempoT8.seconds, tempoT8.microseconds))
print('T9 = ' + '%02d.%06d'%(tempoT9.seconds, tempoT9.microseconds))

# Árvore AVL - Inserção 100000 elementos

arv_avl = ArvAVL()

inicioT10 = datetime.now() # início contagem de tempo T10

for i in range(len(vetor)):
    arv_avl.insere(vetor[i])

finalT10 = datetime.now() # fim contagem de tempo T10

# Árvore AVL - Pesquisar elemento 50

inicioT11 = datetime.now() # início contagem de tempo T11

arv_avl.busca(50)

finalT11 = datetime.now() # fim contagem de tempo T11

# Árvore AVL - Pesquisar elemento 50000

inicioT12 = datetime.now() # início contagem de tempo T12

arv_avl.busca(50000)

finalT12 = datetime.now() # fim contagem de tempo T12

tempoT10 = finalT10-inicioT10
tempoT11 = finalT11-inicioT11
tempoT12 = finalT12-inicioT12

print('T10 = ' + '%02d.%06d'%(tempoT10.seconds, tempoT10.microseconds))
print('T11 = ' + '%02d.%06d'%(tempoT11.seconds, tempoT11.microseconds))
print('T12 = ' + '%02d.%06d'%(tempoT12.seconds, tempoT12.microseconds))
