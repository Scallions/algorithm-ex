import sys



if __name__ == '__main__':
    n, m = [int(inp) for inp in sys.stdin.readline().split(" ")]
    faces = []
    jobs = []
    for i in range(n):
        face, job = sys.stdin.readline().split(" ")
        faces.append(int(face))
        jobs.append(job)

    cur = 0
    for i in range(m):
        f, l = [int(inp) for inp in sys.stdin.readline().split(" ")]
        if f == 0:
            # left
            if faces[cur] == 0:
                # 内
                cur -= l
            else:
                # 外
                cur += l
        else:
            # right
            if faces[cur] == 0:
                # 内
                cur += l
            else:
                # 外
                cur -= l
        cur %= n

    print(jobs[cur])