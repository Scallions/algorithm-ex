
import sys

inps = sys.stdin.readline().split(" ")
inps = [int(inp) for inp in inps]
s = inps[0]
v = inps[1]
t = s/v
import math
t = math.ceil(t)
t += 10

h = t // 60
m = t % 60

if m == 0:
    m = 0
    h -= 1
else:
    m = 60 - m
h = 7 - h
if h < 0:
    h += 24

print(f"{h:02d}:{m:02d}")