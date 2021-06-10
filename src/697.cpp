class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        //两次扫描，第一次确定度，第二次确定最短数组长度
        //多次扫描了，为了求度，为了求最短数组，感觉时间复杂度是On2
        //数组非空，非负数
        //不容易，这么大的复杂度居然没超时，感觉微微比普通简单题难一些
        //十二分钟，两次提交，时间击败-88.85%，空间击败-85.49%
        if(nums.size() <= 1){
            return nums.size();
        }
        map<int, int> numAndCount;
        //map默认值为0
        for(int i : nums){
            numAndCount[i] ++;
            //cout<<i<<" "<<numAndCount[i]<<endl;
        }
        //获取度
        int maxDegree = 0;
        for(auto i = numAndCount.begin(); i != numAndCount.end(); i ++){
            if(maxDegree < i->second){
                maxDegree = i->second;
            }
        }
        //边界情况
        if(maxDegree == 1){
            return 1;
        }
        vector<int> degrees;
        for(auto i = numAndCount.begin(); i != numAndCount.end(); i ++){
            if(i->second == maxDegree){
                degrees.emplace_back(i->first);
            }
        }
        //然后找首尾出现下标，要最短的
        int length = nums.size();
        for(auto degree : degrees){
            int left = -1, right = nums.size();
            for(int i = 0; i < nums.size(); i ++){
                if(nums[i] == degree && left == -1){
                    left = i;
                }
                else if(nums[i] == degree){
                    right = i;
                }
            }
            //cout<<degree<<" "<<left<<" "<<right<<endl;
            length = min(length, right - left + 1);
        }
        return length;
    }
};
