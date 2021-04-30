class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //从剑指offer上学到的思想，一次遍历解决
        //用位运算，时间复杂度On，空间复杂度O1
        //[2]就返回2
        //[2,3]和[2,3,3]是非法测试用例，不会出现
        //一次提交，十五分钟，时间击败-35.80%，空间击败-47.00%
        if(nums.size() == 1){
            return nums[0];
        }
        else{
            int result = 0;
            //每个元素都是32位的
            for(int i = 0 ; i < 32; i ++){
                //当前这一位加起来是多少
                int bitSum = 0;
                for(const auto & num : nums){
                    bitSum += ((num >> i) & 1); //要最低位
                }
                //看这个最低位存不存在数字
                if(bitSum % 3 != 0){
                    //这一位有这个数字，将这一位置1
                    //因为现在的这个数字在原来是右移第几位的
                    //所以现在要用左移几位加回去
                    result |= (1 << i);    
                }
            }
            return result;
        }
    }
};
