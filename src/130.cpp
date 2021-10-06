class Solution {
private:
    void dfs(const vector<vector<char>> & board, vector<vector<int>> & vis, int row, int col, int rowLimit, int colLimit){
        //边界判断
        if(row < 0 || row >= rowLimit || col < 0 || col >= colLimit){
            return;
        }
        else if(vis[row][col] == 1){
            return;
        }
        else if(board[row][col] == 'O'){
            //如果当前是'O'，则标记
            vis[row][col] = 1;
            //向上下左右探索
            dfs(board, vis, row - 1, col, rowLimit, colLimit);
            dfs(board, vis, row + 1, col, rowLimit, colLimit);
            dfs(board, vis, row, col - 1, rowLimit, colLimit);
            dfs(board, vis, row, col + 1, rowLimit, colLimit);
            return;
        }
        else{
            //否则，结束dfs
            return;
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        //用题目的话说
        /*
        在边界上的，或者与边界上的O相连的O不会被填充成X
        */
        //两次提交，十分钟，时间击败-97.38%，空间击败-21.36%
        int m = board.size();   //m行
        int n = board[0].size();    //n列
        //题目保证矩阵不为空
        vector<vector<int>> vis(m, vector<int>(n, 0));
        //然后将所有边界上的、或者与边界上相连的O都标记为1
        //上
        for(int i = 0; i < n; ++ i){
            if(board[0][i] == 'O'){
                //开始探索并标记
                dfs(board, vis, 0, i, m, n);
            }
        }
        //下
        for(int i = 0; i < n; ++ i){
            if(board[m - 1][i] == 'O'){
                //开始探索并标记
                dfs(board, vis, m - 1, i, m, n);
            }
        }   
        //左
        for(int i = 0; i < m; ++ i){
            if(board[i][0] == 'O'){
                dfs(board, vis, i, 0, m, n);
            }
        }     
        //右
        for(int i = 0; i < m; ++ i){
            if(board[i][n - 1] == 'O'){
                dfs(board, vis, i, n - 1, m, n);
            }
        }
        //遍历board，开始改写
        for(int i = 0; i < m; ++ i){
            for(int j = 0; j < n; ++ j){
                //cout<<vis[i][j]<<" ";
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    //不是边界或者与边界相连的点
                    board[i][j] = 'X';
                }
            }
            cout<<endl;
        }
        return;
    }
};
