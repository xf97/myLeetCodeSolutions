class Solution {
public:
    int uniquePaths(int m, int n) {
        //干翻蚂蚁金服
        //动态规划，我又来了！
        //递推公式，dp(i, j) = dp(i-1, j) + dp(i, j-1)
        //二维跳台阶
        //得初始化第一行和第一列
        //十分钟，两次提交，时间击败-100%，空间击败-5.62%
        vector<vector<int>> dp(m, vector<int>(n));  //m行n列
        //从0-0到(m-1)-(n-1)
        //初始化第一行
        for(int i = 0; i < n; ++ i){
            dp[0][i] = 1;   //第一行只有一种路径可以到达
        }
        //初始化第一列
        for(int j = 0; j < m; ++ j){
            dp[j][0] = 1;
        }
        //开始递推
        for(int i = 1; i < m; ++ i){
            for(int j = 1; j < n; ++ j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n- 1];
    }
};
