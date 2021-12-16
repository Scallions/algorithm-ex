/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 *
 * https://leetcode-cn.com/problems/k-th-smallest-prime-fraction/description/
 *
 * algorithms
 * Hard (47.81%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    7.3K
 * Total Submissions: 13K
 * Testcase Example:  '[1,2,3,5]\n3'
 *
 * 给你一个按递增顺序排序的数组 arr 和一个整数 k 。数组 arr 由 1 和若干 素数
 * 组成，且其中所有整数互不相同。
 *
 * 对于每对满足 0 < i < j < arr.length 的 i 和 j ，可以得到分数 arr[i] / arr[j]
 * 。
 *
 * 那么第 k 个最小的分数是多少呢?  以长度为 2 的整数数组返回你的答案,
 * 这里 answer[0] == arr[i] 且 answer[1] == arr[j] 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [1,2,3,5], k = 3
 * 输出：[2,5]
 * 解释：已构造好的分数,排序后如下所示:
 * 1/5, 1/3, 2/5, 1/2, 3/5, 2/3
 * 很明显第三个最小的分数是 2/5
 *
 *
 * 示例 2：
 *
 *
 * 输入：arr = [1,7], k = 1
 * 输出：[1,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2
 * 1
 * arr[0] == 1
 * arr[i] 是一个 素数 ，i > 0
 * arr 中的所有数字 互不相同 ，且按 严格递增 排序
 * 1
 *
 *
 */
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> c(n - 1, 0);
    auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y) {
      return x.first * y.second > x.second * y.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    unordered_map<int, int> mp;
    for (int i = 1; i < n; ++i) {
      mp[arr[i]] = i - 1;
      pq.push(make_pair(arr[0], arr[i]));
    }
    int count = 1;
    while (count < k) {
      auto t = pq.top();
      pq.pop();
      ++c[mp[t.second]];
      if (c[mp[t.second]] <= mp[t.second]) {
        pq.push(make_pair(arr[c[mp[t.second]]], t.second));
      }
      ++count;
    }
    return {pq.top().first, pq.top().second};
  }
};
// @lc code=end

// 官方优先队列
class Solution1 {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    int n = arr.size();
    auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y) {
      return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
        cmp);
    for (int j = 1; j < n; ++j) {
      q.emplace(0, j);
    }
    for (int _ = 1; _ < k; ++_) {
      auto [i, j] = q.top();
      q.pop();
      if (i + 1 < j) {
        q.emplace(i + 1, j);
      }
    }
    return {arr[q.top().first], arr[q.top().second]};
  }
};

// 官方二分
class Solution2 {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    int n = arr.size();
    double left = 0.0, right = 1.0;
    while (true) {
      double mid = (left + right) / 2;
      int i = -1, count = 0;
      // 记录最大的分数
      int x = 0, y = 1;

      for (int j = 1; j < n; ++j) {
        while ((double)arr[i + 1] / arr[j] < mid) {
          ++i;
          if (arr[i] * y > arr[j] * x) {
            x = arr[i];
            y = arr[j];
          }
        }
        count += i + 1;
      }

      if (count == k) {
        return {x, y};
      }
      if (count < k) {
        left = mid;
      } else {
        right = mid;
      }
    }
  }
};
