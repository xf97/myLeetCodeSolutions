class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        #输入是由大写和小写字母组成的非空单词
        #边界处理
        #五分钟，一次提交，时间击败-64.44%，空间击败-59.62%
        if len(word) <= 1:
            return True
        else:
            #分类讨论
            if word[0].isupper():
                #首字母是大写吗
                #是大写，要么只能首字符是大写，要么全员大写
                if word[1].isupper():
                    #此时只能全员大写
                    result = True
                    for i in word[2:]:
                        if i.islower():
                            result = False
                            break
                        else:
                            continue
                    return result
                else:
                    #此时后面只能全员小写
                    result = True
                    for i in word[2:]:
                        if i.isupper():
                            result = False
                            break
                        else:
                            continue
                    return result
            else:
                #不是的话，后面所有字母都不能是大写
                result = True
                for i in word[1:]:
                    if i.isupper():
                        result = False
                        break
                    else:
                        continue
                return result
