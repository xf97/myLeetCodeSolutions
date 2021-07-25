class Solution {
public:
    int climbStairs(int n) {
        //干翻字节，老斐波那契了
        //老动态规划了，f(n)=f(n-1)+f(n-2)
        //做完这题回去吃饭了，然后准备干翻拼多多
        //三分钟，一次提交，时间击败-100%，空间击败-5.73%
        //题目保证n是一个正整数
        //边界情况
        if(n == 1){
            return 1;
        }
        else if(n == 2){
            return 2;
        }
        else{
            //一维动态规划，需要辅助数组
            //时间复杂度On，空间复杂度On
            vector<int> result(n);
            result[0] = 1;
            result[1] = 2;
            for(int i = 2; i < n; ++ i){
                result[i] = result[i - 1] + result[i - 2];
            }
            return result[n - 1];
        }
    }
};
