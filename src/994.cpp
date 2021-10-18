class Solution {
private:
    int freshOrange = 0;
    int rotOrange = 0;
    void doRot(vector<vector<int>> & grid, int rowLimit, int colLimit){
        for(int row = 0; row < rowLimit; ++ row){
            for(int col = 0; col < colLimit; ++ col){
                if(grid[row][col] == 2){
                    //向四周扩散
                    //cout<<row<<"*"<<col<<endl;
                    if(row >= 1 && grid[row - 1][col] == 1){
                        grid[row - 1][col] = 3;
                        freshOrange --;
                    }
                    if(row < rowLimit - 1 && grid[row + 1][col] == 1){
                        grid[row + 1][col] = 3;
                        freshOrange --;
                    }
                    if(col >= 1 && grid[row][col - 1] == 1){
                        grid[row][col - 1] = 3;
                        freshOrange --;
                    }
                    if(col < colLimit - 1 && grid[row][col + 1] == 1){
                        grid[row][col + 1] = 3;
                        freshOrange --;
                    }
                }
            }
        }
        for(int row = 0; row < rowLimit; ++ row){
            for(int col = 0; col < colLimit; ++ col){
                if(grid[row][col] == 3){
                    grid[row][col] = 2;
                }
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //dfs深搜的题目
        //先统计新鲜橘子和腐烂橘子的数目
        int m = grid.size();
        int n = grid[0].size(); //数组不为空
        for(int i = 0; i < m; ++ i){
            for(int j = 0; j < n; ++ j){
                if(grid[i][j] == 1){
                    freshOrange ++;
                }
                else if(grid[i][j] == 2){
                    rotOrange ++;
                }
            }
        }
        if(freshOrange == 0){
            return 0;
        }
        if(rotOrange == 0){
            return -1;
        }
        int result = 0; //结果
        int prevOrange = freshOrange;   //记录前值
        while(freshOrange > 0){
            //开始腐烂
            doRot(grid, m, n);
            //cout<<prevOrange<<" "<<freshOrange<<endl;
            if(freshOrange == prevOrange){
                return -1;  //情况未改变，永远不会腐烂
            }
            prevOrange = freshOrange;
            result ++;
        }
        return result;
    }
};
