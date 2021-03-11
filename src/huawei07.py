#采用加0.5的方式
#题目规定正整数

#74%, 78%
def getSimilar(_num):
    if _num + 0.5 >= int(_num) + 1:
        return int(_num) + 1
    else:
        return int(_num)
    
    
if __name__ == "__main__":
    #python3中没有double类型
    print(getSimilar(float(input())))
