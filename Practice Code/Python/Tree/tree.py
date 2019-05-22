import functools
import operator
from collections import deque

class Node:
    def __init__(self, value):
        self.value = value
        self.neighbors = []

    def addNeighbor(self, value):
        self.neighbors.append(Node(value))

    def removeNeighbor(self, value):
        for neighbor in self.neighbors:
            if neighbor.value == value:
                self.neighbors.remove(neighbor)
                return
    def __repr__(self):
        return str(self.value)

class Tree:

    def __init__(self, value):
        self.root = Node(value)

    def add_node(self, value, parent):
        parent_node = self.find_node(parent, self.root)
        parent_node.addNeighbor(value)

    def find_node(self, value, root):
        if root:
            if root.value == value:
                return root
            for neighbor in root.neighbors:
                child_found = self.find_node(value, neighbor)
                if child_found:
                    return child_found
        return None

    def find_parent(self, value, root):
        if root:
            if value in [x.value for x in root.neighbors]:
                return root
            for neighbor in root.neighbors:
                found = self.find_parent(value, neighbor)
                if found:
                    return found
        return None


    def remove_node(self, value):
        parent = self.find_parent(value, self.root)
        node = self.find_node(value, self.root)
        if parent:
            parent.neighbors.extend(node.neighbors)
            parent.removeNeighbor(value)
            return True
        else:
            # remove root
            if node:
                # has no children
                if not node.neighbors:
                    self.root = None
                    return True
                else:
                    new_root = node.neighbors[0]
                    new_root.neighbors.extend([x for x in node.neighbors
                                               if x.value != new_root.value])
                    self.root = new_root
                    return True

        return False


    def height(self, root):
        if not root:
            return 0
        heights = [self.height(x) for x in root.neighbors]
        if not heights:
            return 1
        return 1 + max(heights)

    def size(self, root):
        if not root:
            return 0
        sizes = [self.size(x) for x in root.neighbors]
        if not sizes:
            return 1
        return 1 + functools.reduce(operator.add, sizes)

    def bft(self, root):
        if not root:
            return
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            print(node.value)
            for neighbor in node.neighbors:
                q.append(neighbor)

    def dft(self, root):
        if not root:
            return
        q = deque()
        q.append(root)
        while q:
            node = q.pop()
            print(node.value)
            for neighbor in node.neighbors:
                q.append(neighbor)


if __name__ == '__main__':
    t = Tree('A')
    t.add_node('B', 'A')
    t.add_node('C', 'A')
    t.add_node('D', 'B')
    t.add_node('E', 'B')
    t.add_node('F', 'C')
    t.add_node('G', 'C')
    print("Level order traversal: ")
    t.bft(t.root)
    print("Depth first traversal: ")
    t.dft(t.root)
    print("Find node E: {}".format(t.find_node('E', t.root)))
    print("Find node X: {}".format(t.find_node('X', t.root)))
    print("Height: {}".format(t.height(t.root)))
    print("Size: {}".format(t.size(t.root)))
    print("{} is parent of C".format(t.find_parent('C', t.root)))
    if t.remove_node('A'):
        print("Successfully removed node A")
    else:
        print("No node A found")
    t.bft(t.root)
    print("{} is parent of C".format(t.find_parent('C', t.root)))
    if t.remove_node('C'):
        print("Successfully removed node C")
    else:
        print("No node C found")
    t.bft(t.root)


