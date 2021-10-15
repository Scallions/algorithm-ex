nums = [98,90,34,56,21,11,43,61]
print(nums)
n = len(nums)

def q_sort(nums, s, e):
    l = s
    r = e
    if l>=r:
        return
    mid = nums[(l+r)//2]
    while l < r:
        while nums[l] < mid:
            l += 1
        while nums[r] > mid:
            r -= 1
        if l <= r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
    q_sort(nums, s, r)
    q_sort(nums, l, e)

q_sort(nums, 0, n-1)
print(nums)