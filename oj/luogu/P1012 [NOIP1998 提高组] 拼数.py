import sys
import functools

n = int(sys.stdin.readline())
nums =  sys.stdin.readline().strip().split(' ')


def cmp(a, b):
    if (a+b) < (b+a):
        return 1
    else:
        return -1

# nums.sort(key=functools.cmp_to_key(cmp))
nums = sorted(nums, key=functools.cmp_to_key(cmp))

print("".join(nums))