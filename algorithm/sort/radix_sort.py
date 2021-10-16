nums = [98, 90, 34, 56, 21, 11, 43, 61]
print(nums)

n = len(nums)
max_ = max(nums)
exp = 1

while max_/exp > 0:
    tmp = [0 for i in range(n)]
    buckets = [0 for i in range(10)]
    for num in nums:
        buckets[(num//exp)%10] += 1
    for i in range(9):
        buckets[i+1] += buckets[i]
    for i in range(n-1, -1, -1):
        tmp[buckets[(nums[i]//exp)%10]-1] = nums[i]
        buckets[(nums[i]//exp)%10] -= 1
    nums[::] = tmp
    exp *= 10

print(nums)