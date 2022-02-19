import sys

n = int(sys.stdin.readline())

s = 0
i = 1
while s<n:
    s += i
    i += 1
if i%2 != 0:
    t = s-n+1
    print(f"{i-t}/{t}")
else:
    t = s-n+1
    print(f"{t}/{i-t}")