class TreeNode:
    def __init__(self, value):
        self.value = value  
        self.left = None    
        self.right = None   
        self.ltag = 0       
        self.rtag = 0       


class ThreadedBinaryTree:
    def __init__(self):
        self.root = None
        self.pre = None  

    def insert(self, value):
        if self.root is None:
            self.root = TreeNode(value)
        else:
            self._insert(self.root, value)

    def _insert(self, node, value):
        if value < node.value:
            if node.left is None:
                node.left = TreeNode(value)
            else:
                self._insert(node.left, value)
        else:
            if node.right is None:
                node.right = TreeNode(value)
            else:
                self._insert(node.right, value)

    def in_order_threading(self):
        if self.root is not None:
            self._in_order_threading(self.root)

    def _in_order_threading(self, node):
        if node is not None:
            self._in_order_threading(node.left)
            
            if node.left is None:
                node.left = self.pre
                node.ltag = 1
    
            if self.pre is not None and self.pre.right is None:
                self.pre.right = node
                self.pre.rtag = 1

            self.pre = node
            self._in_order_threading(node.right)

    def in_order_traversal(self):
        node = self.root
        while node is not None:
            
            while node.ltag == 0:
                node = node.left
            
            print(node.value, end=' ')  

            while node.rtag == 1:
                node = node.right
                print(node.value, end=' ')
            
            node = node.right


tree = ThreadedBinaryTree()
values = [1, 2, 3]
for v in values:
    tree.insert(v)


tree.in_order_threading()

tree.in_order_traversal()
