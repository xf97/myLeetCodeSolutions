class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
        //最最简单的思路，记录不能find的
        vector<int> result; //结果数组
        //会超时，通过31/34个
        for(int i = 1; i <= nums.size(); i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()){
                //找到不存在的，记录
                result.emplace_back(i);
            }
            else{
                continue;
            }
        }
        return result;
        */
        //另一种思路，先去重，然后排序，最后数数
        /*
        全部通过
        time defeat: 6.46%
        space defeat: 5.00%
        此方案实际上可以不去重，从而节省时间
        */
        /*
        int n = nums.size();
        set<int> tempSet(nums.begin(), nums.end());
        nums.assign(tempSet.begin(), tempSet.end());
        vector<int> result; //结果数组
        int i = 1, j = 0;   //双标出场
        for(; i <= n && j < nums.size();){
            //双标，i != nums[j]
            if(i == nums[j]){
                i++;
                j++;
            }
            else if(i != nums[j] && i > nums[j]){
                j++;
            }
            else if(i != nums[j] && i < nums[j]){
                result.emplace_back(i);
                i++;
            }
        }
        //检查双标
        while(i <= n){
            result.emplace_back(i);
            i++;
        }
        return result;
        */
        vector<int> result; //结果数组
        /*
        time defeat: 27.31%
        space defeat: 96.18%
        */
        //要用双标
        sort(nums.begin(), nums.end()); //排序还是必要的
        int i = 1, j = 0;   //i是数字，j是下标
        while(i <= nums.size() && j < nums.size()){
            if(i == nums[j]){
                //包含此数字
                i++;
                j++;
            }
            else if(i > nums[j]){
                //数组数字重复，推进一个下标
                j++;
            }
            else if(i < nums[j]){
                //缺失数字，记录并推进数字
                result.emplace_back(i);
                i++;
            }
        }
        //检查数组最大值未达到n的情况
        while(i <= nums.size()){
            result.emplace_back(i);
            i++;
        }
        return result;
    }
};