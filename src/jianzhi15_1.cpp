class Solution {
public:
    int hammingWeight(uint32_t n) {
        //这题我也做过，现在再做想用最快的方法来完成
        //时间复杂度，o(32)->o(1)，空间复杂度-o(1)
        //两分钟，一次提交，时间击败-39.40%, 空间击败-14.91%
        //位运算
        int result = 0;
        while(n > 0){
            if(n &  0x1){
                result ++;
            }
            //cout<<(n &  0x1)<<endl;
            n >>= 1;
        }
        return  result;
    }
};
