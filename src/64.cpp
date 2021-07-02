class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //中等题，用dfs做，我可以记录每一条路径的路径和，然后拿出最小路径
        //又超时了，23/61，吐了，难道又是动态规划？
        //真的是动态规划，自己写吧
        //两次提交，十五分钟，时间击败-58.76%，空间击败-37.56%
        int length =  grid.size();  //m
        int weight =  grid[0].size();   //n，题目保证m n不为0
        //初始化二维数组
        vector<vector<int>> result(length,  vector<int>(weight));
        //初始化第一行
        result[0][0] = grid[0][0];
        for(int i=1; i<weight; i++){
            result[0][i] = result[0][i-1] +  grid[0][i];
        }
        //初始化第一列
        for(int j=1; j<length; j++){
            result[j][0] = result[j-1][0] +  grid[j][0];
        }
        //开始递推每一个格子
        for(int i=1; i<length; i++){
            for(int j=1; j<weight; j++){
                //这一个格子的数值来自左边或者上边小的那个数
                result[i][j] = min(result[i-1][j], result[i][j-1]) + grid[i][j];
            }
        }
        return result[length-1][weight-1];
        /*
        vector<int> pathSum;    //路径和保存
        //起点0,0 终点m-1,n-1
        findPath(0,  0, length -  1, weight - 1, 0, pathSum, grid);
        return *min_element(pathSum.begin(), pathSum.end());
    }

    void findPath(int _sX, int _sY, int _tX, int _tY, int _nowSum, vector<int> & _pathSum, const vector<vector<int>> & _grid){
        if(_sX == _tX && _sY  == _tY){
            //目标找到
            //cout<<_sX<<" "<<_sY<<" "<<_nowSum<<"  "<<_grid[_sX][_sY]<<"***"<<endl;
            _pathSum.push_back(_nowSum + _grid[_tX][_tY]);
            return;
        }
        else if(_sX > _tX || _sY > _tY){
            //超限
            return;
        }
        else{
            //继续向下探索
            //向下
            //cout<<_sX<<" "<<_sY<<" "<<_nowSum<<"  "<<_grid[_sX][_sY]<<endl;
            findPath(_sX + 1, _sY, _tX, _tY, _nowSum + _grid[_sX][_sY], _pathSum, _grid);
            //向右
            findPath(_sX, _sY + 1, _tX, _tY, _nowSum + _grid[_sX][_sY], _pathSum, _grid);
            return;
        }
        */
    }
};
