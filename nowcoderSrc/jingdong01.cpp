//东子哥，我来了
//简单题我重拳出击
//好像，这不是一个简单题诶
//东子哥，你坑我，这是一个动态规划诶
//不过不好意思，我刚好会
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        //动态规划
        //递推公式-gift(x, y) = max(gift(x-1,y), gift(x, y-1)) + board[x][y]
        //因此要处理第0行和第0列
        //规定6*6
        //十分钟，一次提交通过
        vector<vector<int>> gift(6,  vector<int>(6,0));    //初始化，每个元素>100小于1000，因此不会超限
        //初始化第一行和第一列
        gift[0][0] = board[0][0];
        //第一行
        for(int i=1; i<6;  i++){
            gift[0][i] = gift[0][i-1]+ board[0][i];
        }
        //第一列
        for(int j=1; j<6; j++){
            gift[j][0] = gift[j-1][0]+board[j][0];
        }
        //然后开始递推
        for(int i=1; i<6; i++){
            for(int j=1; j<6; j++){
                gift[i][j] = max(gift[i-1][j], gift[i][j-1]) + board[i][j];
            }
        }
        return gift[5][5];    //因为礼物价值没有负数，所以拿得越多越划算
    }
};
