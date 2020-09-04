
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //使用回溯法求解
        auto solutions = vector<vector<string>>(); //保存解集，每行是形如“...Q...”的字符串
        auto queens = vector<int>(n, -1); //声明并初始化queens数组
        auto columns = unordered_set<int>(); //该集合用于记录哪一列被占用
        auto dia1 = unordered_set<int>(); //该集合用于记录“左上-右下”的对角线是否被占用
        auto dia2 = unordered_set<int>(); //右上-左下的对角线
        backtrack(solutions, queens, n, 0, columns, dia1, dia2); //开始回溯求解
        return solutions;
    }
    //使用引用，支持参数上修改
    //_row，开始操作的行
    void backtrack(vector<vector<string>> & _solutions, vector<int> & _queens, int n, int row, unordered_set<int> & _columns, unordered_set<int> & _dia1, unordered_set<int> & _dia2){
        if(row == n){
            //如果已经试探完了最后一行，则产生结果，记录入解决方案
            vector<string> board = generateBoard(_queens, n);
            _solutions.push_back(board); //压入解决方案数组
        }
        else{
            for(int i = 0; i < n; i++){
                //逐步试探这一行的每一列
                if(_columns.find(i) != _columns.end()){
                    //哦豁，这一列有其他皇后先占位了，溜了
                    continue;
                }
                int d1 = row - i; //左上-右下这条对角线的特征是行下标与列下表之差相等，d为差值
                if (_dia1.find(d1) != _dia1.end()){
                    continue;
                }
                int d2 = row + i; //再声明一个变量的原因是防止覆盖d1，这两个数值之后要保存（如果这个位置可以的话）
                if (_dia2.find(d2) != _dia2.end()){
                    continue;
                }
                //到现在，跟任何一个都不冲突，那么记录
                _queens[row] = i; //第row行的皇后放在第i列
                _columns.insert(i);
                _dia1.insert(d1);
                _dia2.insert(d2);
                //完成一行，再去下一行
                backtrack(_solutions, _queens, n, row + 1, _columns, _dia1, _dia2);
                /*为什么直接在下方写就能认为是应对试探失败的做法
                因为，如果函数正常执行，将会执行到row==n这一部分，就可以生成结果了
                凡是不能生成结果的，都会回到本层本次调用，接着向下执行
                */
                //如果下一行或（下若干行）试探失败，则回滚本次的结果
                _queens[row] = -1; 
                _columns.erase(i);
                _dia1.erase(d1);
                _dia2.erase(d2);
            }
        }
    }
    
    //每行排列输出函数
    vector<string> generateBoard(vector<int> & _queens, int n){
        auto board = vector<string>();
        for(int i = 0; i < n; i++){
            string row = string(n, '.');
            row[_queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};
