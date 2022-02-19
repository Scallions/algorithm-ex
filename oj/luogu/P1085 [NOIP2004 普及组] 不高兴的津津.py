


import sys

idx = -1
s = 0

for i in range(7):
    inps = [int(inp) for inp in sys.stdin.readline().split(" ")]
    ss = inps[0]+inps[1]
    if ss >8 and ss > s:
        idx = i
        s = ss

print(f"{idx+1}")