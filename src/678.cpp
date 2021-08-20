class Solution {
private:
    bool check1Char(const string & s, int index, int length, stack<char> brack){
        //递归边界条件
        if(index == length){
            if(brack.empty()){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            bool result = false;
            //如果是左括号的话，入栈，推进
            if(s[index] == '('){
                brack.push(s[index]);
                result = check1Char(s, index + 1, length, brack);
            }
            else if(s[index] == ')' && result == false){
                //cout<<index<<" "<<brack.size()<<endl;
                //边界判断
                if(brack.empty()){
                    return false;
                }
                else{
                    brack.pop();
                    result = check1Char(s, index + 1, length, brack);
                }
            }
            else if(s[index] == '*' && result == false){
                //如果为空，就压左括号
                if(brack.empty()){
                    brack.push('(');
                    result = check1Char(s, index + 1, length, brack);
                    if(result == false){
                        //压空
                        brack.pop();
                        result = check1Char(s, index + 1, length, brack);
                    }
                }
                else{
                    brack.pop();
                    result = check1Char(s, index + 1, length, brack);
                    if(result == false){
                        //压空
                        brack.push('(');
                        result = check1Char(s, index + 1, length, brack);
                    }
                    if(result == false){
                        //压左括号
                        brack.push('(');
                        result = check1Char(s, index + 1, length, brack);
                    }
                }
            }
            return result;
        }
    }
public:
    bool checkValidString(string s) {
        //干翻腾讯CSIG
        //我自己想的办法是用栈，和探索加回溯
        //果然超时，不行
        //用贪心，太强了，学到了
        /*
        int index = 0;
        stack<char> brack;
        int length = s.size();
        if(length == 0){
            return true;
        }
        //开始探索
        bool result = check1Char(s, index, length, brack);  //值传递
        return result;
        */
        int lower = 0, highest = 0; //分别表示最小左括号和最大左括号数
        for(const char & c : s){
            if(c == '('){
                ++ lower;
                ++ highest;
            }
            else if(c == '*'){
                lower = (lower > 0) ? lower - 1 : lower;
                ++ highest;
            }
            else{
                lower = (lower > 0) ? lower - 1 : lower;
                -- highest;
            }
            if(highest < 0){
                //最大左括号数字不能小于0
                return false;
            }
        }
        return lower == 0;  //大于0的话说明末尾有多余左括号
    }
};
