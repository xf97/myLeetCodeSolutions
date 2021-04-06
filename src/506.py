class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        #先用调库的方法
        #排序，哈希表记录位置，然后返回结果
        #N是一个正整数，并且每个运动员的分数都不相同
        #不存在边界情况
        #一次提交成功，十五分钟，时间击败：19.51%，空间击败：36.77%
        def getRanking(_num):
            if _num == 1:
                return "Gold Medal"
            elif _num == 2:
                return "Silver Medal"
            elif _num == 3:
                return "Bronze Medal"
            else:
                return str(_num)

        sortedScore = sorted(score, reverse = True)
        scoreAndRank = dict()
        #遍历
        for index, value in enumerate(sortedScore):
            scoreAndRank[value] = (index + 1)
        #print(scoreAndRank)
        #产生结果数组
        result = [""] * len(score)
        for key, value in scoreAndRank.items():
            index = score.index(key)
            #print(key, value, index)
            result[index] = getRanking(value)
        #print(result)
        return result
