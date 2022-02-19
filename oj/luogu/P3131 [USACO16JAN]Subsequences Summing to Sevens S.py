
import sys

fin = open("data/luogu/P3131_12.in")
sys.stdin = fin

inps = sys.stdin.readlines()
inps = inps[1:]
tmps = []
for inp in inps:
    tmps += [int(i) for i in inp.strip().split(" ")]

# inps = [int(inp) for inp in inps]
inps = tmps

for i in range(1, len(inps)):
    inps[i] += inps[i-1]

inps = [inp%7 for inp in inps]

inps = [0] + inps

res = 0
dic = {}
for i in range(len(inps)):
    if inps[i] in dic:
        res = max(res, i-dic[inps[i]])
    else:
        dic[inps[i]] = i


print(res)