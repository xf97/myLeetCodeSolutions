class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //哈希值，一个0，一个2
        //时间复杂度-On
        //七分钟，一次提交，时间击败-10.77%，空间击败-6.37%
        map<int, int> numAndCount;
        //初始化
        int index = 1;
        for(int i = 1; i <= nums.size(); i++){
            numAndCount[i] = 0;
        }
        //遍历
        for(const auto & i : nums){
            numAndCount[i] ++;
        }
        //返回结果
        vector<int> result(2, 0);
        //找到0和1的元素
        //再次遍历
        for(auto i = numAndCount.begin(); i != numAndCount.end(); i ++){
            if((i->second == 2)){
                result[0] = i->first;
            }
            if(i->second == 0){
                result[1] = i->first;
            }
        }
        return result;
    }
};
