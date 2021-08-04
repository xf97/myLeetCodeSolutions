class Solution {
private:
    int findPeakIndex(const vector<int> & nums, int left, int right){
        //边界情况处理，题目说超出范围的nums[-1]和nums[n]是负无穷
        if(left > right){
            return -1;  
        }
        else if(right - left == 0){
            return left;
        }
        else if(right - left == 1){
            //长度为2
            return nums[left] > nums[right] ? left : right;
        }
        else{
            //长度大于等于3
            int middle = (left + right) / 2;;
            if(nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1]){
                return middle;
            }
            //往小于那边走，保持问题规模
            else if(nums[middle] <= nums[middle - 1]){
                right = middle;
            }
            else{
                left = middle;
            }
            return findPeakIndex(nums, left, right);
        }
    }
public:
    int findPeakElement(vector<int>& nums) {
        //干翻蚂蚁金服
        //这是我蚂蚁链面试的面试题
        //Ologn来个二分
        //nice，不错，一次提交，自己做的
        //时间击败-86.72%，空间击败-49.24%
        int left = 0;
        int right = nums.size() - 1;
        //int middle = (left + right) / 2;
        int result = findPeakIndex(nums, left, right);
        return result;
    }
};
