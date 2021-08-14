class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //干翻蚂蚁金服！
        //感觉会溢出，试一试，想耍赖
        //不会溢出，但是有0
        //不使用除法，而且On时间，那就是不能乘起来
        //不偷鸡了
        //思维僵住了，可以计算前缀和后缀的乘积来得到答案
        //二十分钟，两次提交，时间击败-87.31%，空间击败-47.44%
        int length = nums.size();
        vector<int> result(length, 0);
        //先填充前缀左边元素的乘积
        result[0] = 1;
        for(int i = 1; i < length; ++ i){
            result[i] = result[i - 1] * nums[i - 1];
        }
        //然后把右侧的直接乘上来
        int right = 1;
        for(int i = length - 1; i >= 0; -- i){
            result[i] = result[i] * right;
            right *= nums[i];
        }
        return result;
        /*
        long long mulSum = 1;
        int length = nums.size();
        vector<int> result(length, 0);
        //先乘一遍
        for(const int & i : nums){
            mulSum *= i;
        }
        //然后赋值
        for(int i = 0; i < length; ++ i){
            if(nums[i] == 0){
                result[i] = 
            }
            result[i] = mulSum / nums[i];
        }
        return result;
        */
    }
};
