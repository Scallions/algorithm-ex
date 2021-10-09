import sys

# A => 12 34
# B => AB CD

fin = open("data/honor1.in", "r")

sys.stdin = fin
inps = sys.stdin.readline()
datas = inps.split(" ")
# n = datas[0]
datas = datas[1:]
res = []
for data in datas:
    if data == "A":
        res.extend(["12" , "34"])
    elif data == "B":
        res.extend(["AB", "CD"])
    else:
        res.append(data)

n = str(hex(len(res)+1)).upper()[2:]

print(" ".join([n] + res))
