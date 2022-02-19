import sys

inps = sys.stdin.readline().split(" ")
inps = [int(inp) for inp in inps]

lens = sorted(inps)
# print(lens)

a = lens[0]
b = lens[1]
c = lens[2]

if a+b <=c or a+c <= b or b+c <= a:
    print("Not triangle")
    exit()

ts = a**2 + b**2
ls = c**2
if ts == ls:
    print("Right triangle")
elif ts > ls:
    print("Acute triangle")
else:
    print("Obtuse triangle")

if a == b:
    print("Isosceles triangle")
    if b == c:
        print("Equilateral triangle")