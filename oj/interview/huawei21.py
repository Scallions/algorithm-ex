import sys
# If you need to import additional packages or classes, please import here.

def func():
    n = int(sys.stdin.readline())
    t = [int(i) for i in sys.stdin.readline().split(" ")]
    nums = []
    for i in range(len(t)):
        nums.append((t[i], i))
    m = int(sys.stdin.readline())
    codes = [int(i) for i in sys.stdin.readline().split(" ")]
    # please define the python3 input here. For example: a,b = map(int, input().strip().split())
    # please finish the function body here.
    # please define the python3 output here. For example: print().
    nums = sorted(nums, reverse=True)
    d = {}
    for i in range(len(nums)):
        d[nums[i][1]] = i+1
    # print(d)
    s = 0
    for code in codes:
        if code >= n:
            print("-1")
            return
        s += d[code]
    print(s)

if __name__ == "__main__":
    func()
