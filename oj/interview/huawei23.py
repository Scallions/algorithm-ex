import sys
# If you need to import additional packages or classes, please import here.

fin = open("data/huawei23.in", "r")
sys.stdin = fin

def func():
    n = int(sys.stdin.readline())
    nums = [int(i) for i in sys.stdin.readline().split(" ")]
    s = sum(nums)
    if s % 2 == 1:
        print("-1")
        return
    # 背包问题
    dp = [None for i in range(10001)]
    dp[0] = [[]]
    for num in nums:
        for i in range(10001,0,-1):
            if i-num>=0 and dp[i-num] is not None:
                if dp[i] is None:
                    dp[i] = []
                for o in dp[i-num]:
                    t = []
                    t.extend(o)
                    t.append(num)
                    dp[i].append(t)
    if dp[s//2] is not None:
        print(dp[s//2])
    
    # please define the python3 input here. For example: a,b = map(int, input().strip().split())
    # please finish the function body here.
    # please define the python3 output here. For example: print().

if __name__ == "__main__":
    func()
