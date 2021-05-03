class Solution {
public:
    int reverse(int x) {
        //用标准方法做吧
        //翻转倒不难
        //脑子有点乱，两次提交
        //时间击败-49.04%，空间击败-14.76%
        long long tempResult = x;
        bool negativeFlag = false;   //负数标志
        if(tempResult < 0){
            negativeFlag = true;
             tempResult *= (-1);
        }
        //翻转
        string tempStr = to_string(tempResult);
        std::reverse(tempStr.begin(), tempStr.end());
        tempResult = stoll(tempStr);
        if(tempResult > (pow(2, 31) -1)){
            return 0;
        }
        if(negativeFlag){
            tempResult *= (-1);
        }
        if(tempResult < ((-1) * pow(2, 31))){
            return 0;
        }
        return static_cast<int>(tempResult);
    }
};
