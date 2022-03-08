import sys

res = [
    [0,-1,1,1,-1],
    [1,0,-1,1,-1],
    [-1,1,0,-1,1],
    [-1,-1,1,0,1],
    [1,1,-1,-1,0]
]


if __name__ == '__main__':
    inps = [int(inp) for inp in sys.stdin.readline().strip().split(" ")]
    n = inps[0]
    na = inps[1]
    nb = inps[2]
    ra = [int(inp) for inp in sys.stdin.readline().strip().split(" ")]
    rb = [int(inp) for inp in sys.stdin.readline().strip().split(" ")]
    ta = 0
    tb = 0
    for i in range(n):
        a = ra[i%na]
        b = rb[i%nb]
        if res[a][b] == 1:
            ta += 1
        elif res[a][b] == -1:
            tb += 1

    print(f"{ta} {tb}")