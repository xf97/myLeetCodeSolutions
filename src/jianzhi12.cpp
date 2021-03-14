class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //二维矩阵的题一般要用回溯法，一直去探索
        //只有二十分钟时间了，不知道做不做得出来
        //递归加回溯，先去设计递归函数
        //要有一个记录使用过位置的数组
        //边界情况
        //自己的做法，78/87，有个奇怪的用例过不去，时间不够了，走了
        //找到了，没有回退状态导致的，通过了，耗时45分钟
        /*
        时间击败： 21.21%
        空间击败：18.78%
        */
        if(board.size() == 0 || word.size() == 0){
            return false;
        }
        else{
            vector<vector<bool>> visited;
            for(const auto & i: board){
                vector<bool> temp;
                for(const auto & j: i){
                    temp.emplace_back(false);
                }
                visited.emplace_back(temp);
            }
            //每个格子作为起始点都要去尝试
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[i].size(); j++){
                    //cout<<i<<" "<<j<<endl;
                    if(re_findPath(board, visited, word, 0, i, j)){
                        //找到一条路径
                        //cout<<"haha"<<endl;
                        return true;
                    }
                }
            }
            return false;
        }
    }

    //_index指的是现在到字符串中的第几个字符了
    //_col和_row代表当前的字符
    //_visited记录各自使用情况
    bool re_findPath(vector<vector<char>>& _board, vector<vector<bool>> & _visited, string _word, int _index, int _row, int _col){
        //首先判断递归边界
        //短路原则，保证不会溢出
        if(_row < 0 || _row >= _board.size() || _col < 0 || _col >= _board[_row].size() || _visited[_row][_col] == true){
            //首先应该考虑，万一点在边界，那么有方向不能扩展
            //当点无效时，直接false
            return false;
        }
        else if(_board[_row][_col] != _word[_index]){
            //然后字母不匹配也返回false
            return false;
        }
        else if(_index == _word.size() - 1 && _board[_row][_col] == _word[_index]){
            //找到路径
            //_visited[_row][_col] = true;
            return true;
        }
        else if(_board[_row][_col] == _word[_index]){
                //cout<<_row<<" "<<_col<<endl;
                //找到匹配，继续探索
                _visited[_row][_col] = true;
                bool result = re_findPath(_board, _visited, _word, _index + 1, _row - 1, _col) || re_findPath(_board, _visited, _word, _index + 1, _row + 1, _col) || re_findPath(_board, _visited, _word, _index + 1, _row, _col - 1) || re_findPath(_board, _visited, _word, _index + 1, _row, _col + 1);
                //回退状态
                _visited[_row][_col] = false;
                return result;
        }
        return false;
    }
};
