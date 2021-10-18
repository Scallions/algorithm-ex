import sys

fin = open("data/baidu1.in", "r")
sys.stdin = fin

n, m = [int(cc) for cc in sys.stdin.readline().split(" ")]

maps = {}

for i in range(m):
    s, e, c, t = [int(cc) for cc in sys.stdin.readline().split(" ")]
    if s not in maps:
        maps[s] = {}
    maps[s][e] = (c,t)
    if e not in maps:
        maps[e] = {}
    maps[e][s] = (c,t)

res = None

over = set()
over.add(1)
queue = [1]
dis = {}
dis[1] = (0,0)
while queue:
    c = queue.pop(0)
    # print(maps[c])
    for k in maps[c]:
        v = maps[c][k]
        xiaohao = (dis[c][0] + v[0], dis[c][1] + v[1])
        if k not in over:
            dis[k] = xiaohao
            over.add(k)
            queue.append(k)
        else:
            old_xiaohao = dis[k]
            if old_xiaohao > xiaohao:
                dis[k] = xiaohao
                if k not in queue:
                    queue.append(k)

print(f"{dis[n][0]} {dis[n][1]}")