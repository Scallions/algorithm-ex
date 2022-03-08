import sys



if __name__ == '__main__':
    n = int(sys.stdin.readline().strip())
    nums = [int(inp) for inp in sys.stdin.readline().strip().split(" ")]
    l = len(nums)
    res = []
    for i in range(l):
        c = l-i-1
        if c == 0:
            res.append("")
        elif c == 1:
            res.append("x")
        else:
            res.append(f"x^{c}")
    r = ""
    for i, num in enumerate(nums):
        if num == 0:
            continue
        cur = str(num)+res[i]

        if num == 1 and i!=l-1:
            r += '+'+res[i]
        elif num == -1 and i!=l-1:
            r += '-'+res[i]
        elif num > 0:
            r += "+"+cur
        else:
            r += cur
    if r[0] == '+':
        print(r[1:])
    else:
        print(r)