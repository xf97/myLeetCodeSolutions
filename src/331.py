class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        #看了题解，现在根据自己的思路复现
        '''
        看了题解才明白这题是什么意思，要去验证这个前序序列能够构成一棵树
        time defeat: 18.13%
        space defeat: 14.28%
        '''
        #边界条件
        if len(preorder) == 0:
            return False
        elif preorder[0] == '#' and len(preorder) == 1:
            return True
        elif len(preorder) < 3:
            return False
        #普适条件
        else:
            #去掉无关字母
            nodeList = preorder.split(',')
            spots = 1    #需要填值的槽位，每个槽位都必须被填入值
            for ch in nodeList:
                if spots == 0:
                    #还没遍历完就没槽位了
                    return False
                elif ch == '#':
                    spots -= 1
                else:
                    spots += 1
            return spots == 0
