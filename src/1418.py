class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        #每日中等题，现在每天还得做一些牛客上的题
        #这个中等题看着比较简单，只是代码麻烦一些
        #先遍历一次，把菜品名，以及桌号和菜品的对应关系收集了
        #时间复杂度-On，空间复杂度-On
        #三十分钟，一次提交，时间击败-17.86%，空间击败-33.93%
        _1stRow = set()
        tableAndFoodDict = dict()   #后期可以对桌号进行升序遍历
        for item  in orders:
            _1stRow.add(item[2]) #记录菜品
            #记录桌号和菜品
            if item[1] not in tableAndFoodDict:
                tableAndFoodDict[item[1]] = list()
                tableAndFoodDict[item[1]].append(item[2])
            else:
                tableAndFoodDict[item[1]].append(item[2])
        #生成第一行
        result =  list()
        _1stRow = list(_1stRow)
        _1stRow.sort()
        _1stRow.insert(0, "Table")
        result.append(_1stRow)
        #按升序遍历桌号
        #print(tableAndFoodDict.keys())
        tableNumList = sorted(int(i) for i in tableAndFoodDict.keys())
        #print(tableNumList)
        for tableNum in tableNumList:
            #新建每一行
            aRow =len(_1stRow) * [0]
            aRow[0] = tableNum
            for food in tableAndFoodDict[str(tableNum)]:
                aRow[_1stRow.index(food)] += 1
            aRow =  [str(i) for i in aRow]
            result.append(aRow)
        return result 
