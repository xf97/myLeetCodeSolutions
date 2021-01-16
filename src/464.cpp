class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        //又到了我啥都不会的动态规划了
        //看了题解，用的是我还是会一点的递归加回溯
        /* 边界情况*/
        if(maxChoosableInteger >= desiredTotal){
            return true;
        }
        /*另一个边界情况，等差数列求和都无法达到要求*/
        if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 <desiredTotal)
        {
            return false;
        }
        //剩下的，就要记录哪个数字用过，哪个没用过
        //state[i] = 'i'就表示i被用过，state[0]没有作用，故多初始化一个空间
        vector<char> state(maxChoosableInteger + 1, 'n'); 
        map<string, bool> memory;   //记录怎么抽数字可以赢
        //递归回溯
        return reTrace(desiredTotal, state, memory);
    }

    //state不能引用传递，那么递归中会反复修改该值
    bool reTrace(int _desiredTotal, vector<char> _state, map<string, bool> & _memory){
        //首先是确定当前修改状态，在之前的探索中有没有遇到
        //遇到的话，结果如何
        string nowState;
        nowState.insert(nowState.begin(), _state.begin(), _state.end());
        //cout<<1<<endl;
        if(_memory.count(nowState) != 0){
            return _memory[nowState];
        }
        //cout<<2<<endl;
        //没遇到过，就去探索
        for(int i = 1; i < _state.size(); i++){
            //从1开始，因为0对累加和没作用
            if (_state[i] == 'n')
            {
                //没用过  
                //置位
                _state[i] = 'i';
                if(_desiredTotal - i <= 0 || !reTrace(_desiredTotal - i, _state, _memory)){
                    //如果可以，那么获得结果
                    _memory[nowState] = true;   //说明到这一步先手的朋友有机会赢
                    _state[i] = 'n';    //置位回去
                    return true;
                }
                    _state[i] = 'n';    //不能赢也置位回去
            }
        }
                //cout<<3<<endl;
        //这种情况赢不了，置位
        _memory[nowState] = false;
        return false;
    }
};
