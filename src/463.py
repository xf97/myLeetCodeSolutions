class Solution:
    '''
    基本思想：边遍历边探查每个格子周围的陆地情况
    time defeat: 89%
    space defeat: 25%
    time consuming: 20 mins
    '''
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        perimeter = 0   #周长
        for exIndex, array in enumerate(grid):
            #再进入内部数组
            for inIndex, item in enumerate(grid[exIndex]):
                if item == 1:
                    #陆地，探查周围四个格子
                    nowPer = 0  #这个格子的周长
                    #上
                    if exIndex == 0 or grid[exIndex - 1][inIndex] == 0:
                        #是边界或者是海的情况，周长加1
                        nowPer += 1
                    #左
                    if inIndex == 0 or grid[exIndex][inIndex - 1] == 0:
                        nowPer += 1
                    #下
                    if exIndex == len(grid) - 1 or grid[exIndex + 1][inIndex] == 0:
                        nowPer += 1
                    #右
                    if inIndex == len(grid[exIndex]) - 1 or grid[exIndex][inIndex + 1] == 0:
                        nowPer += 1
                    #加入总周长
                    perimeter += nowPer
        return perimeter