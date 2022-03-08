import sys

def duipai(l, r):
    cnt = 0
    for i in range(l, r+1):
        si = str(i)
        for c in si:
            if c == '2':
                cnt += 1
    return cnt

def tcnt(num):
    snum = str(num)
    l = len(snum)
    base = 10**(l-1)
    pre = 0
    scnt = 0
    for i in range(l):
        cnt = 0
        for j in range(1, num//base+1):
            if j == 2:
                cnt += (l-i-1)*base//10 + 1
            elif j == 3:
                cnt += (l-i-1)*base//10 + (base-1)
            else:
                cnt += (l-i-1)*base//10
        scnt += cnt + pre*(num-num%base)
        # scnt += cnt*(pre)
        if num//base == 2:
            pre += 1
        num %= base
        base //= 10
    return scnt


if __name__ == '__main__':
    # for i in range(l, r+1):

    # print(duipai(0,10))
    # print(duipai(0,100))
    # print(duipai(0,1000))
    # print(tcnt(3))
    # print(tcnt(100))
    # print(tcnt(1100))
    # print(tcnt(2))
    # print(tcnt(20))
    # print(tcnt(23))
    l,r = [int(inp) for inp in sys.stdin.readline().split(" ")]
    print(tcnt(r)-tcnt(l-1))