from collections import deque


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:

    def __init__(self):
        self.root = None

    def insertNode(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insertHelper(self.root, data)

    def _insertHelper(self, currNode, data):

        if data < currNode.data:
            if currNode.left:
                self._insertHelper(currNode.left, data)
            else:
                currNode.left = Node(data)
        else:
            if currNode.right:
                self._insertHelper(currNode.right, data)
            else:
                currNode.right = Node(data)

    def levelOrderTraversal(self):
        if self.root is None:
            return "Tree is Empty"

        q = deque()
        q.append(self.root)

        while q:
            curr = q.popleft()
            print(curr.data)
            if curr.left:
                q.append(curr.left)
            if curr.right:
                q.append(curr.right)


bst = BST()
bst.insertNode("F")
bst.insertNode("B")
bst.insertNode("G")
bst.insertNode("A")
bst.insertNode("D")

bst.levelOrderTraversal()
