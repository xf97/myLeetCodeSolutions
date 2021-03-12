class Solution {
public:
    int hammingWeight(uint32_t n) {
        //今日收尾算法题目，时间只有二十多分钟了，做个简单题
        //用位运算
        //题目给定无符号整数，必定不为负数，所以
        //向右移位补0，不干扰运算
        /*
        10分钟搞定
        时间击败：39.6%
        空间击败：46.4%
        */
        int result = 0;
        while(n){
            //cout<<n<<endl;
            if(n & 1){
                //只保留最后1位
                result++;
            }
            n >>= 1;
        }
        return result;
    }
};
