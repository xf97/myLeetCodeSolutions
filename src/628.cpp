class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        /*
        //最简单的方法，暴力三重遍历
        //超时，71/91
        int maxMulValue = nums[0] * nums[1] * nums[2];
        //边界情况
        if(nums.size() == 3){
            return maxMulValue;
        }
        for(int i = 0; i < nums.size() -2 ; i ++){
            for(int j = i + 1; j < nums.size() - 1; j++){
                for(int z = j + 1; z < nums.size(); z++){
                    if(maxMulValue <= (nums[i] * nums[j] * nums[z])){
                        maxMulValue = (nums[i] * nums[j] * nums[z]);
                    }
                }
            }
        }
        return maxMulValue;
        */
        //思考一下，3种情况
        //全为正数，那么就是三个最大的数
        //全为负数，那么也是三个最大的数
        //正负都有，那么是三个最大的数，或者两个绝对值最大的数和一个正数的
        //time defeat: 91%
        //space defeat: 83%
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return max(nums[len-1]*nums[len-2]*nums[len-3], nums[0]*nums[1]*nums[len-1]);
    }
};