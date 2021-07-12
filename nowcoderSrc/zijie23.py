#入门题目我无敌重拳出击
if __name__ == "__main__":
    #所有数据都花得少于1024元但是大于0元
    #先计算要找零的数量
    cost = int(input())
    num = 1024 - cost
    #然后一直减等于就好了
    #2的倍数，一定能减到0的
    result = 0    #硬币数量
    while num:
        #最少多少枚，往大了找零
        if num >= 64:
            num -= 64
            result += 1
        elif num >= 16:
            num -= 16
            result += 1
        elif  num >= 4:
            num -= 4
            result += 1
        else:
            num -= 1
            result += 1
    print(result)
