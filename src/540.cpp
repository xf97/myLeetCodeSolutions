class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //干翻拼多多
        //先当舔够
        //字典，哈希表
        //边界处理
        //时间复杂度On，空间复杂度On
        //先舔过了，一次提交，五分钟，时间击败-26.29%，空间击败-5.00%
        //然后，应该是要二分查找
        //时间复杂度Ologn，空间O1
        /*
        if(nums.size() == 1){
            return nums[0];
        }
        unordered_map<int, int> numAndCount;
        for(const int & i : nums){
            numAndCount[i] ++;
        }
        //再次遍历
        for(auto iter = numAndCount.begin(); iter != numAndCount.end(); ++ iter){
            if((*iter).second == 1){
                return (*iter).first;
            }
            else{
                continue;
            }
        }
        return -1;
        */
        //想出来饿了，用数组长度
        //左边一样，为奇朝左，为偶朝右
        //右边一样，为奇朝右，为偶朝左
        //左右都不一样，找到
        //想法完全是对的，二十分钟，一次提交
        //时间击败-97.16%，空间击败-97.25%
        //边界处理
        int length = nums.size();
        if(length == 1){
            return nums[0];
        }
        int left = 0;
        int right = length - 1;
        while(left <= right){
            int middle = (left + right) / 2;
            //cout<<middle<<endl;
            //跟左边一样吗
            if(middle == 0 || middle == length - 1){
                return nums[middle];
            }
            if(nums[middle - 1] == nums[middle]){
                int size = middle - left + 1;
                if(size & 0x1){
                    right = middle - 2;
                }
                else{
                    left = middle + 1;
                }
            }
            else if(nums[middle + 1] == nums[middle]){
                //跟右边一样吗
                int size = right - middle + 1;
                if(size & 0x1){
                    left = middle + 2;
                }
                else{
                    right = middle - 1;
                }
            }
            else{
                return nums[middle];
            }
        }
        return -1;
    }
};
