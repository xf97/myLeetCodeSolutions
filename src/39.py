class Solution:
    '''
    自己做出来的，高兴！
    '''
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.temp = list()
        self.result = list(list())
        self.dfs(candidates, target, self.temp, self.result)
        return self.result
        
    def dfs(self, _candi, _nowTarget, _nowSolu, _soluList):
        #print(_nowTarget)
        temp = _nowSolu[:]
        if _nowTarget < 0:
            #print("lululu")
            return
        if _nowTarget == 0:
            #print("hahahahaha")
            temp = sorted(temp)
            if temp not in _soluList:
                _soluList.append(temp)
            #_nowSolu.clear()
        else:
            #print("xixixi")
            for i in _candi:
                #print(i)
                temp.append(i)
                self.dfs(_candi, _nowTarget - i, temp, _soluList)
                temp.pop() #探索完一个元素，将其从待解集中释放

        
