#!/usr/bin/python
#用个递归吧

#89%, 82%
def getPrime(_num):
    #用于应对本身就是质数的情况
    selfPrime = 1
    for factor in range(2, int(_num ** 0.5 + 1)):
        #一个数的质因数最大就是他的开根
        if _num % factor == 0:
            #这个数不是质数并且找到了一个质因数
            print(factor, end = " ")
            selfPrime = 0
            #递归向下
            getPrime(_num // factor)
            break
    if selfPrime:
        print(_num, end = " ")
        
if __name__ == "__main__":
    getPrime(int(input()))
    
        
