class Solution {
/*
我懂了，数学题
要均匀
x的范围是[rx-r, rx+r]
y的范围是[ry-r, ry+r]
并且(x-rx)^2 + (y-ry)^2 <= r^2
自己的方法是对的，不过不太细心，提交了四次
25分钟，时间击败-84.76%，空间击败-49.59%
*/
private:
    double r;   //半径
    double rx;  //圆心x
    double ry;  //圆心y
    random_device rd;   //随机数种子
    default_random_engine rng {rd()};
public:
    Solution(double radius, double x_center, double y_center): r(radius), rx(x_center), ry(y_center) {
        //srand(time());
    }
    
    vector<double> randPoint() {
        uniform_real_distribution<> xValues{rx - r, rx + r};    //x范围
        uniform_real_distribution<> yValues{ry - r, ry + r};    //y范围
        double tempX = xValues(rng);
        double tempY = yValues(rng);
        while(pow(abs(tempX - rx), 2) + pow(abs(tempY - ry), 2) > r * r){
            tempX = xValues(rng);
            tempY = yValues(rng);         
        }
        vector<double> result(2);
        result[0] = tempX;
        result[1] = tempY;
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
