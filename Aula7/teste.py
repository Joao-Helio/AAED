import sys

while True:
    try:
        lista = sys.stdin.readline().strip()
        if not lista:
            break

        corresp = []
        conexoes = 0

        pilha = []

        for i in lista:
            if i == 'S':
                    corresp.append("B")
            elif i == 'B':
                    corresp.append("S")
            elif i == 'C':
                    corresp.append("F")
            elif i == 'F':
                    corresp.append("C")

        i = 0
        while i < len(lista):
            if not pilha or  pilha[-1] != corresp[i]:
                pilha.append(lista[i])
            else:
                while i < len(lista) and pilha and corresp[i] == pilha[-1]:
                    conexoes += 1
                    pilha.pop()
                    i += 1
                continue
            
            i += 1

        print(conexoes)
    except ValueError:
        print("Sorry, wrong input")
        continue
