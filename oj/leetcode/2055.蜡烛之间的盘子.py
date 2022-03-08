class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        ls = len(s)
        left = [-1] * ls
        right = [-1] * ls
        psum = [0] * (ls+1)
        for i,c in enumerate(s):
            if c == '|':
                psum[i+1] = psum[i] + 1
                left[i] = i
            else:
                if i != 0:
                    left[i] = left[i-1]
                psum[i+1] = psum[i]

        for i in range(ls-1,-1,-1):
            if s[i] == '|':
                right[i] = i
            else:
                if i!= ls-1:
                    right[i] = right[i+1]

        res = []
        for querie in queries:
            s, e = querie
            if right[s] == -1 or left[e] == -1 or abs(psum[e+1]-psum[s]) < 2:
                res.append(0)
                continue
            l = (e-s+1) - (right[s]-s) - (e-left[e]) - (psum[e+1] - psum[s])
            res.append(l)

        return res
