class Solution {
public:
    int findLHS(vector<int>& nums) {
        //题目就很难理解，现在开始做
        //最简单的暴力法（感觉可以哈希一下），时间复杂度On2，空间O1
        //得，果然超时，167/206
        //两次提交，十五分钟，时间击败-20.61%，空间击败-43.13%
        //要用哈希
        //并不需要的边界处理
        if(nums.size() <= 1){
            return 0;
        }
        int result = 0;
        //我想通了，就是求num+1的元素个数
        //手动count
        map<int, int> numAndLength;
        for(const auto & num : nums){
            if(numAndLength.find(num) != numAndLength.end()){
                numAndLength[num] ++; 
            }
            else{
                numAndLength[num] = 1;
            }
        }
        for(auto i = numAndLength.begin(); i != numAndLength.end(); i++){
            if(numAndLength.find((i->first) + 1) != numAndLength.end()){
                result = max(result, numAndLength[i->first] + numAndLength[(i->first) + 1]);
            }
        }
        /*
        //cout<<1<<endl;
        for(int i = 0; i < nums.size(); i++){
            int length = 0; //子序列长度
            bool flag = false;  //是否有比i大1的元素出现
            for(int j = 0; j < nums.size(); j++){
                //cout<<i<<" "<<j<<endl;
                if(nums[i] == nums[j]){
                    length ++;
                }
                else if((nums[j] + 1) == nums[i]){
                    length ++;
                    flag = true;
                }
                else{
                    continue;
                }
            }
            if(flag == true){
                result = (result > length) ? result : length;
            }
        }
        */
        return result;
    }
};
