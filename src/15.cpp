class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //我来了，接着复仇字节
        //我感觉可以逐级缩小问题
        //三数之和等于0，两数之和等于0-某个数，一个数字等于0-某个数-另一个数
        //看了题解，不行，要用排序加双指针来做，把时间复杂度降到On2
        //十分钟，一次提交，时间击败-60.91%，空间击败-81.37%
        vector<vector<int>>  results;
        sort(nums.begin(), nums.end());
        //开始遍历
        //要保持最开始这个是最小的
        //大循环中++i比i++快
        int length = nums.size();
        for(int i = 0; i <  length -  2; ++ i){
            //跳过重复元素，与上一个得不一样
            if(i != 0 && nums[i -1] == nums[i]){
                continue;
            }
            //否则，锁定了i
            //现在开始找第二个和第三个元素的位置
            int k = length - 1;
            int target = 0  -  nums[i];
            for(int j = i + 1;  j < length - 1; ++ j){
                //同样的跳过重复元素
                if(j != i + 1 && nums[j -1] == nums[j]){
                    continue;
                }
                //右端收进来并进，汇总双指针
                while(j <  k  && nums[j] + nums[k] > target){
                    //收进来，数字是逐渐缩小的，如果缩到和第二个重合都大于，那就是没救了
                    --k;
                }
                //判断
                if(j == k){
                    continue;   //没救了
                }
                //如果不等于，就没救了
                if(nums[j] + nums[k] == target){
                    //找到一个解
                    results.push_back({nums[i], nums[j], nums[k]});   //花括号初始法
                }
            }
        }
        return results;
    }
};
