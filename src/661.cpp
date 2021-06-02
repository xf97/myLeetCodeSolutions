class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        //最普通的方法，逐个点求值，时间复杂度ON2
        //题目保证输入的img不为空，最小为[1,1]
        //向下舍入
        //十分钟（代码比较多），一次提交，时间击败-25.43%，空间击败-5.12%
        int rows = img.size();  //行
        int cols = img[rows - 1].size();    //列
        vector<vector<int>> result; //结果数组
        //开始逐点访问
        for(int row = 0; row < rows; row ++){
            vector<int> aRow;
            for(int col = 0; col < cols; col ++){
                //计算本点的灰度值
                int grayValue = getGrayValue(img, rows, cols, row, col);
                aRow.emplace_back(grayValue);
            }
            result.emplace_back(aRow);
        }
        return result;
    }

    int getGrayValue(const vector<vector<int>> & _img, int _rowLimit, int _colLimit, int _row, int _col){
        int average = 0;    //灰度值
        int count = 0;  //有效的元素值
        //开始逐个产生周围八个点的坐标
        for(int i = (_row - 1); i <= (_row + 1); i ++){
            if(i < 0 || i >= _rowLimit){
                //无效行号
                continue;
            }
            else{
                for(int j = (_col - 1); j <= (_col + 1); j ++){
                    if(j < 0 || j >= _colLimit){
                        //无效列号
                        continue;
                    }
                    else{
                        count ++;
                        average += _img[i][j];
                    }
                }
            }
        }
        return static_cast<int>(average / count);
    }
};
