import sys 
import pytest
sys.path.append("./structure/tree")

from trie import Trie

@pytest.fixture()
def trie():
    trie1 = Trie()
    trie1.insert("hello")
    trie1.insert("world")
    return trie1

def test_search(trie):
    assert trie.search("hello") == True 
    assert trie.search("word") == False 
    assert trie.search("world") == True 

def test_starts_with(trie):
    assert trie.starts_with("hell") == True 
    assert trie.starts_with("word") == False
    
