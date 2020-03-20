'''
@Author       : Scallions
@Date         : 2020-03-20 11:25:55
@LastEditors  : Scallions
@LastEditTime : 2020-03-20 11:27:14
@FilePath     : /algorithm-ex/structure/set/tests/test.py
@Description  : 
'''

import pytest


def test_init():
    set1 = set([1,2,3])
    assert 1 in set1
    assert 2 in set1
    assert 3 in set1