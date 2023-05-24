
# criação da árvore
    # criar raiz da árvore -> nó especial que aponta para o primeiro elemento da árvore

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

from collections import deque

def level_order_traversal(root):
    if root is None:
        return

    queue = deque()
    queue.append(root)

    while queue:
        node = queue.popleft()
        print(node.value)

        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

def inorder_traversal(root):
    if root:
        inorder_traversal(root.left)
        print(root.value)
        inorder_traversal(root.right)
        
def insert(root, value):
    if root is None:
        return Node(value)
    else:
        if value < root.value:
            root.left = insert(root.left, value)
        else:
            root.right = insert(root.right, value)
    return root

import random

vetor = [924, 220, 911, 244, 898, 258, 362, 363, 360, 350]

# for i in range(100):
#     num_aleatorio = random.randint(0,100)
#     vetor.append(num_aleatorio)

root = None

for i in range(0, len(vetor)):
    root = insert(root, vetor[i])

print(vetor)

# Print the tree using inorder traversal
print("Inorder Traversal:")
inorder_traversal(root)

# Print the tree using level order traversal
print("\nLevel Order Traversal:")
level_order_traversal(root)

# destruição da árvore
    # percorrer todos os nós da árvore e liberar a memória alocada em cada um