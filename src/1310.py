class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        #arr中每个元素都是正整数
        #乍一看，怎么感觉并不难呀，感觉配不上中等题
        #原来是会超时，40/42
        #看了题解，果然又是到数学题
        '''
        result = list() #结果数组
        #根据传入的参数，计算异或值
        #题目保证_sIndex<=_eIndex
        def getXorValue(_arr, _sIndex, _eIndex):
            #边界处理
            if _sIndex == _eIndex:
                return _arr[_sIndex]
            #print(_sIndex, _eIndex)
            value = _arr[_sIndex]
            for i in range(_sIndex + 1, _eIndex + 1):
                value ^= _arr[i]
            return value

        #print(3 ^ 4)
        for item in queries:
            value = getXorValue(arr, item[0], item[1])
            result.append(value)
        return result
        '''
        #为防止超时，先行计算一次前缀异或结果
        #两次提交，十分钟，时间击败-87.18%，空间击败-91.67%
        xorValueList = list()
        xorValueList.append(0)
        for i in arr:
            xorValueList.append(xorValueList[-1] ^ i)   #用之前的前缀来计算新的值
        #现在可以计算结果了
        result = list()
        for sIndex, eIndex in queries:
            result.append(xorValueList[sIndex] ^ xorValueList[eIndex + 1])
        return result

