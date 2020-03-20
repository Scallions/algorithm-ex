'''
@Author       : Scallions
@Date         : 2020-03-20 11:38:52
@LastEditors  : Scallions
@LastEditTime : 2020-03-20 11:43:07
@FilePath     : /algorithm-ex/tests/test_tree.py
@Description  : 
'''

import sys 
import pytest
sys.path.append("./structure/tree")

import tree 

@pytest.fixture()
def get_a_btree():
    return tree.BinaryTree(0)

def test_init():
    root = tree.BinaryTree(6)
    assert root.data == 6
    assert root.left == None
    assert root.right == None
    
def test_set_child():
    root = get_a_btree
    root.left = tree.BinaryTree(5)
    assert root.left.data == 5    