import sys
import functools

@functools.lru_cache(30**3)
def w(a: int, b:int, c:int) -> int:
    """奇怪的递归函数
    >>> w(1, 1, 1)
    2
    >>> w(2,2,2)
    4

    Args:
        a (int): a
        b (int): b
        c (int): c

    Returns:
        int: 结果
    """
    if a<=0 or b<=0 or c<= 0:
        return 1
    if a>20 or b>20 or c>20:
        return w(20,20,20)
    if a<b and b<c:
        return w(a, b, c-1) + w(a,b-1,c-1) - w(a,b-1,c)
    return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)


if __name__ == '__main__':
    while True:
        inp = sys.stdin.readline().strip()
        # print(inp)
        if inp == '-1 -1 -1':
            break
        nums = [int(i) for i in inp.split(' ')]
        print(f"w({', '.join(inp.split(' '))}) = {w(*nums)}")