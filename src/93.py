class Solution:
    def reFind(self, _result, _nowStr, _remainNum, _str):
        #终止条件
        '''
        elif _str[0] > "2":
            return 
        '''
        #print(_remainNum, _str)
        if _str == "" and _remainNum  == 0:
            _result.add(_nowStr[1:])
        elif len(_str) > 3 * _remainNum:
            return
        else:
            #只要不到255，就拼接，注意.
            tempStr = ""
            index = 0
            while index < 3 and index < len(_str):
                tempStr += _str[index]
                if int(tempStr) > 255:
                    break
                index += 1
                #print(tempStr)
                #向下
                if tempStr == "0":
                    self.reFind(_result, _nowStr + "." + tempStr, _remainNum - 1, _str[index:])
                    break
                else:
                    self.reFind(_result, _nowStr + "." + tempStr, _remainNum - 1, _str[index:])
            return

    def restoreIpAddresses(self, s: str) -> List[str]:
        #干翻蚂蚁金服
        #可以逐步缩小问题
        #直接回溯，了解，会了
        #自己做出来的！麻烦的很，一次提交
        #五十分钟，时间击败-92.79%，空间击败-48.84%
        result = set()
        _1Result = str()
        index = 4
        self.reFind(result, _1Result, index, s)
        return list(result)
