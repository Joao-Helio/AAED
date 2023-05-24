class AVLNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.height = 1


def insert(root, value):
    if root is None:
        return AVLNode(value)
    elif value < root.value:
        root.left = insert(root.left, value)
    else:
        root.right = insert(root.right, value)

    root.height = 1 + max(get_height(root.left), get_height(root.right))

    balance_factor = get_balance(root)

    if balance_factor > 1 and value < root.left.value:
        return rotate_right(root)

    if balance_factor < -1 and value > root.right.value:
        return rotate_left(root)

    if balance_factor > 1 and value > root.left.value:
        root.left = rotate_left(root.left)
        return rotate_right(root)

    if balance_factor < -1 and value < root.right.value:
        root.right = rotate_right(root.right)
        return rotate_left(root)

    return root


def rotate_left(z):
    y = z.right
    T2 = y.left

    y.left = z
    z.right = T2

    z.height = 1 + max(get_height(z.left), get_height(z.right))
    y.height = 1 + max(get_height(y.left), get_height(y.right))

    return y


def rotate_right(z):
    y = z.left
    T3 = y.right

    y.right = z
    z.left = T3

    z.height = 1 + max(get_height(z.left), get_height(z.right))
    y.height = 1 + max(get_height(y.left), get_height(y.right))

    return y


def get_height(node):
    if node is None:
        return 0
    return node.height


def get_balance(node):
    if node is None:
        return 0
    return get_height(node.left) - get_height(node.right)

root = None

for value in [924, 220, 911, 244, 898, 258, 362, 363, 360, 350]:
    root = insert(root, value)

# def inorder_traversal(root):
#     if root:
#         inorder_traversal(root.left)
#         print(root.value)
#         inorder_traversal(root.right)

# from collections import deque

# def level_order_traversal(root):
#     if root is None:
#         return

#     queue = deque()
#     queue.append(root)

#     while queue:
#         node = queue.popleft()
#         print(node.value)

#         if node.left:
#             queue.append(node.left)
#         if node.right:
#             queue.append(node.right)


# # Print the tree using inorder traversal
# print("Inorder Traversal:")
# inorder_traversal(root)

# # Print the tree using level order traversal
# print("\nLevel Order Traversal:")
# level_order_traversal(root)
