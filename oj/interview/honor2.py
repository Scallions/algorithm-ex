import sys

fin = open("data/honor2.in", "r")
sys.stdin = fin

n = int(sys.stdin.readline())
inps = sys.stdin.readline()
nums = [int(inp) for inp in inps.split(" ")]
times = []
for i in range(len(nums)//2):
    times.append((nums[2*i], nums[2*i+1]))
times.sort(key=lambda x: x[1])
res = 0
e = -2e9
for time in times:
    if time[0] > e:
        res += 1
        e = time[1]

print(res)

# temp = []
# for i in range(len(times)):
#     if i == 0 or times[i-1][0] != times[i][0]:
#         temp.append(times[i])
# times = temp

# dp = [0,-1,0,-1]
# for time in times:
#     temp = dp
#     # 以这个结尾的 最长长度
#     dp[1] = time[1]
#     t = 1
#     if time[0] > temp[1]:
#         t = max(t, temp[0]+1)
#     if time[0] > temp[3]:
#         t = max(t, temp[2]+1)
#     dp[0] = t
#     # 不以这个结尾的最长长度 和 结尾
#     if temp[0] == temp[2]:
#         dp[2] = temp[0]
#         dp[3] = min(temp[1], temp[3])
#     elif temp[0] > temp[2]:
#         dp[2:] = temp[0:2]
#     else:
#         dp[2:] = temp[2:]

# print(max(dp[0], dp[2]))