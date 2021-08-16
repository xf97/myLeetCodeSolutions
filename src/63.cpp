class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //干翻阿里巴巴！
        //这一题有障碍物
        //同样的动态规划，用障碍物的地方置0
        //m, n >= 1
        //很棒，第一次自己做出来这么低通过率的题
        //考虑很周全，一次提交，二十分钟，时间击败-73.96%，空间击败-5.52%
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        bool flag = false;  //障碍物标志
        vector<vector<int>> dp(m, vector<int>(n, 0));   //动态规划数组
        //初始化第一行
        for(int i = 0; i < n; ++ i){
            if(flag){
                dp[0][i] = 0;
            }
            else if(flag == false && obstacleGrid[0][i] == 0){
                dp[0][i] = 1;
            }
            else{
                dp[0][i] = 0;
                flag = true;
            }
        }
        flag = false;
        //初始化第一列
        for(int i = 0; i < m; ++ i){
            if(flag){
                dp[i][0] = 0;
            }
            else if(flag == false && obstacleGrid[i][0] == 0){
                //cout<<i<<" "<<0<<" "<<1<<endl;
                dp[i][0] = 1;
            }
            else{
                dp[i][0] = 0;
                flag = true;
            }
        }
        //向内推导
        for(int i = 1; i < m; ++ i){
            for(int j = 1; j < n; ++ j){
                //障碍物
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
