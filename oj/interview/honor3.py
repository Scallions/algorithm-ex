import sys

# 格式化路径

fin = open("data/honor3.in", "r")
sys.stdin = fin

inps = sys.stdin.readline()
inps = inps.replace('/', ' ')
inps = inps.split(' ')
dirs = []
for dir in inps:
    if dir == '' or dir == '.':
        continue
    if dir == "..":
        # .. 情况
        dirs.pop()
        continue
    else:
        # 有效dir
        dirs.append(dir)
        continue
if len(dirs) == 0:
    print("/")
else:
    res = ""
    for dir in dirs:
        res = res + "/" + dir
    print(res)
