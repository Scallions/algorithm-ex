import sys

raws = []

while (inp:=sys.stdin.readline().strip()) != "EOF":
    raws.append(inp)


inps = []
while (inp:=sys.stdin.readline().strip()) != "EOF":
    inps.append(inp)

t = int(sys.stdin.readline().strip())


cnt = 0
i = 0
while i < len(raws) and i < len(inps):
    raw = raws[i]
    inp = inps[i]
    i += 1
    rs = []
    for c in raw:
        if c == '<':
            if len(rs) != 0:
                rs.pop()
        else:
            rs.append(c)
    ips = []
    for c in inp:
        if c == '<':
            if len(ips) != 0:
                ips.pop()
        else:
            ips.append(c)
    ii = 0
    ir = 0
    li = len(ips)
    lr = len(rs)
    while ii < li and ir < lr:
        if ips[ii] == rs[ir]:
            cnt += 1
        ii += 1
        ir += 1

cnt  = 60 * cnt
i = cnt // t
r = cnt % t
if r/t > 0.5:
    print(i+1)
else:
    print(i)