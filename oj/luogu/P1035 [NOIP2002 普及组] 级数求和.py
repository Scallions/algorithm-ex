import sys

k = int(sys.stdin.readline())

i = 1
s = 0
while s <= k:
    s += 1 / i
    i += 1

print(i-1)