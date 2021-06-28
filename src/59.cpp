class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //35分钟，好费时间，中等题，不过一次通过
        //时间击败-100%，空间击败-92.37%
        //模拟填入
        //vector<int>  nums(n * n,  0);
        //初始化
        vector<vector<int>> matrix;
        for(int i = 0;  i < n; i ++){
            matrix.emplace_back(vector<int>(n, 0));
        }
        int  num =1;
        //正方形，对角线是起始点
        for(int i = 0;  i <= (n/2); i ++){
            //i是起始点
            int right  = n -  i - 1;
            int down = n -  i - 1;
            //开始填入
            num = fillNum(matrix, make_pair(i,i), make_pair(i, right),  make_pair(down,  right), make_pair(down, i), num);
        }
        return matrix;
    }

    int fillNum(vector<vector<int>> &  _matrix,  pair<int,  int> _lt, pair<int,  int> _rt, pair<int,  int> _rd, pair<int,  int> _ld, int _num){
        int result  = _num;
        //填充上
        for(int i  = _lt.second;  i <= _rt.second; i ++){
            //cout<<i<<"*"<<result<<endl;
            _matrix[_lt.first][i] =  result;
            result ++;
        }
        //填充右
        for(int i = _rt.first + 1; i <= _rd.first; i++){
            //cout<<i<<"*"<<result<<endl;
            _matrix[i][_rt.second] = result;
            result ++;
        }
        //填充下
        for(int i = _rd.second - 1;  i >= _ld.second;  i-- ){
            //cout<<i<<"*"<<result<<endl;
            _matrix[_rd.first][i] = result;
            result ++;
        }
        //填充左
        for(int i = _ld.first - 1; i > _lt.first; i --){
          //cout<<i<<"*"<<result<<endl;
            _matrix[i][_ld.second] = result;
            result  ++;
        }
        return result;
    }
};
