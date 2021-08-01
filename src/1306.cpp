class Solution {
private:
    bool findIndex(const vector<int> & _arr, const int _length, vector<bool> & _vis, int _index){
        //递归边界
        if(_arr[_index] == 0){
            return true;
        }
        else if(_vis[_index]){
            //已经访问过
            return false;
        }
        else{
            //标记访问
            _vis[_index] = true;
            //确保下两个位置不会超出界限
            int left = (_index - _arr[_index] >= 0) ? _index - _arr[_index] : -1;
            int right = (_index + _arr[_index] < _length) ? _index + _arr[_index] : -1;
            bool result = false;
            if(left != -1){
                result = findIndex(_arr, _length, _vis, left);
            }
            if(result == false && right != -1){
                result = findIndex(_arr, _length, _vis, right);
            }
            return result;
        }
    }
public:
    bool canReach(vector<int>& arr, int start) {
        //干翻蚂蚁金服
        //试探+回溯
        //要记录已经访问的位置
        //十分钟，一次提交，时间击败-99.72%，空间击败-40.65%
        vector<bool> vis(arr.size(), false);
        //逐个试探
        return findIndex(arr, arr.size(), vis, start);
    }
};
