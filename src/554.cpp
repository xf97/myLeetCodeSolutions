class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        //看了题解，我懂了
        //现在自己实现
        //统计间隙的数量 
        //十分钟，一次提交，时间击败-55.72%，空间击败-88.02%
        int height = wall.size();   //墙高度
        unordered_map<int, int> gaps;  //间隙-数量
        for(int i = 0; i < height; ++ i){
            int size = wall[i].size();
            int gap = 0;
            for(int j =  0; j < size - 1; ++ j){
                gap += wall[i][j];
                gaps[gap] ++;   //间隙数量加1
            }
        }
        /*
        for(auto & [g, c] : gaps){
            cout<<g<<" "<<c<<endl;
        }
        */
        //找到间隙最大的那一列
        int maxGap = 0;
        for(auto & [_, count] : gaps){
            maxGap = max(maxGap, count);
        }
        return height - maxGap; //返回高度减间隙
    }
};
