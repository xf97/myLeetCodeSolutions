class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //简单方法是一次循环
        //时间复杂度On,空间复杂度O1
        //数组长度大于等于1
        //一次提交，三分钟，时间击败-58.34%，空间击败-91.45%
        for(int i = 0; i < nums.size(); i ++){
            if(i != nums[i]){
                return i;
            }
            else{
                continue;
            }
        }
        //如果到结尾都没有，那么就是缺失最后的元素
        return nums.size();
    }
};
