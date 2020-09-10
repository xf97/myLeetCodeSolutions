class Solution:
    '''
    时间巨长：击败5.01%
    内存还好: 击败78.31% 
    '''
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = list(list())
        temp = list()
        #递归求解
        self.dfs(candidates, target, temp, result)
        return result
    
    def dfs(self, _candidates, _nowTarget, _nowSolu, _soluList):
        tempCan = _candidates[:]
        tempSolu = _nowSolu[:]
        if _nowTarget < 0:
            return
        if _nowTarget == 0:
            sortSolu = sorted(tempSolu)
            if sortSolu not in _soluList:
                _soluList.append(sortSolu)
            return
        else:
            for i in range(len(_candidates)):
                tempSolu.append(_candidates[i])
                tempCan.remove(_candidates[i])
                self.dfs(tempCan, _nowTarget - _candidates[i], tempSolu, _soluList)
                tempSolu.pop()
                tempCan.append(_candidates[i])
