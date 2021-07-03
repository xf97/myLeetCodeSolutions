class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        //现在开始主攻中等题
        //一个一个算，复杂度O(圆的数量 *点的数量)
        //点跟圆都至少有一个
        //十分钟，这个中等题也有点菜
        //暴力成功，一次提交，时间击败-36.38%，空间击败-78.63%
        vector<int> result(queries.size(), 0);
        for(int  i=0; i<queries.size(); i++){
            int count = 0;  //在这个圆内点的数量
            for(int j=0; j<points.size(); j++){
                if(isInACircle(queries[i][0], queries[i][1], queries[i][2], points[j][0], points[j][1])){
                    count ++;
                }
            }
            result[i] = count;
        }
        return result;
    }

    //感觉没啥好办法，就暴力破解
    bool isInACircle(int _cX, int _cY, int _r, int _pX, int _pY){
        //_cX, _cY圆心，_r半径，_pX, _pY点坐标
        //要计算距离
        double distance =  sqrt((_cX -  _pX) * (_cX - _pX) + (_cY - _pY) * (_cY - _pY));
        bool result = (distance <= static_cast<double>(_r));
        return result; 
    }
};
