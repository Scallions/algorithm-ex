import sys

fin = open("data/baidu2.in", "r")
sys.stdin = fin

n = int(sys.stdin.readline())
nums = [int(cc) for cc in sys.stdin.readline().split(" ")]

max_left = []
max_right = []

lm = nums[0]
rm = nums[n-1]
for i in range(n):
    max_left.append(max(lm, nums[i]))
    lm = max_left[-1]
    max_right.append(max(rm, nums[n-1-i]))
    rm = max_right[-1]

max_right = list(reversed(max_right))
# print(list(range(n)))
# print(nums)
# print(max_left)
# print(max_right)
for i in range(n):
    lm = max_left[i]
    if lm not in max_right:
        continue
    # 可更改为二分
    idx_r = max_right.index(lm)
    if idx_r <= i+1:
        idx_r = i+2
    while idx_r < n and max_right[idx_r] == lm:
        # 计算最小值
        # 可更改为线段树
        mid_min = min(nums[i+1:idx_r])
        # print(i, idx_r, lm, mid_min)
        if mid_min == lm:
            print(mid_min)
            break
        idx_r += 1
