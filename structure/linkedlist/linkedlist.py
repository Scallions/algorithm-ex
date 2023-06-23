'''
@Author       : Scallions
@Date         : 2020-03-20 11:01:35
@LastEditors  : Scallions
@LastEditTime : 2020-03-20 11:19:04
@FilePath     : /algorithm-ex/structure/linkedlist/linkedlist.py
@Description  : 单向链表
'''


class Node:
    def __init__(self, data, next=None):
        super().__init__()
        self.data = data
        self.next = next

    def __repr__(self):
        return super().__repr__()
        return f"Node: {str(self.data)}"

    def insert(self, v):
        next_node = Node(v)
        self.next = next_node
        return next_node

    def delete(self):
        if self.next:
            self.data = self.next.data
            self.next = self.next.next
            return self
        


if __name__ == "__main__":
    node = Node(1)
    node.insert(2).insert(3).insert(4)
    while node:
        print(node.data)
        node = node.next
    