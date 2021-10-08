class Solution {
private:
    int rowLimit;
    int colLimit;
    bool dfs(vector<vector<char>> & board, string word, int row, int col, int index){
        //边界处理或错误处理
        if(row < 0 || row >= rowLimit || col < 0 || col >= colLimit || board[row][col] != word[index]){
            return false;
        }
        if(index == word.size() - 1){
            //找到了
            return true;
        }
        //进入下一步搜索
        //先置空这一个，防止搜回来
        board[row][col] = '\0';
        //短路原则，可以防止重复搜索
        bool result = dfs(board, word, row + 1, col, index + 1) || dfs(board, word, row - 1, col, index + 1) || dfs(board, word, row, col + 1, index + 1) || dfs(board, word, row, col - 1, index + 1);
        //不对，要回溯
        board[row][col] = word[index];
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        //学习了简练的写法
        //开始写
        //board不为空
        rowLimit = board.size();
        colLimit = board[0].size();
        //逐一检查每一个空格
        for(int i = 0; i < rowLimit; ++ i){
            for(int j = 0; j < colLimit; ++ j){
                //再剪枝，只有当字母匹配时才dfs
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
