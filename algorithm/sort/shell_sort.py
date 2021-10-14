nums = [98,90,34,56,21,11,43,61]
print(nums)
n = len(nums)
gap = n // 2
while gap > 0:
    for i in range(gap, n):
        if nums[i] < nums[i-gap]:
            t = nums[i]
            mi = i-gap
            for k in range(i-gap, -1, -gap):
                if nums[k] > t:
                    nums[k+gap] = nums[k]
                    mi = k
                else:
                    break
            nums[mi] = t
    gap = gap // 2
print(nums)