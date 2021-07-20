class Solution {
private:
    void searchIslands(vector<vector<char>> & _grid, int _x,  int _y,  int _xLimit, int _yLimit){
        if(_x < _xLimit && _y < _yLimit && _grid[_x][_y] == '1'  ){
            //置空
            _grid[_x][_y] = '0';
            //向四周蔓延
            //上
            if(_y - 1 >= 0){
                searchIslands(_grid,  _x,  _y - 1, _xLimit, _yLimit);
            }
            //左
            if(_x - 1 >= 0){
                searchIslands(_grid,  _x - 1,  _y, _xLimit, _yLimit);
            }
            //右
            if(_y + 1 <  _yLimit){
                searchIslands(_grid,  _x,  _y + 1, _xLimit, _yLimit);
            }
            //下
            if(_x + 1 < _xLimit){
                searchIslands(_grid, _x + 1,_y, _xLimit, _yLimit);
            }
        }
        else{
            //不要蔓延
            return;
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        //就这？我还以为要干嘛呢
        //干翻字节！
        //十五分钟，两次提交，时间击败-99.85%，空间击败-89.03%
        int result = 0; //结果
        //题目保证grid不为空
        int length = grid[0].size();
        int  weight = grid.size();
        //逐个试探，On2的复杂度
        for(int  i = 0; i < weight; ++ i){
            for(int  j = 0; j < length; ++ j){
                if(grid[i][j] == '1'){
                    result  ++;
                    //搜索连通岛屿
                    searchIslands(grid, i, j, weight, length);
                }
            }
        }
        return result;
    }
};
