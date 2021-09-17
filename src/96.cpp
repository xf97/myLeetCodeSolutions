class Solution {
public:
    int numTrees(int n) {
        //一种想法是生成所有的排列，然后验证某种排列下符不符合排序
        //时间复杂度O2^n
        //能不能用数学？好像可以动态规划
        //思路完全正确，我好强，只是*弄成+
        //七分钟，一次通过，时间击败-100%，空间击败-63.07%
        //边界处理
        if(n <= 2){
            return n;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;  //只有一个节点时
        dp[2] = 2;  //有两个节点时 
        for(int i = 3; i <= n; ++ i){
            //拆分为左右子树
            //选定根
            for(int j = 1; j <= i; ++ j){
                //j是根
                int left = j - 1;   //左子树的节点数量
                int right = i - j;  //右子树的节点数量
                //是组合数量，所以相乘
                dp[i] += dp[left] * dp[right];
            }
        }
        return dp[n];
    }
};
