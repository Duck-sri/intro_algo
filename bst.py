#!/opt/homebrew/bin/python3 env

# Set abstract ds, which contains a element only one and all elements are sorted.
# An iterator is available

# Set is implemented using BST

import random

class Node:
    
    def __init__(self,val=None,left=None,right=None):
        self.val = val
        self.right = right
        self.left = left

    def __nonzero__(self):
        return (self.right!=None or self.left!=None)


class BST:

    def __init__(self):
        self.root = None

    def append(self,val):

        tmpNode = Node(val)
        if (self.root is None):
            self.root = tmpNode
            return

        tmpRoot = self.root
        while(True):
            if (val <= tmpRoot.val):
                if (tmpRoot.left is None):
                    tmpRoot.left = tmpNode
                    return
                else:
                    tmpRoot = tmpRoot.left
            else:
                if (tmpRoot.right is None):
                    tmpRoot.right = tmpNode
                    return
                else:
                    tmpRoot = tmpRoot.right

    def insert(self,val,insRoot,root=None):
        if (root is None):
            root = self.root

        if (root == insRoot):
            tmpNode = Node(val)
            if(val <= root.left.val):
                tmpLeft = root.left
                tmpNode.right = root.right
                tmpNode.left = tmpLeft
                root.left = tmpNode
            else:
                tmpRight = root.right
                tmpNode.left = root.left
                tmpNode.right = tmpRight
                root.right = tmpNode
            return

        if (val <= root.left.val):
            self.insert(val,insRoot,root.left)
        else:
            self.insert(val,insRoot,root.right)



    def view(self,root=None):
        if (root is None):
            root = self.root

        print(f"{root.val} -> left: {root.left.val if root.left else '-'} -> right: {root.right.val if root.right else '-'}")
        if root.left is not None:
            self.view(root.left)
        if root.right is not None:
            self.view(root.right)

    def find(self,key,root=None):
        if (root is None):
            root = self.root
        if (root.left is None) and (root.right is None):
            return None
        if (key == root.val):
            return root

        if (key <= root.val):
            return self.find(key,root.left)
        else:
            return self.find(key,root.right)


def ResPlanner(BST):
    def __init__(self,k=3):
        self.k = k
        super(ResPlanner,self).__init__()

    def append(self,val):
        tmpNode = Node(val)
        if (self.root is None):
            self.root = tmpNode
            return

        tmpRoot = self.root
        while(True):
            if (val <= tmpRoot.val):
                if (tmpRoot.left is None ):
                    if (abs(tmpRoot.left.val - val) <= self.k):
                        tmpRoot.left = tmpNode
                    return
                else:
                    tmpRoot = tmpRoot.left
            else:
                if (tmpRoot.right is None ):
                    if (abs(tmpRoot.right.val - val) <= self.k):
                        tmpRoot.right = tmpNode
                    return
                else:
                    tmpRoot = tmpRoot.right



if __name__ == "__main__":
    tree = BST()

    added = list()

    for i in range(10):
        tmp = random.randint(0,100)
        tree.append(tmp)
        added.append(tmp)
        print(tmp,end=' ')

    print()

    tree.view()
    print()

    randidx = random.randint(0,len(added)-1)
    got_pos = tree.find(added[randidx])
    if got_pos is not None:
        print(randidx,got_pos.val)
    else:
        print("Not found")
