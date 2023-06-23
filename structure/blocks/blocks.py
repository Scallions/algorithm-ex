"""
区间求和例子
"""

class Blocks:

    def __init__(self, n, s):
        """
        n: 总大小
        s: 块大小
        """
        self.data = [0 for i in range(n)]
        self.s = s
        self.l = n // s + 1
        self.bases = [0 for i in range(self.l)]
        self.bs = [0 for i in range(self.l)]

    def update(self, l, r, v):
        lbi = (l-1) // self.s
        rbi = (r+1) // self.s
        if lbi == rbi:
            for i in range(l, r+1):
                self.data[i] += v
                self.bs[lbi] += v
        else:
            for bi in range(lbi+1, rbi):  # 去掉头尾的块
                self.bases[bi] += v
                self.bs[bi] += v * self.s
            for i in range(l, self.s*(lbi+1)):
                self.data[i] += v
                self.bs[lbi] += v
            for i in range(self.s*rbi, r+1):
                self.data[i] += v
                self.bs[rbi] += v

    def sum(self, l, r):
        lbi = (l-1) // self.s
        rbi = (r+1) // self.s
        if lbi == rbi:
            return sum(self.data[l:r+1]) + self.bases[lbi]*(l-r+1)
        res = sum(self.bs[lbi+1:rbi])
        res += sum(self.data[l:self.s*(lbi+1)]) + self.bases[lbi]*(self.s - l%self.s-1)
        res += sum(self.data[self.s*rbi:r+1]) + self.bases[rbi]*(r%self.s+1)
        return res 


if __name__ == "__main__":
    blocks = Blocks(20, 4)
    blocks.update(1, 3, 4)
    print(blocks.data)
    blocks.update(5, 15, 2)
    print(blocks.data)
    print(blocks.bases)
    print(blocks.bs)
    print(blocks.sum(0, 10))

        