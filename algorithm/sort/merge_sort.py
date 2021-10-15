nums = [98,90,34,56,21,11,43,61]
print(nums)
n = len(nums)

def merge_sort(nums, s, e):
    if s >= e:
        return 
    m = (s+e) // 2
    merge_sort(nums, s, m)
    merge_sort(nums, m+1, e)
    merge(nums, s, m, e)

def merge(nums, s, m, e):
    l = s
    r = m+1
    temp = []
    while l<=m and r <= e:
        if nums[l] > nums[r]:
            temp.append(nums[r])
            r += 1
        else:
            temp.append(nums[l])
            l += 1
    if l<=m:
        temp.extend(nums[l:m+1])
    if r<=e:
        temp.extend(nums[r:e+1])
    nums[s:e+1] = temp

merge_sort(nums, 0, n-1)
print(nums)