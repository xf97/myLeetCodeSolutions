class Solution:
    '''
    time defeat: 30.20%
    space defeat: 62.92%
    '''
    def findComplement(self, num: int) -> int:
        #用python简单一些
        #首先获取二进制
        bNum = bin(num)[2:] #不要开头的0b
        bResult = str() #存储返回结果的二进制字符串
        #然后按位取反
        for i in bNum:
            if i == "1":
                bResult += "0"
            else:
                bResult += "1"
        #最后转成10进制输回去
        return int(bResult, 2)
