class Solution {
public:
    vector<string> permutation(string s) {
        //中等题，才是我最爱的
        //问题可以分解：全排列=第一个字符＋后面字符串的全排列
        //那么问题就可以逐步缩小
        //四次通过，主要花在去重上面
        //时间击败：8.96%，空间击败：12.77%
        vector<string> result;
        if(s == ""){
            result.emplace_back("");
            return result;
        }
        //利用重载
        permutation(s, 0, result);  //0是当前操作位置，result以引用形式传入
        //一次去重
        set<string> temp(result.begin(), result.end());
        result.clear();
        result.assign(temp.begin(), temp.end());
        return result;
    }

    void permutation(string & _str, int _index, vector<string> & _result){
        //递归终止条件是，第一个字符到末尾了
        if(_index == _str.size()){
            //if(find(_result.begin(), _result.end(), _str) == _result.end()){
                string temp(_str.begin(), _str.end());  //因为是引用，担心深浅拷贝的问题
                //要注意不重复的问题，回去统一去重
                _result.emplace_back(temp);
            //}
        }
        else{
            //从当前位置向后，逐个将后面那些字母交换过来
            for(int i = _index; i < _str.size(); i++){
                char temp = _str[i];    //基本类型，构造函数和析构函数的开销不大
                _str[i] = _str[_index];
                _str[_index] = temp;
                //交换了一个了，向下
                permutation(_str, _index + 1, _result);
                //复原
                temp = _str[i];
                _str[i] = _str[_index];
                _str[_index] = temp;
            }
        }
    }
};
