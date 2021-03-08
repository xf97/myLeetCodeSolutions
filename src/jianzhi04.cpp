class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        //又到了复习看书所得的时间
        /*
        time defeat: 92.99%
        space defeat: 75.49%
        */
        //边界情况
        if(matrix.empty()){
            return false;
        }
        else{
            //普适情况
            //从右向左，从上到下，开始扫描
            //获取行数和列数
            int rows = 0;
            int rowsLimit = matrix.size() - 1;
            int cols = matrix[0].size() - 1;
            while(rows <= rowsLimit && cols >= 0){
                //cout<<rows<<" "<<cols<<endl;
                if(matrix[rows][cols] == target){
                    return true;
                }
                else if(matrix[rows][cols] > target){
                    cols --;
                }
                else{
                    rows ++;
                }
            }
            return false;
        }
    }
};
