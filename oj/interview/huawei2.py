import sys

fin = open("data/huawei2.in", "r")
sys.stdin = fin

# 大小
n1, n2 = [int(num) for num in sys.stdin.readline().split(" ")]
board = [[[9999,0] for i in range(n2)] for j in range(n1)] # 距离， 个数
# 起点
s1, s2 = [int(num) for num in sys.stdin.readline().split(" ")]
# 终点
e1, e2 = [int(num) for num in sys.stdin.readline().split(" ")]
# 障碍个数
n = int(sys.stdin.readline())
blocks = set()
for i in range(n):
    b1, b2 = [int(num) for num in sys.stdin.readline().split(" ")]
    blocks.add((b1, b2))

dd = [(1,0), (-1,0), (0,1), (0,-1)]

def shortest_path():
    queue = []
    queue.append((s1, s2))
    board[s1][s2][0] = 0
    board[s1][s2][1] = 1
    c = 0
    while queue:
        lq = len(queue)
        c += 1
        for i in range(lq):
            cx, cy = queue.pop(0)
            # print(f"now {c}:{cx}, {cy}, {board[cx][cy]}")
            if cx == e1 and cy == e2:
                return board[cx][cy]
            dis, count = board[cx][cy]
            for dx, dy in dd:
                x = cx + dx
                y = cy + dy
                if (x,y) in blocks:
                    # 障碍
                    continue
                if x < 0 or x >= n1 or y < 0 or y >= n2:
                    # 超出边界
                    continue
                if dis+1 == board[x][y][0]:
                    board[x][y][1] += count
                elif dis+1 < board[x][y][0]:
                    board[x][y] = [dis+1, count]
                else:
                    # 跳过 不能更新
                    continue
                if (x,y) not in queue:
                    queue.append((x, y))

print(" ".join([str(i) for i in shortest_path()[::-1]]))