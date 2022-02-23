import sys

word = sys.stdin.readline().strip()

sentence = sys.stdin.readline()

cnt = 0
idx = -1

l = len(sentence)
lw = len(word)
i = 0
while i < l:

    # 匹配一个单词初始位置
    while i < l and sentence[i] == ' ':
        i += 1
    if i >= l:
        break

    iw = 0
    while iw<lw and i < l and sentence[i].lower() == word[iw].lower():
        iw += 1
        i += 1

    # print(i, iw, lw, sentence[i])
    if iw == lw and sentence[i] == ' ':
        # print('tt')
        if cnt == 0:
            idx = i - lw
            cnt = 1
        else:
            cnt += 1

    while i < l and sentence[i] != ' ':
        i += 1


if cnt == 0:
    print(-1)
else:
    print(f"{cnt} {idx}")