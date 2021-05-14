class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        //题目要求mat最少有一行
        //十分钟，一次提交，时间击败-81.47%，空间击败-13.62%
        int height = mat.size();    //有几行
        int width = 0;
        if(height > 0){
            width = mat[0].size();  //有几列
        }
        //判断能否重塑
        if(height * width != r * c){
            return mat;
        }
        //可以重塑
        vector<vector<int>> result;
        //初始化填充值
        for(int i = 0; i < r; i++){
            vector<int> aRow;
            for(int j = 0; j < c; j++){
                aRow.emplace_back(0);
            }
            result.emplace_back(aRow);
        }
        //遍历每一个原矩阵元素
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                //计算重塑后的行列号
                //最难就是这里
                int num = (i * width) + j;
                int row = (num) / c;
                int col = num - (c * row);
                result[row][col] = mat[i][j];
            }
        }
        //返回结果
        return result;
    }
};
