class Solution {
    /*
官方题解
我填入注释
顺序-行优先
采用-递归-回溯的方法，逐个探查
*/
private:
    bool line[9][9];    //行被占用情况数组，当line[x][y] = True时，说明第x行已经填入过数字(y-1)
    bool column[9][9];  //列被占用数组，当column[x][y] = True时，说明第y列已经填入过数字(x-1)
    bool block[3][3][9];    //九宫格被占用数组，当block[x][y][i] = True时，表明第(x, y)个九宫格中已经填入过数字(i-1)
    bool valid; //递归有效位
    vector<pair<int, int>> spaces;  //记录空白格位置的数组

public:
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            //如果所有位置都已被探查，则结束递归
            valid = true;   //valid的作用终止循环吗？是的，如果在递归的下层获得了解，则可以中断上层的循环
            return;
        }
        //从spaces中取出的是一个二维坐标(x, y)，表示数独数组中将要被填值的位置
        auto [i, j] = spaces[pos];
        for (int digit = 0; digit < 9 && !valid; ++digit) {
            if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
                //当行、列、和九宫格中都没填入该数字时，尝试填入
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                //首先记录填入信息，↑
                board[i][j] = digit + '0' + 1;
                //然后向数独数组中填入值
                dfs(board, pos + 1);    //递归回溯，考察位置向前推进1
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
                //如果不填入该数字，则释放它，考虑尝试下一个数字 
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line, false, sizeof(line));  //初始化
        memset(column, false, sizeof(column));  //初始化
        memset(block, false, sizeof(block));    //初始化
        valid = false;

        //探查内部情况，了解可用空间
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);  //如果是空白格，则压入需要填值的元素位置
                    //emplace_back相对于push_back更加快速，且压入(i, j)则会自动压入pair(i, j)
                }
                else {
                    //如果是数字
                    //board[i][j] - '0'就能够获得数字，然后因为数组从0开始下标，而我们的数字从1开始，因此计算下标需再向下-1
                    int digit = board[i][j] - '0' - 1;
                    line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;  //填值
                }
            }
        }

        dfs(board, 0);  //基本情况已经了解，开始递归加回溯
    }
};
