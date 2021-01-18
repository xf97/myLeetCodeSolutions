class Solution:
    '''
    time defeat: 88%
    space defeat: 8%
    '''
    def reverseWords(self, s: str) -> str:
        #split解决？
        wordList = s.split(" ")
        resultList = list()
        for word in wordList:
            resultList.append(word[::-1])
        return " ".join(resultList)
        
