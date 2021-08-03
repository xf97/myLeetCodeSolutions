class Solution {
private:
    void findSum(vector<vector<int>> & result, vector<int> & tempResult, const vector<int> & candidates, const int target, const int first){
        int sum = accumulate(tempResult.begin(), tempResult.end(), 0);
        if(sum == target){
            //目标找到
            result.emplace_back(tempResult);
            return;
        }
        else if(sum > target){
            //正整数，没希望了
            return;
        }
        else{
            //还小再试探
            for(int i = first; i < candidates.size(); ++ i){
                //后不往前探索，因为已经被探索过了，就可以避免重复
                tempResult.push_back(candidates[i]);
                findSum(result, tempResult, candidates, target, i);
                tempResult.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //干翻蚂蚁金服！
        //注意无重复元素和正整数
        //是试探加回溯
        //很强，很棒，十五分钟，一次提交成功
        //时间击败-95.37%，空间击败-97.15%
        vector<vector<int>> result;
        //不用边界处理
        vector<int> _1Result;   //一次探索的结果
        //开始探索，记得释放加回溯
        //因为可以重复，所以不用加下标
        findSum(result, _1Result, candidates, target, 0);
        return result;
    }
};
