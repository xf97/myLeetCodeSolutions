class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //逐步分解，递归向下
        //数组大小为1-6
        //数组元素不重复
        vector<vector<int>> result;
        if(nums.size() == 1){
            result.emplace_back(nums);
            return result;
        }
        //我先耍赖吧
        //五分钟，一次提交，时间击败-100%，空间击败-91.06%
        sort(nums.begin(), nums.end());
        do{
            result.emplace_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return result;
    }
};
