#
# @lc app=leetcode.cn id=2241 lang=python3
#
# [2241] 设计一个 ATM 机器
#

# @lc code=start
class ATM:

    def __init__(self):
        self.money_vaules_list = [20, 50, 100, 200, 500]
        self.money_cnt = {
            20: 0,
            50: 0,
            100: 0,
            200: 0,
            500: 0
        }
        

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(len(banknotesCount)):
            self.money_cnt[self.money_vaules_list[i]] += banknotesCount[i]
        

    def withdraw(self, amount: int) -> List[int]:
        res = [0] * len(self.money_vaules_list)
        for i in range(len(self.money_vaules_list) - 1, -1, -1):
            res[i] = min(self.money_cnt[self.money_vaules_list[i]], amount // self.money_vaules_list[i])
            amount -= res[i] * self.money_vaules_list[i]
            if amount == 0:
                break
        if amount == 0:
            for i in range(len(self.money_vaules_list)):
                self.money_cnt[self.money_vaules_list[i]] -= res[i]
            return res
        else:
            return [-1]

        


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)
# @lc code=end

