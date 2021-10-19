
class Trie:
    def __init__(self):
        self.children = [None for i in range(26)]
        self.isEnd = False

    def insert(self, word):
        cur = self
        for c in word:
            if cur.children[ord(c)-ord('a')] is None:
                cur.children[ord(c)-ord('a')] = Trie()
            cur = cur.children[ord(c)-ord('a')]
        cur.isEnd = True

    def search(self, word):
        cur = self
        for c in word:
            if cur.children[ord(c)-ord('a')] is None:
                return False
            cur = cur.children[ord(c)-ord('a')]
        return cur.isEnd

    def starts_with(self, prefix):
        cur = self
        for c in prefix:
            if cur.children[ord(c)-ord('a')] is None:
                return False
            cur = cur.children[ord(c)-ord('a')]
        return True


if __name__ == '__main__':
    trie = Trie()
    trie.insert("hello")
    trie.insert("world")
    print(trie.search("hello"))
    print(trie.search("word"))
    print(trie.starts_with("hell"))