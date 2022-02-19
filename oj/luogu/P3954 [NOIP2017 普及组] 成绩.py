
import sys

inps = sys.stdin.readline().split(" ")
inps = [int(inp) for inp in inps]
weights = [0.2, 0.3, 0.5]
s = [inps[i]*weights[i] for i in range(3)]
s = int(sum(s))
print(s)