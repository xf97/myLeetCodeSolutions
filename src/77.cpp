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

        /*
        被垃圾C++折磨 的一天（好久不打全忘了）
        报错报的莫名其妙
       vector<vector<int> > result;
        vector valid(n, 0);
        vector<int>temp;
        for(int i = 0; i < valid.size(); i++){
            valid[i] = (i + 1);
        }
        iota(begin(valid), end(valid), 1);
        for(int i = 1; i <= n; i++){
            temp.push_back(i);
            valid[i - 1] = 0;
            recFind(result, valid, k, temp, 1);
            iota(begin(valid), end(valid), 1);
            //重新复制有效位数组
        }
        return result;
    }
    
    void recFind(vector<vector<int>> &  _res, vector<int> _valid, const int _k, const vector<int> _nowRes, const int _nowLev){
        if(_nowLev == _k){
            //达到长度
            _res.push_back(_nowRes);
            return;
        }
        else{
            for(int i = 0;i <= _valid.size(); i++){
                if(_valid[i] != 0){
                    auto temp = _nowRes;
                    temp.push_back(_valid[i]);
                    _valid[i] = 0;
                    recFind(_res, _valid, _k, temp, _nowLev + 1);
                }
                else{
                    continue;
                }
            }
        }
        return;
    }
    */
};
