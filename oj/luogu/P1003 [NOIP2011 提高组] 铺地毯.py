import sys



if __name__ == '__main__':
    n = int(sys.stdin.readline().strip())
    rows = []
    for i in range(n):
        rows.append([int(inp) for inp in sys.stdin.readline().strip().split(" ")])

    x, y = [int(inp) for inp in sys.stdin.readline().strip().split(" ")]

    res = -1
    for i, row in enumerate(rows):
        if x >= row[0] and x<= row[0]+row[2] and y>=row[1] and y <=row[1]+row[3]:
            res = i+1
    print(res)