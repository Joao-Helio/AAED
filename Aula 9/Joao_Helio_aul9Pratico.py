import random

# Gerar 100000 numeros aleatorios em um vetor

vetor = []

for i in range(100000):
    num_aleatorio = random.randint(0,100000)
    vetor.append(num_aleatorio)

# Algoritmo para inserção em árvore vermelho-preto

from rbTreeAB import *

# Execução e medições de tempo

import sys
sys.setrecursionlimit(1000000)

from datetime import datetime

# Árvore Vermelho-Preto - Inserção 100000 elementos

arv_rb = ArvLLRB()

inicioT1 = datetime.now() # início contagem de tempo T1

for i in range(len(vetor)):
    arv_rb.insere(vetor[i])

finalT1 = datetime.now() # fim contagem de tempo T1

# Árvore Vermelho-Preto - Pesquisar elemento 50

inicioT2 = datetime.now() # início contagem de tempo T2

arv_rb.busca(50)

finalT2 = datetime.now() # fim contagem de tempo T2
print(arv_rb.busca(50))

# Árvore Vermelho-Preto - Pesquisar elemento 50000

inicioT3 = datetime.now() # início contagem de tempo T3

arv_rb.busca(50000)

finalT3 = datetime.now() # fim contagem de tempo T3
print(arv_rb.busca(50000))

tempoT1 = finalT1-inicioT1
tempoT2 = finalT2-inicioT2
tempoT3 = finalT3-inicioT3

print('T1 = ' + '%02d.%09d'%(tempoT1.seconds, tempoT1.microseconds))
print('T2 = ' + '%02d.%09d'%(tempoT2.seconds, tempoT2.microseconds))
print('T3 = ' + '%02d.%09d'%(tempoT3.seconds, tempoT3.microseconds))

# Árvore Vermelho-Preto - Calcular alturas das subárvores à esquerda e à direita

arv_rb_altura = arv_rb.altura_subarvores()

# Printar alturas das subárvores à esquerda e à direita
if arv_rb_altura is not None:
    altura_rb_esq, altura_rb_dir = arv_rb_altura
    print("hRBEsq=", altura_rb_esq)
    print("hRBDir=", altura_rb_dir)
else:
    print("A arvore esta vazia.")
