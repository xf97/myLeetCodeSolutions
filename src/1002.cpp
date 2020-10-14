class Solution {
/*
time defeat: 13%
space defeat: 56%
time consuming: 40 mins
*/
public:
    vector<string> commonChars(vector<string>& A) {
        map<char, int> _1stStrCharCount;    //该字典用来保存第一个字符串中各个字符的出现次数
        for(char c: A[0]){
            //数组A长度默认大于等于1
            if(_1stStrCharCount.count(c) == 0){
                //只有没有统计过这个字符的出现次数时才count
            _1stStrCharCount[c] = count(A[0].begin(), A[0].end(), c);
            }
        }
        vector<string> result;  //结果字符串
        //然后去遍历其他字符串
        //极端情况
        if(A.size() == 1){
            for(char c: A[0]){
                string temp;
                temp.push_back(c);
                result.emplace_back(temp);
            }
            return result;
        }
        //否则，从第二个字符串开始遍历
        for(int i = 1; i < A.size(); i++){
            //cout<<A[i]<<endl;
            for(auto  c =  _1stStrCharCount.begin(); c != _1stStrCharCount.end(); c ++){
                //检查每个字符，拿出常用字符
                //c是指针，使用->访问元素，(*c)是元素，使用成员运算符.访问元素 
                int countNum = count(A[i].begin(), A[i].end(), (*c).first);
                //cout<<c->first<<" "<<countNum<<endl;
                if(countNum == 0){
                    //出现在第一个字符串中的字母没有出现在本字符串中，置0
                    (*c).second  = 0;
                }
                else{
                    //否则出现过该字符，取count和原值的最小值
                   c->second = countNum <  c->second ? countNum : c->second;
                }
            }
        }
        //然后，根据字典，构造返回结果
        for(auto c : _1stStrCharCount){
            int countNum = c.second;
            while(countNum > 0){
                string temp;
                temp.push_back(c.first);
                result.emplace_back(temp);
                countNum --;
            }
        }
        return result;
    }
};
