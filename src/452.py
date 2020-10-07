class Solution:
    '''
    题目的意思就是，给定几个区间
    如果两两区间有相交部分（就是我的终点大于它的起点）
    就射爆它
    time defeat: 99.78%
    space defeat: 99.59%
    time consuming: 1 hour
    '''
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if len(points) == 0 or len(points) == 1:
            return len(points)
        #排序
        points.sort(key = lambda x : x[1] ) #按结束坐标排序
        num = 1 #箭的数量
        firstEnd = points[0][1] #首个终止坐标
        for start, end in points:
            if start > firstEnd:    #跟我不重合，加一支箭
                num += 1
                firstEnd = end
            elif end <= firstEnd:   #否则，扩展这个气球的范围
                end = firstEnd
        return num
