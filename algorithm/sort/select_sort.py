nums = [98,90,34,56,21]
print(nums)
n = len(nums)
for i in range(n):
    midx = i
    for j in range(i, n):
        if nums[j] < nums[midx]:
            midx = j 
    nums[i], nums[midx] = nums[midx], nums[i]
print(nums)