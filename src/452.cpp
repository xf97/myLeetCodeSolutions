
class Solution {
    /*
   用cpp再做一遍
    */
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //极端情况
        if(points.size() <= 1){
            return  points.size();
        }
        //排序
        sort(points.begin(), points.end(), cmp);
        //初始化
        int num = 1;
        int firstEnd = points[0][1];
        for(auto i : points){
            if(i[0] > firstEnd){
                num ++;
                firstEnd = i[1];
            }
            else if(i[1] <= firstEnd){
                i[1] = firstEnd;
            }
        }
        return num;
    }
    
    //排序选择函数，使用静态函数
    static bool cmp(vector<int> _vec1, vector<int> _vec2) {
        return _vec1[1] < _vec2[1];  //按终点升序排序
    }
};
