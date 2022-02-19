import sys

inps = [int(inp) for inp in sys.stdin.readline().split(" ")]

inps[1] = str(inps[1])


cnt = 0
for i in range(1, inps[0]+1):
    for c in str(i):
        if inps[1] == c:
            cnt += 1

print(cnt)