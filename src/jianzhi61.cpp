class Solution {
public:
    bool isStraight(vector<int>& nums) {
        //今天时间不够，就做个简单题保持下手感
        //干翻出这个题的公司
        //第一次提交，五分钟，197/203
        //两次提交，七分钟，时间击败-100%，空间击败-68.15%
        sort(nums.begin(), nums.end());
        int _0Count = 0;    //大小王的数量
        int missCount = 0;  //要补的牌的数量
        //开始遍历
        int length = nums.size();
        for(int i = 0; i < length - 1; ++ i){
            if(nums[i] == 0){
                ++ _0Count;
            }
            else if(nums[i] + 1 == nums[i + 1]){
                continue;
            }
            else if(nums[i] == nums[i + 1] && nums[i] != 0){
                return false;
            }
            else{
                //缺失数字
                //统计补到那个数字要几张牌
                int temp = nums[i] + 1;
                while(temp < nums[i + 1]){
                    ++ temp;
                    ++ missCount;
                }
            }
        }
        if(missCount == 0){
            //不缺失数字
            return true;
        }
        if(_0Count >= missCount){
            //缺数字，但是能补
            return true;
        }
        return false;
    }
};