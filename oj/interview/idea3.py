grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]

n = len(grid)
m = len(grid[0])

def dfs(grid, x, y):
    # 消除 x,y 所在岛屿
    grid[x][y] = "0"
    for dx, dy in [[1,0], [0,1], [-1,0], [0,-1]]:
        if x+dx >=0 and x+dx < n and y+dy >=0 and y+dy < m and grid[x+dx][y+dy] == "1":
            dfs(grid, x+dx, y+dy)

cnt = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == "1":
            cnt += 1
            dfs(grid, i, j)
print(cnt)