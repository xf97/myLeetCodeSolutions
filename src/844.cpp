class Solution {
/*
time defeat: 100%
space defeat: 34.84%
time consuming: 14 mins
*/
public:
    //基本思路，扫描两个字符串，逐步组出最终字符串
    bool backspaceCompare(string S, string T) {
        string finalS = ""; //保存S的最终字符串
        string finalT = ""; //保存T的最终字符串
        for(auto c: S){
            if(finalS.empty() && c == '#'){
                //忽略空字符串的退格
                continue;
            }
            else if(c == '#'){
                //弹出字符串的末尾元素
                finalS.pop_back();
            }
            else{
                //字母情况，压入
                finalS.push_back(c);
            }
        }
        for(auto c: T){
            if(finalT.empty() && c == '#'){
                //忽略空字符串的退格
                continue;
            }
            else if(c == '#'){
                //弹出字符串的末尾元素
                finalT.pop_back();
            }
            else{
                //字母情况，压入
                finalT.push_back(c);
            }
        }
        //处理完成，比较
        //C++中string已经重载了==符号
        if(finalS == finalT){
            return true;
        }
        else{
            return false;
        }
    }
};
