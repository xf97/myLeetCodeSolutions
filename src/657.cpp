class Solution {
public:
    bool judgeCircle(string moves) {
        //一分钟，一次提交，时间击败-53.65%，空间击败-71.21%
        //时间复杂度On级别
        return (count(moves.begin(), moves.end(), 'U') == count(moves.begin(), moves.end(), 'D')) && (count(moves.begin(), moves.end(), 'L') == count(moves.begin(), moves.end(), 'R'));
    }
};
