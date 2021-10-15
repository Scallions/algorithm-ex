import sys

fin = open("data/szld2.in", "r")
sys.stdin = fin

s = sys.stdin.readline()
s += s[0]

d = {}
l = 0
res = 0
for i in range(len(s)):
    if s[i] in d and d[s[i]]>=l:
        # 重现重复
        # print(l, i, s[l:i],d)
        res = max(res, i-l)
        l = d[s[i]] + 1
    d[s[i]] = i

print(res)