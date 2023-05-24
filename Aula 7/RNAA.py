def maximize_connections(rnaa):
    connections = 0
    stack = []

    for base in rnaa:
        if base == 'B' or base == 'C':
            stack.append(base)
        else:
            if stack and stack[-1] == 'C':
                stack.pop()
                connections += 1
            else:
                stack.append(base)
    
    return connections

# Process multiple test cases
while True:
    try:
        rnaa = input().strip()
        max_connections = maximize_connections(rnaa)
        print(max_connections)
    except EOFError:
        break
