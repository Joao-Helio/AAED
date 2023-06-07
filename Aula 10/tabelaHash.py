import random
import time

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(self.size)]
        
    def hash_divisao(self, key):
        return key % self.size
    
    def insercao_divisao(self, key, value):
        index = self.hash_divisao(key)
        self.table[index].append((key, value))
        
    def busca_divisao(self, key):
        index = self.hash_divisao(key)
        for item in self.table[index]:
            if item[0] == key:
                return item[1]
        return None
    
    def hash_sondagem_linear(self, key, aux):
        return (key + aux) % self.size
    
    def insercao_sondagem_linear(self, key, value):
        aux = 0
        index = self.hash_sondagem_linear(key, aux)
        while self.table[index] != []:
            aux += 1
            index = self.hash_sondagem_linear(key, aux)
        self.table[index] = (key, value)
        
    def busca_sondagem_linear(self, key, max_aux):
        aux = 0
        index = self.hash_sondagem_linear(key, aux)
        while self.table[index] != []:
            if self.table[index][0] == key:
                return self.table[index][1]
            aux += 1
            if aux >= max_aux:
                break
            index = self.hash_sondagem_linear(key, aux)
        return None

tempos_insercao_divisao = []
tempos_insercao_sondagem = []
tempos_busca_divisao = []
tempos_busca_sondagem = []

for i in range(1,11):

    print('Execução ' + str(i) + ':')
        
    # Gerar 100.000 elementos aleatórios
    elements = [random.randint(0, 100000) for _ in range(100000)]

    # Tempos de inserção de elementos

    # Criar a tabela hash
    hash_divisao = HashTable(50000)

    # Iniciar a contagem do tempo
    divisao_inicio = time.time()

    # Inserir os elementos na tabela com função hash de divisão
    for element in elements:
        hash_divisao.insercao_divisao(element, element)

    # Calcular o tempo total de inserção
    tempo_divisao = time.time() - divisao_inicio

    print("Tempo total de inserção com função hash divisão:", tempo_divisao, "segundos")

    # Criar a tabela hash
    hash_sondagem = HashTable(100000)

    # Iniciar a contagem do tempo
    sondagem_inicio = time.time()

    # Inserir os elementos na tabela hash
    for element in elements:
        hash_sondagem.insercao_sondagem_linear(element, element)

    # Calcular o tempo total de inserção
    tempo_sondagem = time.time() - sondagem_inicio


    print("Tempo total de inserção com sondagem linear:", tempo_sondagem, "segundos")

    # Tempos de Busca

    busca_divisao_inicio = time.perf_counter()

    # Pesquisar o elemento 10000 na tabela com função hash de divisão
    hash_divisao.busca_divisao(10000)

    tempo_busca_divisao = time.perf_counter() - busca_divisao_inicio


    print("Tempo total de busca com função hash divisão:", tempo_busca_divisao, "segundos")

    busca_sondagem_inicio = time.perf_counter()

    # Pesquisar o elemento 10000 na tabela hash Sondagem Linear
    hash_sondagem.busca_sondagem_linear(10000, 100000000)

    tempo_busca_sondagem = time.perf_counter() - busca_sondagem_inicio


    print("Tempo total de busca com sondagem linear:", tempo_busca_sondagem, "segundos")

    tempos_insercao_divisao.append(tempo_divisao)
    tempos_insercao_sondagem.append(tempo_sondagem)
    tempos_busca_divisao.append(tempo_busca_divisao)
    tempos_busca_sondagem.append(tempo_busca_sondagem)

    print('\n')

media_insercao_divisao = sum(tempos_insercao_divisao)/len(tempos_insercao_divisao)
media_insercao_sondagem = sum(tempos_insercao_sondagem)/len(tempos_insercao_sondagem)
media_busca_divisao = sum(tempos_busca_divisao)/len(tempos_busca_divisao)
media_busca_sondagem = sum(tempos_busca_sondagem)/len(tempos_busca_sondagem)

print("Média dos tempos de inserção com função hash divisão:", media_insercao_divisao, "segundos")
print("Média dos tempos de inserção com sondagem linear:", media_insercao_sondagem, "segundos")
print("Média dos tempos de busca com função hash divisão:", media_busca_divisao, "segundos")
print("Média dos tempos de busca com sondagem linear:", media_busca_sondagem, "segundos")