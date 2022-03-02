import sys



if __name__ == '__main__':
    n, k = [int(inp) for inp in sys.stdin.readline().strip().split(" ")]

    psum = [0]*(n+2)
    psum[1] = 1
    for i in range(2, n+2):
        dt = psum[i-1] - psum[i-1-k] if i-1-k>=0 else psum[i-1] - psum[0]
        psum[i] = psum[i-1] + dt
        psum[i] %= 100003
    print((psum[n+1]-psum[n]) % 100003)