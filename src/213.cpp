class Solution {
private:
    int linearRob(const vector<int> & nums, int left, int right){
        //注意right超出末尾
        if(right - left == 1){
            //一个元素
            return nums[left];
        }
        else if(right - left == 2){
            return max(nums[left], nums[left + 1]);
        }
        else{
            //开始动态规划
            vector<int> dp(right - left, 0);
            //初始化状态
            dp[0] = nums[left];
            dp[1] = max(nums[left], nums[left + 1]);
            //开始推进
            int p = 2;
            while(left + p < right){
                //cout<<left<<" "<<p<<" "<<right<<" "<<left+p<<endl;
                dp[p] = max(dp[p - 2] + nums[left + p], dp[p - 1]);
                p += 1;
            }
            //cout<<right - 1<<endl;
            //正整数，偷到最后一定是最大的
            return dp[p - 1];
        }
    }
public:
    int rob(vector<int>& nums) {
        //来了，干翻腾讯
        //专业打家劫舍，动态规划升级版
        //感觉要特殊处理后两个房间
        //[1,2,3,4,5,6,7]
        //看了题解，我错了，不过没看代码，根据我的想法差不多
        //干活
        //动态规划
        //边界处理
        //二十五分钟，一次提交
        //时间击败-100%，空间击败-11.81%
        //题目保证数组不为空
        int length = nums.size();
        if(length == 1){
            return nums[0];
        }
        else if(length == 2){
            return max(nums[0], nums[1]);
        }
        else{
            //开始动态规划
            //两个方案，要第一个房间，不要最后一个
            //要最后一个，不要第一个，两个分别计算，要最大的
            int result1 = linearRob(nums, 0, length - 1);
            int result2 = linearRob(nums, 1, length);
            return (result1 > result2) ? result1 : result2;
        }
    }
};
