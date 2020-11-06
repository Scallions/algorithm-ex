"""heap 数组实现
二叉堆 最大堆
"""


class heap:
    def __init__(self, n):
        self.data = [None] * n
        self.length = n
        self.heap_length = 0 

    def insert(self, num):
        self.data[self.heap_length] = num
        self.heap_length += 1 
        if self.heap_length == 1:
            return
        # 向上调整
        x = self.heap_length - 1
        while x > 0 and self.data[x] > self.data[(x-1)//2]:
            self.data[x], self.data[(x-1)//2] = self.data[(x-1)//2], self.data[x]
            x = (x-1) // 2

    def pop(self):
        if self.heap_length == 0:
            raise Exception("heap is empty")
        if self.heap_length == 1:
            self.heap_length = 0
            return self.data[0]

        # swap front and end
        r = self.data[0]
        self.data[0] = self.data[self.heap_length-1]
        self.heap_length -= 1
        self.data[self.heap_length] = None

        # 向下调整
        x = 0
        while 2*x+1 < self.heap_length:
            t = x * 2+1
            if t+1 < self.heap_length and self.data[t+1] > self.data[t]:
                t += 1
            if self.data[t] <= self.data[x]:
                break 
            self.data[t], self.data[x] = self.data[x], self.data[t]
            x = t
        return r
    

if __name__ == "__main__":
    h = heap(10)
    h.insert(4)
    h.insert(1)
    h.insert(5)
    h.insert(6)
    print(h.data)
    print(h.pop())
    print(h.data)