class Solution:
    def trap(self, height: List[int]) -> int:
        #干翻字节！
        #基本上看懂了，单调栈
        #用要入栈的元素，栈顶元素和下一个栈顶元素来一层一层的求值
        #不看题解做不出来，看了才懂这个思想
        #二十分钟，一次提交，时间击败-45.36%，空间击败-8.87%
        #看了官方题解，动态规划的思想也是绝了，双指针也是妙了妙了
        heightStack  = list()   #后端进，后端出
        #结果
        result = 0
        #边界情况
        length = len(height)
        if length <  3:
            return result
        #开始入栈，有0也不怕
        for i in range(length):
            #单调出栈
            #栈中存储的是索引，方便计算长
            while len(heightStack) >  0 and height[i] > height[heightStack[-1]]:
                #大于，出栈
                tempHeight  = height[heightStack[-1]]
                heightStack.pop()
                #看看有没有大平层情况的出现
                while len(heightStack) > 0 and tempHeight == height[heightStack[-1]]:
                    heightStack.pop()
                #计算每一层能容纳的水
                if len(heightStack) > 0:
                    #长
                    #后减前
                    #索引是顺序入栈的
                    chang = i - heightStack[-1] -1
                    #宽
                    kuan = min(height[heightStack[-1]] - tempHeight, height[i] - tempHeight)
                    #print(chang, kuan)
                    result += (chang *  kuan)
            heightStack.append(i)
        return result


