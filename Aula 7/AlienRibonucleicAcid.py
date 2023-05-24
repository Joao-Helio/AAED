input_str = input()

def contar_conexoes(sequencia):
    contador_B_S = 0
    contador_C_F = 0
    conexoes = 0

    for char in sequencia:
        if char == 'B':
            contador_B_S += 1
        elif char == 'S':
            if contador_B_S > 0:
                contador_B_S -= 1
                conexoes += 1
        elif char == 'C':
            contador_C_F += 1
        elif char == 'F':
            if contador_C_F > 0:
                contador_C_F -= 1
                conexoes += 1

    return conexoes

pilha = list(input_str)
numero_de_conexoes = contar_conexoes(pilha)
print(numero_de_conexoes)
