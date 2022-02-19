import sys

fin = open("data/luogu/P1042_2.in")
sys.stdin = fin

inps = sys.stdin.readlines()

inp = ""
for ip in inps:
    inp += ip.strip()

# print(inp)

w = 0
l = 0
for c in inp:
    if c == 'W':
        w += 1
    if c == 'L':
        l +=1
    if c == 'E':
        print(f"{w}:{l}")
        break
    if w >= 11 and w-l>=2:
        print(f"{w}:{l}")
        w = 0
        l = 0
    if l >= 11 and l-w>=2:
        print(f"{w}:{l}")
        w = 0
        l = 0


print()
w = 0
l = 0
for c in inp:
    if c == 'W':
        w += 1
    if c == 'L':
        l +=1
    if c == 'E':
        print(f"{w}:{l}")
        break
    if w >= 21 and w-l>=2:
        print(f"{w}:{l}")
        w = 0
        l = 0
    if l >= 21 and l-w>=2:
        print(f"{w}:{l}")
        w = 0
        l = 0

