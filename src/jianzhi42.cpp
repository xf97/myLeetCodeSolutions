class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //一次遍历，解决问题
        //三次通过，感觉不像个简单题
        //时间击败：45.65%，空间击败：61.83%
        //还可以用动态规划做
        //遍历到第i个的情况，i=0 or f(i-1)<=0, f(i) = i
        //i>0 and f(i-1)>0, f(i) = f(i-1) + i
        if(nums.size() == 1){
            return nums[0];
        }
        else{
            //处理i=0的情况
            int maxSum = nums[0];   //初始化最大值
            int tempSum = nums[0];  //暂存值
            //开始遍历
            for(int i = 1; i < nums.size(); i++){
                //要应对所有都是负数的情况
                if(tempSum < 0 && tempSum < nums[i]){
                    tempSum = nums[i];
                }
                else{
                    tempSum += nums[i];
                    }
                if(tempSum > maxSum){
                    maxSum = tempSum;
                }
            }
            return maxSum;
        }
    }
};
