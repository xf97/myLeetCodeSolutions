class Solution {
public:
    string convert(string s, int numRows) {
        //题目开始给我整懵了，Z字型
        //中等题，试试
        //从前向后，扫描字符串，然后填充二维数组
        //边界情况
        //三次提交，二十五分钟，时间击败-5.60%，空间击败-4.97%
        if(numRows == 1){
            return s;
        }
        else if(s.size() == numRows){
            return s;
        }
        else{
            //声明并初始化二维数组
            //使用一个不会出现的字符作为标识符
            vector<string> zigMatrix;
            for(int row = 0; row < numRows; row ++){
                string tempStr(s.size(), '#');
                zigMatrix.emplace_back(tempStr);
            }
            //然后遍历的下表
            int row = 0;
            int col = 0;
            bool flag = false;  //false表示在直路，true表示在斜路
            //开始填充二维数组
            for(const char & c : s){
                //cout<<c<<" ";
                zigMatrix[row][col] = c;    
                //到底了吗
                if(flag == false){
                    //在走直路
                    if(row == (numRows - 1)){
                        //走到最底下了
                        row --;
                        col ++;
                        flag = true;
                    }
                    else{
                        //就往下走
                        row ++;
                    }
                }
                else{
                    //在走斜路
                    if(row == 0){
                        //走到顶了
                        row ++;
                        flag = false;
                    }
                    else{
                        row --;
                        col ++;
                    }
                }
            }
            /*
            for(const auto & i : zigMatrix){
                cout<<i<<endl;
            }
            */
            //重组，输出字符串
            string result = "";
            for(const auto & i : zigMatrix){
                for(const auto & j : i){
                    if(j != '#'){
                        result.push_back(j);
                    }
                }
            }
            return result;
        }
    }
};
