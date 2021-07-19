class Solution {
private:
    void getACircle(int _left,  int _up,  int _down, int _right, vector<int> & _result, const vector<vector<int>> _matrix){
        //上
        for(int i = _left; i <= _right; ++i){
            //cout<<"up"<<endl;
            _result.push_back(_matrix[_up][i]);
        }
        //右
        for(int i = _up + 1; i <= _down;++ i){
            //cout<<"right"<<endl;
            _result.push_back(_matrix[i][_right]);
        }
        //下
        for(int i = _right - 1; i >= _left; -- i){
            //cout<<"down"<<endl;
            if(_up != _down){
                //只有一行
                _result.push_back(_matrix[_down][i]);
            }
        }
        //左
        for(int i = _down - 1; i > _up; -- i){
            //cout<<"left"<<endl;
            if(_left != _right){
                _result.push_back(_matrix[i][_left]);
            }
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //干翻字节！
        //这个其实不难，一圈一圈的来，代码比较麻烦
        //最少有一行一列
        //搞定，面对非矩阵的，就不用对角线，用左上和右下两个下标来
        //二十分钟，三次提交，时间击败-100%，空间击败-87.19%
        //时间复杂度-Omn
        int m = matrix.size();
        int n =  matrix[0].size();  //m行n列
        vector<int> result;
        //计算每一圈的起始点
        int left = 0;
        int up = 0;
        int right = n - 1;
        int down = m -1;
        while(left <= right &&  up <= down){
            getACircle(left, up, down, right, result, matrix);
            left ++;
            up ++;
            right --;
            down --;
        }
        return result;
    }
};
