class Solution:
    def isNumber(self, s: str) -> bool:
        #开头和结尾可能包含空格
        #粗暴解法
        try:
            num = float(s)
        except:
            return False
        return True
        #尝试一下精细解法，能否用正则表达式？不知道为什么re总是报错
        '''
        pattern = "(\s)*((+)|(-))?(\d)"
        result = re.match(pattern, s)
        if result:
            return True
        else:
            return False
        '''
         
