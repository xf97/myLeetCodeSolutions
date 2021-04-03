class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //数组非空，总是存在半数以上的元素
        //方法一：排列，然后返回中位数
        //赖皮方法，一次通过，时间击败：71.47%，空间击败：35.48%
        if(nums.size() == 1){
            return nums[0];
        }
        /*
        else{
            sort(nums.begin(), nums.end());
            return nums[(nums.size() >> 1)];
        }
        */
        else{
            //方法二：使用一个计数器，遇到相同元素就加1
            //五分钟，一次提交，时间击败：97.65%，空间击败：46.85%
            int count = 1;
            int result = nums[0];
            for(int i = 1; i < nums.size(); i++){
                if(count == 0){
                    //计数器为0，就重新初始化计数器
                    count ++;
                    result = nums[i];
                }
                else if(nums[i] == result){
                    count ++;
                }
                else{
                    count --;
                }
            }
            return result;
        }
    }
};
