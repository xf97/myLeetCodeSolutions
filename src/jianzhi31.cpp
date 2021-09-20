class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //以pushed为轴心，模拟整个过程
        //栈中所有数字均不相等 
        stack<int> st;
        int popIndex = 0;
        int pushLength = pushed.size();
        int popLength =  popped.size();
        int pushIndex = 0;
        while(pushIndex < pushLength){
            st.push(pushed[pushIndex++]);
            //看看能不能出栈
            while(!st.empty() && st.top() == popped[popIndex]){
                popIndex ++;
                st.pop();
            }
        }
        return st.empty();
    }
};
