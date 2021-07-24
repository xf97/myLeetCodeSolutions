class Solution {
public:
    bool isValid(string s) {
        //干翻字节！
        //用栈，时间复杂度On，空间复杂度On
        //五分钟，两次提交，粗心了，时间击败-100%，空间击败-44.17%
        int length = s.size();
        //边界处理
        if(length <= 1){
            return false;
        }
        stack<char> parStack;
        for(int i = 0; i < length; ++ i){
            //左括号压入
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                parStack.push(s[i]);
            }
            //右括号，只有在栈顶元素对应时才出栈，否则报错
            else if(!parStack.empty()){
                char topPar = parStack.top();
                if(s[i] == ')' && topPar == '('){
                    parStack.pop();
                }
                else if(s[i] == ']' && topPar == '['){
                    parStack.pop();
                }
                else if(s[i] == '}' && topPar == '{'){
                    parStack.pop();
                }
                else{
                    return false;
                }
            }
            else{
                //空栈
                return false;
            }
        }
        //末尾处理
        return parStack.empty();
    }
};
