nums = [98,90,34,56,21]
print(nums)
n = len(nums)
for i in range(n-1):
    for j in range(n-1-i):
        if nums[j] > nums[j+1]:
            nums[j], nums[j+1] = nums[j+1], nums[j]
print(nums)