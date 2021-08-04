class Solution {
public:
    string removeDuplicates(string s) {
        //干翻蚂蚁金服！
        //用栈
        //边界情况
        //十分钟，一次提交，时间击败-46.30%，空间击败-17.33%
        int length = s.size();
        if(length <= 1){
            return s;
        }
        stack<char> chars;
        for(const char & c : s){
            if(chars.empty()){
                chars.push(c);
            }
            else if(chars.top() == c){
                chars.pop();
            }
            else{
                chars.push(c);
            }
        }
        //拼接结果
        string result = "";
        while(!chars.empty()){
            result += chars.top();
            chars.pop();
        }
        //翻转
        reverse(result.begin(), result.end());
        return result;
    }
};
