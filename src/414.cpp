class Solution {
    //time defeat: 51.54%
    //space defeat: 19.18%
public:
    int thirdMax(vector<int>& nums) {
        //基本思想: 去重，排序取第三
        //先去重，利用set
        set<int> tempSet(nums.begin(), nums.end());
        nums.assign(tempSet.begin(), tempSet.end());
        sort(nums.begin(), nums.end()); //升序排序
        //边际情况
        if(nums.size() <= 2){
            return nums[nums.size()-1]; //不存在第三大的数，返回最大的
        }
        //普适情况
        return nums[nums.size()-3];
    }
};