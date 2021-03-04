class Solution:
    '''
    time defeat: 30.34%
    space defeat: 28.37%
    '''
    def hammingDistance(self, x: int, y: int) -> int:
        #这个用python倒是很好做，直接转然后遍历就可以了
        bX = bin(x)[2:]
        bY = bin(y)[2:]
        #然后补全对齐
        #先保证bX永远是短的那个
        if len(bX) > len(bY):
            bX, bY = bY, bX
        while len(bX) < len(bY):
            bX = "0" + bX
        #然后按位比对
        result = 0
        for (i, j) in zip(bX, bY):
            if i != j:
                result += 1
            else:
                continue
        return result
