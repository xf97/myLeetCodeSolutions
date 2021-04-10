class Solution {
public:
    bool isUgly(int n) {
        //有点简单，向下除
        //题目只是说整数，没有保证输入是正整数
        //边界情况
        //十分钟，一次提交，时间击败：100%，空间击败：31.79%
        if(n <= 0){
            return false;
        }
        while((n & 1) == 0){
            //能整除2，用位运算加快速度
            //用位运算加快速度
            n >>= 1;
        }
        while(n % 3 == 0){
            n /= 3;
        }
        while(n % 5 == 0){
            n /= 5;
        }
        return n == 1;
    }
};
