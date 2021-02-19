class Solution {
    /*
    time defeat: 100.00%
    space defeat: 94.99%
    */
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string intervalString = "->";   //区间连接标志
        //一次遍历，使用开始和结束下标标定区间
        vector<string> result;
        //边际情况
        if(nums.size() == 0){
            return result;
        }
        //另一种边际情况
        if(nums.size() == 1){
            //cout<<nums[0]<<endl;
            //cout<<to_string(nums[0])<<endl;
            result.emplace_back(to_string(nums[0]));
            return result;
        }
        //开始遍历，数组有序
        //区间开始和结束的下表
        for(int i = 0; i < nums.size();){
            int j = i;
            for(;j < nums.size() - 1;j++){
                if(nums[j] + 1 == nums[j + 1]){
                    continue;
                }
                else{
                    break;
                }
            }
            if(i == j){
                result.emplace_back(to_string(nums[i]));
            }
            else{
                //cout<<i<<" "<<j<<endl;
                result.emplace_back(to_string(nums[i]) + intervalString + to_string(nums[j]));
            }
            i = j + 1;
        }
        return result;
    }
};