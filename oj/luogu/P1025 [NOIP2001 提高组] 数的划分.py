import sys
import math

cnt = 0

def dfs(n, s, k):
    # print(n, s, k)
    global cnt
    if k == 1:
        if n!= 0 and n>=s:
            cnt += 1
        return
    for i in range(s,math.ceil(n/k)+1):
        dfs(n-i, i, k-1)

if __name__ == '__main__':
    inps = [int(inp) for inp in sys.stdin.readline().strip().split()]
    n = inps[0]
    k = inps[1]
    dfs(n, 1, k)
    print(cnt)