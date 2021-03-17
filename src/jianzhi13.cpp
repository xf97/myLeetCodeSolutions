class Solution {
public:
    int movingCount(int m, int n, int k) {
        //继续膨胀，触碰中等题
        //书上的标准解法回溯法，我怎么感觉通过数学的遍历法也能算出来
        //不太行，能通过34/49，数学法错误的原因应该是是“走”这个动作没有模拟
        //那还是按照回溯法来做吧
        //45分钟，时间击败: 100%，空间击败：25.59%
        //边界条件
        if(k == 0){
            return 1;
        }
        else{
            //根据题目，k是个正整数，m和n同样是正整数
            //从0，0开始起步，逐步试探每一个格子，如果满足就+1，不满足就不加
            //要解决重复进入同一个格子的问题
            vector<bool> visited(m * n, false);
            int result = 0; //答案
            result = backtrackFind(m, n, k, 0, 0, visited);
            return result;
        }
    }

    int backtrackFind(const int & _rowLimit, const int & _colLimit, const int & _target, const int & _nowRow, const int & _nowCol, vector<bool> & _visited){
        //首先判断是否超限或者是否被走过
        if(_nowRow < 0 || _nowRow >= _rowLimit || _nowCol < 0 || _nowCol >= _colLimit || _visited[_nowRow * _colLimit + _nowCol] == true){
            return 0;
        }
        //判断是否符合
        else if(lessThanK(_nowRow, _nowCol, _target)){
            //符合
            _visited[_nowRow * _colLimit + _nowCol] = true; //标记访问
            int count = 0;
            //向前后左右继续探索
            count = 1 + backtrackFind(_rowLimit, _colLimit, _target, _nowRow - 1, _nowCol, _visited) + backtrackFind(_rowLimit, _colLimit, _target, _nowRow + 1, _nowCol, _visited) + backtrackFind(_rowLimit, _colLimit, _target, _nowRow, _nowCol + 1, _visited) + backtrackFind(_rowLimit, _colLimit, _target, _nowRow, _nowCol - 1, _visited);
            //要不要回退状态？先观察
            return count;
        }
        else{
            //不符合，回退
            return 0;
        }
    }

   bool lessThanK(int _num1, int _num2, const int & _limit){
        int temp = 0;
        //先对_num1进行取各位
        while(_num1){
            temp += _num1 % 10;
            _num1 /= 10;
        }
        //再对_num2取各位
        while(_num2){
            temp += _num2 % 10;
            _num2 /= 10;
        }
        //比较
        if(temp <= _limit){
            return true;
        }
        else{
            return false;
        }
    }
    /*
        else{
            int result = 0;
            //这时候应该去遍历每一个方格
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(lessThanK(i, j, k)){
                        result ++;
                    }
                }
            }
            return result;
        }
    }

 
    */
};
