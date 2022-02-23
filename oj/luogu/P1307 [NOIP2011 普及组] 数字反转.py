import sys


num = int(sys.stdin.readline().strip())

neg = num < 0

if neg:
    num = -num

res = 0
while num!=0:
    res *= 10
    res += (num%10)
    num //= 10

if neg:
    print(-res)
else:
    print(res)