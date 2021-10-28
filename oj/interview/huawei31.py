
l = 0
r = 100000

# 对拍
count  = 0
for i in range(l, r+1):
	if "4" in str(i) or "18" in str(i):
		continue
	count += 1
print(count)


## 稍微优化
i = l 
count = 0
while i < r+1:
	if "4" in str(i):
		# 跳过4
		length = len(str(i)) - str(i).index("4") - 1
		i += 10 ** length
		continue
	if "18" in str(i):
		# 跳过18
		length = len(str(i)) - str(i).index("18") - 2
		i += 10 ** length
		continue 
	count += 1
	i += 1

print(count)