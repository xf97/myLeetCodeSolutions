class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //干翻蚂蚁金服！
        //当时在腾讯做的题，现在自己再做一次
        //一种想法是On时间，On空间
        //题目说能不能O1空间
        //可以，两次扫描——不行，如果确定哪个元素应该放哪里
        //操了，看了题解才知道，异或呀
        //五分钟，一次提交，时间击败-83.56%，空间击败-55.82%
        int result = 0;
        for(const int & i : nums){
            result ^= i;
        }
        return result;
    }
};
