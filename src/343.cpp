class Solution {
public:
    int integerBreak(int n) {
        //cout<<n<<endl;
        //用数学的思路
        //想到一半发现自己的数学还是太拉
        //果然去看了题解，发现是动态规划
        //4是边界
        /*
        if(n <= 4){
            return n;
        }
        else{
            if(n & 0x1){
                //奇数
                return integerBreak(n / 2) * integerBreak(n / 2 + 1);
            }
            else{
                //偶数
                return integerBreak(n / 2) * integerBreak(n / 2);
            }
        }
        */
        //开始规划起来吧弟弟
        //看了题解后自己写的
        //五分钟，时间击败-100%，空间击败-43.92%
        vector<int> dp(n + 1);  //0要包含上
        for(int i = 2; i <= n; ++ i){
            int curMax = 0;
            for(int j = 1; j < i; ++ j){
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp.back();
    }
};
