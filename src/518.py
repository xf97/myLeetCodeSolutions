class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        #干翻腾讯CSIG！
        #探索加回溯，amount是目标值，coins是可选部分
        #超时，服了，不行呀兄弟
        #服了，原来要兄弟动态规划
        #三十分钟，两次提交，时间击败-99.46%，空间击败-38.67%
        dp = [0] * (amount + 1)
        #初始化
        dp[0] = 1   #要总金额等于0只有一种做法
        #开始递推
        for coin in coins:
            #如果我选了硬币coin
            for i in range(coin, amount + 1):
                #那么康康有没有人是i-coin
                dp[i] += dp[i - coin]
        return dp[amount]
        '''
        result = set()    #结果路径数量
        aPath = list()  #单次路径
        def exploreRecall(target, curPath, result):
            #print(target, curPath)
            if target == 0:
                #找到路径
                #tempPath = sorted(curPath)
                result.add(tuple(curPath)) #不用担心重复
            elif target < 0:
                #死路一条
                return
            else:
                for i in coins:
                    target -= i
                    curPath.append(i)
                    exploreRecall(target, curPath, result)
                    #回溯
                    target += i
                    curPath.pop(-1)
                return

        #开始探索加回溯
        exploreRecall(amount, aPath, result)
        return len(result)
        '''
