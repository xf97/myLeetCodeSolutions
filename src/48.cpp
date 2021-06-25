class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //n*n 正方形矩阵 
        //做过类似的题，一圈一圈，由外向里
        //比较费时间，开始
        //今早烦的一批，就直接这个吧 
        int n = matrix.size();
        if(n == 1){
            return;
        }
        //int n = matrix.size();
        // C++ 这里的 = 拷贝是值拷贝，会得到一个新的数组
        auto matrix_new = matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_new[j][n - i - 1] = matrix[i][j];
            }
        }
        // 这里也是值拷贝
        matrix = matrix_new;
        /*
        //计算每圈的起始点
        for(int i=0; i < (n/2); i++){
            int length =  (n - i * 2);
            //开始旋转一圈
            rotate1Circle(i,  length, n, matrix);
            //cout<<i<<","<<i<<","<<length<<endl;
        }
        return;
        */
    }
    /*
    void rotate1Circle(int _sPoint, int _side, int _n, vector<vector<int>>& _matrix){
        vector<int> tempSide(_side, 0); //(_matrix[_sPoint].begin(),  _matrix[_sPoint].end());
        //cout<<_sPoint<<","<<_side<<","<<_n<<endl;
        //上换右
        for(int i =_sPoint; i<_sPoint+_side;i++){
            //计算右侧的对应点位
            tempSide[i-_sPoint] = _matrix[i][_sPoint+_side-1];
            //赋值
            _matrix[i][_sPoint+_side-1] = tempSide[i-_sPoint];
            cout<<_matrix[i][_sPoint+_side-1]<<" "<<i<<"  "<<_sPoint+_side-1<<endl;
            //swap( _matrix[i][_sPoint+_side-1], tempSide[i-_sPoint]);
        }
        //右换下 
        for(int i=_sPoint;i<_sPoint+_side;i++){
            //计算下侧的点位 
            //_matrix[_sPoint+_side-1][_sPoint+_side-1+(i-_sPoint)]
            swap( _matrix[_sPoint+_side-1][_sPoint+_side-1-(i-_sPoint)], tempSide[i-_sPoint]);
        }
        //下换左
        for(int i=_sPoint+_side-1;i>_sPoint;i--){
            //计算左侧的对应点位
            //_matrix[_sPoint+_side-1-(i-_sPoint)][_sPoint]
            swap( _matrix[_sPoint+_side-1-(i-_sPoint)][_sPoint], tempSide[(_sPoint+_side-1)-i]);
        }
        //左换上
        for(int i=_sPoint+_side-1;i>_sPoint;i--){
            //计算上侧的对应点位
            //_matrix[_sPoint][_sPoint+(_sPoint+_side-1)-1]
            swap( _matrix[_sPoint][_sPoint+(_sPoint+_side-1)-1], tempSide[(_sPoint+_side-1)-i]);
        }
        */
    //}
};
