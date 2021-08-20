class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //剑指offer原题
        //干翻腾讯CSIG
        //从右上角开始
        //比我大，就往下；比我小，就往左
        //时间复杂度Om+n，空间O1
        //题目保证m, n >= 1
        //五分钟，两次提交，时间击败-81.15%，空间击败-58.62%
        int m = matrix.size();  //m行n列
        int n = matrix[0].size();  
        int row = 0;
        int col = n - 1;
        while(row < m && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                -- col;
            }
            else{
                ++ row;
            }
        } 
        return false;
    }
};
