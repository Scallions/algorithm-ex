import sys


inp = sys.stdin.readline()


cnt = 0
for c in inp:
    if c != ' ' and c != '\n':
        cnt += 1

print(cnt)