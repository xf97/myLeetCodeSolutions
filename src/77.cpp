/*
class Solution {
public:
    //以后可以尝试使用全局变量来记录递归值
    vector<int> temp; //记录已经被选中的数字
    vector<vector<int>> ans; //返回结果集
    //深度优先递归
    //cur: 当前位置
    void dfs(int cur, int n, int k) {
        // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }
        // 记录合法的答案
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        //每个位置都存在选择和不选择两种情况
        // 考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        // 考虑不选择当前位置
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        //递归，逐个枚举
        dfs(1, n, k);
        return ans;
    }
};
*/
class Solution {
private:
    void dfs(int first, int curr, int limit, int length, vector<int> path, vector<vector<int>> & result, const vector<int> & nums){
        //要剪枝
        //剩余的长度不可能构造出我需要的长度
        if(limit - curr > length - first){
            return;
        }
        else if(curr == limit){
            //递归终点
            result.emplace_back(path);
            return;
        }
        else if(first == length){
            //超限
            return;
        }
        else{
            //压入本元素
            path.emplace_back(nums[first]);
            dfs(first + 1, curr + 1, limit, length, path, result, nums);
            //弹出本元素
            path.pop_back();
            dfs(first + 1, curr, limit, length, path, result, nums);
            return;
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        //干翻出这个题的公司
        //感觉探索加回溯
        //十分钟，一起提交，超时，26/27
        //十二分钟，两次提交，时间击败-11.76%，空间击败-7.69%
        vector<int> nums(n, 0);
        for(int i = 1; i <= n; ++ i){
            nums[i - 1] = i;
        }
        vector<vector<int>> result;
        if(k == n){
            result.emplace_back(nums);
            return result;
        }
        //相当于从nums中选k个数
        vector<int> path;
        //开始dfs
        dfs(0, 0, k, n, path, result, nums);
        return result;
    }
};