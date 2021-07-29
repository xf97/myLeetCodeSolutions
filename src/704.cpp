class Solution {
public:
    int search(vector<int>& nums, int target) {
        //干翻阿里巴巴
        //阿里你不行呀，你就面这种东西？
        //升序排列
        //不用处理边界情况
        //两分钟，一次提交，时间击败-94.03%，空间击败-21.70%
        //题目保证nums非空
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int middle = (left + right) / 2;
            if(nums[middle] == target){
                return middle;
            }
            else if(nums[middle] > target){
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
        }
        return -1;
    }
};
