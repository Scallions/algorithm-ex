import sys


inps = [int(inp) for inp in sys.stdin.readline().split(" ")]

n = inps[0]
m = inps[1]
k = inps[2]

cnt = []
for i in range(k):
    cnt.append(set())

for i in range(n):
    inps = [int(inp) for inp in sys.stdin.readline().split(" ")]
    for i, t in enumerate(inps):
        cnt[t-1].add(i)


for c in cnt:
    print(f"{len(c)} ", end="")