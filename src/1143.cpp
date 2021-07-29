class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //干翻蚂蚁
        //终于来个有难度的题了
        //整死他，感觉要用哈希表
        //不对，要用动态规划
        //十五分钟，两次提交，时间击败-77.42%，空间击败-27.68%
        int m = text1.size();   //需要一个辅助的动态规划矩阵
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));  //m+1行n+1列
        //初始化
        for(int i = 1; i < m + 1; ++ i){
            for(int j = 1; j < n + 1; ++ j){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
