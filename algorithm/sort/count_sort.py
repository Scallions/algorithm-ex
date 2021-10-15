nums = [11, 9, 11, 13, 19, 14, 16, 14, 8, 17]
print(nums)
max_ = max(nums)
min_ = min(nums)

count = [[] for i in range(min_, max_+1)]

for num in nums:
    count[num-min_].append(num)

res = []
for i in range(max_-min_+1):
    res.extend(count[i])

nums[::] = res
print(nums)