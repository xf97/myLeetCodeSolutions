class Solution {
public:
    int maximumSwap(int num) {
        //从前向后，如果后面的大于前面的，保存交换后的结果
        //时间复杂度On2
        //舒服，十五分钟，一次提交，40%通过率的中等题
        //时间击败-100%，空间击败-75.65%
        if(num <= 10){
            return num;
        }
        string strNum = to_string(num);
        string result = strNum; //结果
        int length = strNum.size();
        for(int i = 0; i < length - 1; ++ i){
            for(int j = i + 1; j < length; ++ j){
                if(strNum[i] >= strNum[j]){
                    continue;
                }
                else{
                    swap(strNum[i], strNum[j]);
                    result = max(result, strNum);
                    swap(strNum[i], strNum[j]);
                }
            }
        }
        return atoi(result.c_str());
    }
};
