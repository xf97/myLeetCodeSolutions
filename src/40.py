class Solution:
    '''
    时间巨长：击败5.01%
    内存还好: 击败80.94% 
    '''
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = list(list())
        temp = list()
        #递归求解
        self.dfs(candidates, target, temp, result)
        return result
    
    def dfs(self, _candidates, _nowTarget, _nowSolu, _soluList):
        tempCan = _candidates[:]  #复制，保留本层递归的解集
        tempSolu = _nowSolu[:]  #同理
        if _nowTarget < 0:  #小于0，已不能找到合适的解集，返回
            return
        if _nowTarget == 0: #等于0，已经找到解集，若其与已有解集不重复，则加入结果
            sortSolu = sorted(tempSolu)
            if sortSolu not in _soluList:
                _soluList.append(sortSolu)
            return
        else:
            for i in range(len(_candidates)):
                tempSolu.append(_candidates[i])
                tempCan.remove(_candidates[i]) #若使用某元素，则将其从待选集中移除
                self.dfs(tempCan, _nowTarget - _candidates[i], tempSolu, _soluList)
                tempSolu.pop() #若不使用某元素，则将其加入到待选集中
                tempCan.append(_candidates[i])
