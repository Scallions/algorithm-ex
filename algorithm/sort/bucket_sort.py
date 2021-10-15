nums = [98, 90, 34, 56, 21, 11, 43, 61]

print(nums)

max_ = max(nums)
min_ = min(nums)
n = len(nums)
bucket_num = (max_-min_)//n + 1
bucket = [[] for i in range(bucket_num)]

# 入桶
for num in nums:
    k = (num-min_)//n
    bucket[k].append(num)

res = []
for i in range(bucket_num):
    sorted(bucket[i])
    res.extend(bucket[i])
nums[::] = res
print(nums)