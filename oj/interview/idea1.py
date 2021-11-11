s = "aaaaa"
n = len(s)
res = []
for i in range(n):
    res.append(s[i:i+1])
    # 查找中心
    if i>0 and s[i-1] == s[i]:
        # aa 式中心
        l = 1
        while i-l>=0 and i+l-1<n:
            if s[i-l] == s[i+l-1]:
                res.append(s[i-l:i+l])
            else:
                break
            l += 1
    if i>1 and s[i-2] == s[i]:
        # aba 式中心
        l = 1
        while i-l-1>=0 and i+l-1<n:
            if s[i-l-1] == s[i+l-1]:
                res.append(s[i-l-1:i+l])
            else:
                break
            l += 1
print(res)