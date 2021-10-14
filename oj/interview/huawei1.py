import sys
from collections import defaultdict


fin = open("data/huawei1.in", "r")
sys.stdin = fin

s = int(sys.stdin.readline())
e = int(sys.stdin.readline())
n = int(sys.stdin.readline())
# gs = [[0 for i in range(n+1)]for j in range(n+1)]
gss = defaultdict(list)
# 读图
for i in range(n):
    n1, n2 = [int(num) for num in sys.stdin.readline().split(" ")]
    if n2 not in gss[n1]:
        gss[n1].append(n2)
        gss[n2].append(n1)
    
def least_open(s, e, gss):
    if s == e:
        return 0
    queue = []
    queue.append(s)
    over = set()
    over.add(s)
    c = 0
    while queue:
        lq = len(queue)
        c += 1
        for i in range(lq):
            node = queue.pop(0)
            for nn in gss[node]:
                if nn == e:
                    return c
                if nn not in over:
                    over.add(nn)
                    queue.append(nn)


print(least_open(s, e, gss))