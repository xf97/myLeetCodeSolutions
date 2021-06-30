class Solution {
public:
    int uniquePaths(int m, int n) {
        //这个感觉可以用回溯法直接解决
        //日常玷污中等题
        //十分钟，超时，37/62，dfs方法可以，但是他直接给我动态规划了
        //这个动态规划我也会，我来
        //动态规划，十分钟，一次提交，时间击败-100%，空间击败-40.08%
        //从左上到右下，先构造一个二维矩阵
        vector<vector<int>> matrix(m, vector<int>(n));  //m行n列
        //先初始化
        for(int  i=0; i<m; i++){
            matrix[i][0] =  1;  //初始化只有一条路径的情况
        }
        for(int i=0; i<n;  i++){
            matrix[0][i] = 1;
        }
        //然后从左上到右下，逐步推导
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                matrix[i][j] = matrix[i-1][j]+matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    /*
        //先处理一下边界情况
        if(m==1 && n==1){
            return 1;
        }
        //计算一下边界
        int right=n-1;  //最大右边界
        int down=m-1;   //最大下界
        int result=0;   //结果
        //开始递归向下
        findPath(0,0,down,right,result);
        return result;
    }

    void findPath(int _sX, int  _sY,  int _tX,  int  _tY,  int & _result){
        //目标情况
        if(_sX==_tX && _sY==_tY){
            _result++;
            return;
        }
        //超限情况
        else if(_sX>_tX || _sY>_tY){
            return;
        }
        else{
            //继续探索情况
            //向右
            findPath(_sX, _sY+1, _tX, _tY, _result);
            //向下
            findPath(_sX+1,  _sY, _tX, _tY, _result);
            return;
        }
        */
    }
};
