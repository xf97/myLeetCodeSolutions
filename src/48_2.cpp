class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //干翻微软
        //我先上下翻转然后对角线翻转
        //时间复杂度On，空间复杂度O1
        //二十五分钟，一次提交，时间击败-46.61%，空间击败-66.28%
        int m = matrix.size();
        int n = matrix[0].size();   //m行n列
        int temp = 0;   //交换的临时变量
        //上下翻转
        for(int row = 0; row < (m / 2); ++ row){
            for(int col = 0; col < n; ++ col){
                temp = matrix[row][col];
                matrix[row][col] = matrix[m - 1 - row][col];
                matrix[m - 1 - row][col] = temp;
            }
        }
        /*
        for(int row = 0; row < m; ++ row){
            for(int col = 0; col < n; ++ col){
                cout<<matrix[row][col]<<" ";
            }
            cout<<endl;
        }
        */
        //现在对角线翻转
        for(int row = 0; row < m; ++ row){
            for(int col = row + 1; col < n; ++ col){
                //cout<<row<<" "<<col<<endl;
                temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;                
            }
        }
        return;
    }
};
