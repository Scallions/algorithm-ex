


import sys


mom = 0
me = 0

for i in range(12):
    inp = int(sys.stdin.readline())
    me = me + 300 - inp
    if me < 0:
        print(f"-{i+1}")
        exit()
    mom += (me-me%100)
    me = me % 100

print(f"{me+int(mom*1.2)}")