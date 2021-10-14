nums = [98,90,34,56,21]
print(nums)
n = len(nums)
for i in range(1, n):

    for j in range(i):
        if nums[i] < nums[j]:
            t = nums[i]
            for k in range(i, j, -1):
                nums[k] = nums[k-1]
            nums[j] = t
print(nums)