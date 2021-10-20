import sys
# If you need to import additional packages or classes, please import here.

def func():
    n = int(sys.stdin.readline())
    paths = sys.stdin.readline()
    paths = paths.replace("[","").replace("]","").split(",")
    paths = [int(p) for p in paths]
    dd = {}
    dis = {}
    vis = {}
    for i in range(0,len(paths), 2):
        if paths[i] not in dd:
            dd[paths[i]] = set()
        dd[paths[i]].add(paths[i+1])
        dis[paths[i]] = 9999
        dis[paths[i+1]] = 9999
        vis[paths[i]] = False
        vis[paths[i+1]] = False
        if paths[i+1] not in dd:
            dd[paths[i+1]] = set()
        dd[paths[i+1]].add(paths[i])
    dis[n] = 0
    #vis[n] = True
    queue = [n]
    while queue:
        cur = queue.pop(0)
        #vis[cur] = True
        for net in dd[cur]:
            if dis[cur] + 1 < dis[net]:
                dis[net] = dis[cur]+1
                if net not in queue:
                    queue.append(net)
    mx = [1,0]
    for k in dis:
        if dis[k] > mx[1]:
            mx = [k, dis[k]]
        if dis[k] == mx[1]:
            mx[0] = min(mx[0], k)
    print(str(mx[0])+" "+str(mx[1]))
    # please define the python3 input here. For example: a,b = map(int, input().strip().split())
    # please finish the function body here.
    # please define the python3 output here. For example: print().

if __name__ == "__main__":
    func()
