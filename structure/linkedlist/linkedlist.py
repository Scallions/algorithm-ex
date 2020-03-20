'''
@Author       : Scallions
@Date         : 2020-03-20 11:01:35
@LastEditors  : Scallions
@LastEditTime : 2020-03-20 11:19:04
@FilePath     : /algorithm-ex/structure/linkedlist/linkedlist.py
@Description  : 
'''


class Node:
    def __init__(self, data, next=None):
        super().__init__()
        self.data = data
        self.next = next

    def __repr__(self):
        return super().__repr__()
        return f"Node: {str(self.data)}"


if __name__ == "__main__":
    pass