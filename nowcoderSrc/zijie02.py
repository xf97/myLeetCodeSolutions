#兄弟们，字节跳动，奥利给，许愿下周三过
#淦
#不会，淦
#看了题解，滑动窗口
#最长子串就要想到滑动窗口
#看了下题解，自己实现
#吃一堑长一智

if __name__ == "__main__":
    length, count = ([int(i)  for i in input().split(" ")])
    string = input()
    result = -1
    lPoint, rPoint  = 0, 0    #左右指针
    aNum, bNum = 0, 0
    while rPoint < length:
        if string[rPoint] == "a":
            aNum += 1
        else:
            bNum += 1
        #贪心，能多吃就多吃
        if aNum <= count  or bNum <= count:
            #现在还能cover，不用担心，往前走
            rPoint += 1
        else:
            #覆盖不了了，先记录结果，然后开始收缩
            result = max(result, rPoint - lPoint)
            if string[lPoint] == "a":
                lPoint += 1
                aNum -= 1
            else:
                lPoint += 1
                bNum -= 1
            rPoint += 1    #又可以向右了
        #最后，更新结果
    result = max(result, rPoint - lPoint)
    print(result)
