import sys



if __name__ == '__main__':
    inps = [int(inp) for inp in sys.stdin.readline().strip().split(" ")]
    a = inps[0]
    b = inps[1]
    n = inps[2]
    d = b - a
    s = a*n+(n-1)*d*n//2
    print(s)