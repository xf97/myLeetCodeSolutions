class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #用的简单方法，时间复杂度On2
        #超时，111/114
        #看了题解，太强了太强了
        #时间击败-30.82%, 空间击败-61.45%
        mp = collections.defaultdict(list)  #创建列表字典
        #用排序后的字符串当键
        for str in strs:
            key  = "".join(sorted(str))
            mp[key].append(str)

        return list(mp.values())
        '''
        if  len(strs) <= 1:
            return  [strs]
        else:
            result = list() #结果 
            #递归遍历
            self.forAllStrs(strs, result)
            return result

    def forAllStrs(self, _strLists, _result):
        if len(_strLists) == 0:
            return
        else:
            tempResult  = list()
            tempResult.append(_strLists[0])
            for word in _strLists[1:]:
                if  self.isAnagrams(tempResult[0], word):
                    tempResult.append(word)
                else:
                    continue
            #移除这一轮的字母异位词
            _result.append(tempResult)
            for word in tempResult:
                _strLists.remove(word)
            self.forAllStrs(_strLists, _result)
    
    def isAnagrams(self, _word1, _word2):
        if len(_word1) != len(_word2):
            return False
        else:
            #str是不可变类型
            alpha1 = list(_word1)
            alpha2 =list(_word2)
            for a1 in alpha1:
                if a1 not in alpha2:
                    return False
                else:
                    alpha2.remove(a1)
            return len(alpha2) == 0
            '''
