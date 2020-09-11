class Solution {
        /*
         * 官方题解：
         * 时间击败：45.65%
         * 空间击败：10.41%
    public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k, int sum) {
        if (temp.size() + (n - cur + 1) < k || temp.size() > k) {
            return;
        }
        if (temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(cur);
        dfs(cur + 1, n, k, sum);
        temp.pop_back();
        dfs(cur + 1, n, k, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 9, k, n);
        return ans;
    }*/

	/*
	时间击败：6.03%
	空间击败：5.10%
	*/
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        //递归实现
        vector<int>sum{1, 3, 6, 10, 15, 21, 28, 36, 45};
        vector<vector<int>> result; //结果数组
        vector<int> temp; //每层递归用于保存当前结果的数组
        vector<int> valid(9, 0);  //有效位数组
        iota(valid.begin(), valid.end(), 1);
        recFind(result, temp, valid, n, k, sum);
        return result;
    }
    
    void recFind(vector<vector<int>> & _result, const vector<int> _nowResult, vector<int> _valid, const int _nowTarget, const int _lenLimit, const vector<int> & _sum){
        //超出时间限制：尝试剪枝和考虑极端情况
        if(_nowTarget == 36){
            vector<int> nowRes(8, 0);
            iota(nowRes.begin(), nowRes.end(), 1);
            _result.push_back(nowRes);
            return;
        }
        if(_nowTarget == 45){
            vector<int> nowRes(9, 0);
            iota(nowRes.begin(), nowRes.end(), 1);
            _result.push_back(nowRes);
            return;
        }
        auto temp = _nowResult; //保存本层结果 
        if(temp.size() > _lenLimit || _nowTarget < 0){
            return;
        }
        if(_nowTarget == 0 and temp.size() == _lenLimit){
            sort(temp.begin(), temp.end()); //对结果进行排序
            auto index = find(_result.begin(), _result.end(), temp);
            if(index  == _result.end()){
                //_result中不包含本次寻找的结果
                _result.push_back(temp);
            }
            return;
        }
        //当备选数组的最小值都大于可选的上界时，剪枝
        if(*min_element(_valid.begin(), _valid.end()) > _nowTarget){
            //cout<<"hahahah"<<endl;
            return;
        }
        //当备选数组之和小于预定目标时，剪枝
        if(accumulate(_valid.begin(), _valid.end(), 0) < _nowTarget){
            return;
        }
        else{
            for(int i = 0; i < _valid.size(); i++){
                    auto tempInt = _valid[i];   //暂时保存_valid[i]的值
                    _valid.erase(_valid.begin() + i);
                    temp.push_back(tempInt);
                    recFind(_result, temp, _valid, _nowTarget - tempInt, _lenLimit, _sum);
                    _valid.insert(_valid.begin() + i, tempInt); //插入
                    temp.pop_back(); //如果不选择该元素，则释放
            }
            return;
        }
    }
};
