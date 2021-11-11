ss = "abbccc"
n = len(ss)

dp = [[False for _ in range(n)] for _ in range(n)]
for i in range(n):
    dp[i][i] = True

for l in range(2, n+1):
    for s in range(n-l+1):
        if ss[s] == ss[s+l-1]:
            if l == 2 or dp[s+1][s+l-2]:
                dp[s][s+l-1] = True     
res = []

def dfs(cur, tmp):
    if cur == n:
        res.append(tmp[::])
    for i in range(cur, n):
        if dp[cur][i]:
            tmp.append(ss[cur:i+1])
            dfs(i+1, tmp)
            tmp.pop()
dfs(0, [])

print(res)