class Solution {
public:
    bool judgeSquareSum(int c) {
        //感觉要用一点数学方法？
        //这是个中等题
        //如果是标准方法就是遍历，复杂度是On感觉
        //诶，好像是个动态规划可以做——看了题解后，不能动态规划，找不到前面元素和后面元素的关系，别挣扎了
        //仔细想了下又不太对，先用遍历看一遍
        //c >= 0
        //我草，十分钟，居然过了，一次提交
        //也太水了这中等题，我还以为会超时
        //时间击败-8.24%，空间击败-92.12%
        if(c <= 2){
            return true; 
        }
        else{
            for(int i = 0; i <= static_cast<int>(sqrt(c)); i++){
                int anotherFactor2 = c - i * i;
                if(static_cast<int>(sqrt(anotherFactor2)) * static_cast<int>(sqrt(anotherFactor2)) == anotherFactor2){
                    //另外一个数字也是平方的
                    return true;
                }
                else{
                    continue;
                }
            }
            return false;
        }
    }
};
