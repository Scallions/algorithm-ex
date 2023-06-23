
class Dsu:

    def __init__(self, n):
        self.pa = [i for i in range(n)]

    def find(self, x):
        if self.pa[x] != x:
            self.pa[x] = self.find(self.pa[x])
        return self.pa[x]

    def union(self, x, y):
        self.pa[self.find(x)] = self.find(y)


if __name__ == "__main__":
    dsu = Dsu(10)
    dsu.union(0, 1)
    dsu.union(2, 3)
    dsu.union(3, 4)
    print(dsu.pa)
    dsu.union(1, 2)
    print(dsu.pa)
    dsu.find(0)
    print(dsu.pa)