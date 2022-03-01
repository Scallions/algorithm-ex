import sys



cnt = 0
inps = None

def check(s: int) -> bool:
    """检查s是否为素数

    Args:
        s (int): 要检查的数

    Returns:
        bool: 是否为素数

    >>> check(1)
    False
    >>> check(2)
    True
    >>> check(3)
    True
    >>> check(10)
    False
    """
    if s == 1:
        return False
    for i in range(2, s//2):
        if s % i == 0:
            return False
    return True

def dps(s, start, k):
    global cnt
    if k == 0:
        # print(s)
        if check(s):
            cnt += 1
        return
    for i in range(start, len(inps)):
        c = inps[i]
        dps(s+c, i+1, k-1)

if __name__ == '__main__':
    inps = [int(inp) for inp in sys.stdin.readline().split(" ")]
    n = inps[0]
    k = inps[1]

    inps = [int(inp) for inp in sys.stdin.readline().split(" ")]

    dps(0, 0, k)

    print(cnt)