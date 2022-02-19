
import sys


n = int(sys.stdin.readline())

res = 10**9

import math

for i in range(3):
    ts = [int(i) for i in sys.stdin.readline().split(" ")]
    p = math.ceil(n/ts[0]) * ts[1]
    res = min(p, res)

print(res)