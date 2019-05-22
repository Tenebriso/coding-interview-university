class Node:
    def __init__(self, value):
        self.value = value
        self.right = None
        self.left = None

    def addLeft(self, value):
        if not self.left:
            self.left = Node(value)
            return True
        return False

    def addRight(self, value):
        if not self.right:
            self.right = Node(value)
            return True
        return False

    def removeLeft(self):
        self.left = None

    def removeRight(self):
        self.right = None


class Tree:
    def __init__(self, value):
        self.root = Node(value)

    def add_child(value, root):
        if value > root.value:
            if root.right:
                add_child(value, root.right)
            else:
                root.right = Node(value)
        if value < root.value:
            if root.left:
                add_child(value, root.left)
            else:
                root.left = Node(value)

    def remove_child(value, root):
        pass
