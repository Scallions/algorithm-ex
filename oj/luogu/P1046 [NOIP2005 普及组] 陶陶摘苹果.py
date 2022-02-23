import sys


hs = [int(h) for h in sys.stdin.readline().split(" ")]
H = int(sys.stdin.readline())
H += 30

res = 0
for h in hs:
    if h<=H:
        res += 1

print(res)