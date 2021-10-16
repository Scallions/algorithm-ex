nums = [98, 90, 34, 56, 21, 11, 43, 61]
print(nums)

n = len(nums)

def down(i, l):
    while 2*i+1 < l:
        t = 2*i+1
        if t+1<l and nums[t+1]>nums[t]: # 最大子元素
            t += 1
        if nums[t] <= nums[i]:
            # 不能交换跳出
            break
        else:
            nums[t], nums[i] = nums[i], nums[t]
            i = t

## 建堆 采用向下调整
for i in range(n//2-1,-1,-1):
    down(i, n)

## 取元素
res = []
for i in range(n-1):
    nums[0], nums[n-1-i] = nums[n-1-i], nums[0]
    down(0, n-i-1)

print(nums)
