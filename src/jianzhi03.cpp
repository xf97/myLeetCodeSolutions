class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //我在看这本书，现在我来！
        //用最好的办法
        //边界情况，看题目数组非空
        //一次遍历，解决问题
        //要用到下标
        /*
        time defeat: 88.29%
        space defeat: 99.06%
        */
        int temp = 0;   //暂存变量
        for(int i = 0; i < nums.size(); i++){
            //关键在于如果没有重复的话，下标i上的数字就是i
            if(nums[i] == i){
                continue;
            }
            else{
                if(nums[i] == nums[nums[i]]){
                    //在属于他的位置上已经放着他了，那么重复
                    return nums[i];
                }
                else{
                    while(nums[i] != i){
                        //否则，把他放到他的位置去
                        //很奇怪，这里nums[temp]如何改成nums[i]的话会超时
                        //应该是重复修改吗
                        temp = nums[i];
                        nums[i] = nums[temp];
                        nums[temp] = temp;
                }
            }
        }
        }
        return 0;
    }
};
