class Solution {
private:
    unordered_set<int> appearDigit;   //出现过的元素
public:
    int firstMissingPositive(vector<int>& nums) {
        //干翻pdd！希望今晚的笔试顺利
        //要求时间复杂度On，空间复杂度O1
        //困难题
        //未排序的数组，不能排序，排序的复杂度超了
        //以空间换时间，遍历一遍后记录数组中有什么的元素和最小正数的信息
        //万一没有正数呢，没有正数就返回1
        //十分钟，一次提交，时间击败-6.23%，空间击败-5.09%
        int maxPositive = INT_MIN;    //最大正数
        for(const auto & i : nums){
            appearDigit.insert(i);  //记录出现过的元素
            if(i >0 && i > maxPositive){
                maxPositive = i;
            }
        }
        //万一没有正数的判断
        if(maxPositive == INT_MIN){
            return 1;
        }
        else{
            //有正数的判断
            //当存在极端大数时，这个时间复杂度会很大
            for(int i = 1; i <= maxPositive; ++ i){
                if(appearDigit.find(i) == appearDigit.end()){
                    return i;
                }
                else{
                    continue;
                }
            }
            return maxPositive + 1;
        }
    }
};
