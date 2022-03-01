import sys

n = int(sys.stdin.readline())

res = [1]*(n+1)
psum = [1]*(n+1)

for i in range(2, n+1):
    res[i] = 1 + psum[i//2]
    psum[i] = psum[i-1] + res[i]
    # print(res[i], psum[i])

print(res[n])