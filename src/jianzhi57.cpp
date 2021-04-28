class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //无结果，返回空vector
        //数组长度为1，同样也是返回空vector
        //数组中每个元素大于1
        //十分钟，一次提交，时间击败-61.05%，空间击败-23.53%
        vector<int> result;
        if(nums.size() <= 1){
            return result;
        }
        else{
            //确定一个数后，二分查找
            for(int i = 0; i < nums.size() && nums[i] <= (target - 1); i ++){
                int anotherFacIndex = getNumIndex(nums, target - nums[i]);
                if(anotherFacIndex != -1){
                    result.emplace_back(nums[i]);
                    result.emplace_back(nums[anotherFacIndex]);
                    return result;
                }
                else{
                    continue;
                }
            }
            //没得结果，返回空数组
            return result;
        }
    }

    int getNumIndex(const vector<int> & _nums, const int _target){
        if(_target < _nums[0] || _target > _nums[_nums.size() - 1]){
            //超过界限
            return -1;
        }
        else{
            //开始二分
            int sIndex = 0;
            int eIndex = _nums.size() - 1;
            while(sIndex <= eIndex){
                int mIndex = (sIndex + eIndex) / 2;
                if(_nums[mIndex] == _target){
                    return mIndex;
                }
                else if(_nums[mIndex] > _target){
                    //在左边
                    eIndex = mIndex - 1;
                }
                else{
                    //在右边
                    sIndex = mIndex + 1;
                }
            }
            //找不到
            return -1;
        }
    }
};
