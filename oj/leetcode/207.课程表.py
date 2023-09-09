#
# @lc app=leetcode.cn id=207 lang=python3
#
# [207] 课程表
#
# https://leetcode.cn/problems/course-schedule/description/
#
# algorithms
# Medium (53.67%)
# Likes:    1705
# Dislikes: 0
# Total Accepted:    323.7K
# Total Submissions: 603.1K
# Testcase Example:  '2\n[[1,0]]'
#
# 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
# 
# 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi]
# ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
# 
# 
# 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
# 
# 
# 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：numCourses = 2, prerequisites = [[1,0]]
# 输出：true
# 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
# 
# 示例 2：
# 
# 
# 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
# 输出：false
# 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
# 
# 
# 
# 提示：
# 
# 
# 1 <= numCourses <= 2000
# 0 <= prerequisites.length <= 5000
# prerequisites[i].length == 2
# 0 <= ai, bi < numCourses
# prerequisites[i] 中的所有课程对 互不相同
# 
# 
#

# @lc code=start
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        pcnt = [0 for _ in range(numCourses)]
        pn = defaultdict(list)
        for vec in prerequisites:
            pcnt[vec[1]] += 1
            pn[vec[0]].append(vec[1])
        for i in range(numCourses):
            k = -1
            for j in range(numCourses):
                if pcnt[j] == 0:
                    k = j
                    break
            if k == -1:
                return False
            pcnt[j] -= 1
            for l in pn[j]:
                pcnt[l] -= 1
        return True



"""
官方题解，结合了遍历，这里看不超时，直接暴力了
"""

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        edges = collections.defaultdict(list)
        visited = [0] * numCourses
        result = list()
        valid = True

        for info in prerequisites:
            edges[info[1]].append(info[0])
        
        def dfs(u: int):
            nonlocal valid
            visited[u] = 1
            for v in edges[u]:
                if visited[v] == 0:
                    dfs(v)
                    if not valid:
                        return
                elif visited[v] == 1:
                    valid = False
                    return
            visited[u] = 2
            result.append(u)
        
        for i in range(numCourses):
            if valid and not visited[i]:
                dfs(i)
        
        return valid
# @lc code=end

