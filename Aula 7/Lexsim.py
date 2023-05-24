import sys

def avalia_expressao(expressao):
    # Dicionario para ordem de prioridade dos operadores
    operadores = {'^': 6, '*': 5, '/': 5, '+': 4, '-': 4, '>': 3, '<': 3, '=': 3, '#': 3, '.': 2, '|': 1}

    output = ''
    pilha = []
    operadores_validos = {'^', '*', '/', '+', '-', '>', '<', '=', '#', '.', '|'}
    operandos_validos = set('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789')
    operador_esperado = False  # identificar se é esperado um operador

    for char in expressao:
        if char.isalnum():
            output += char
            operador_esperado = True
        elif char == '(':
            pilha.append(char)
            operador_esperado = False
        elif char == ')':
            while pilha and pilha[-1] != '(':
                output += pilha.pop()
            if pilha and pilha[-1] == '(':
                pilha.pop()
                operador_esperado = True
            else:
                return "Syntax Error!"
        elif char in operadores_validos:
            if operador_esperado:
                while pilha and pilha[-1] != '(' and operadores[char] <= operadores.get(pilha[-1], 0):
                    output += pilha.pop()
                pilha.append(char)
                operador_esperado = False
            else:
                return "Syntax Error!"
        else:
            return "Lexical Error!"

    while pilha:
        if pilha[-1] == '(' or pilha[-1] == ')':
            return "Syntax Error!"
        output += pilha.pop()

    # Verificar operandos invalidos
    for char in output:
        if char.isalnum() and char not in operandos_validos:
            return "Lexical Error!"

    return output


while True:
    try:
        expressao = sys.stdin.readline().strip()
        if not expressao:
            break

        print(avalia_expressao(expressao))

    except ValueError:
        print("Sorry, wrong input")
        continue



