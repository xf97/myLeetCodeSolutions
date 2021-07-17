class Solution {
public:
    int rob(vector<int>& nums) {
        //拼多多我来啦，虐杀中等题(膨胀)
        //动态规划，偷了左边就不能偷右边
        //递推公式想出来了，第i个房间能偷到最多钱是 f(i) = max(f(i-2) + m(i), f(i-1))
        //感觉一维空间就可以了
        //五分钟，第一次提交，60/68通过
        //十分钟，共三次提交，时间击败-38.87%，空间击败-41.53%
        vector<int> result(nums.size(),  0);
        //要初始化一些值
        //那么就要考虑边界情况
        int length = nums.size();
        if(length == 1){
            return nums[0];
        }
        if(length ==  2){
            return max(nums[0], nums[1]);
        }
        //处理好了，对nums[0-2]赋值
        //能投到的物品都是非负价值
        result[0] = nums[0];
        result[1] = max(nums[1], nums[0]);
        //result[2] = nums[0] +  nums[2];
        for(int i =  2; i < length; ++i){
            result[i] = max(nums[i] + result[i - 2], result[i - 1]);
        }
        return result[length - 1];
    }
};
