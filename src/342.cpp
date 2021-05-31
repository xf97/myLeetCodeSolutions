class Solution {
public:
    bool isPowerOfFour(int n) {
        //先来暴力法
        //给定的是整数
        //两分钟，一次提交，没想到时间效率这么高
        //时间击败-100%，空间击败-5.08%
        if(n < 1){
            return false;
        }
        int p = 0;  //指数
        while(pow(4, p) < n){
            p ++;
        }
        return n == pow(4, p);
    }
};
