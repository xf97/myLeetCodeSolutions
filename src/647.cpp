class Solution {
public:
    int countSubstrings(string s) {
        int result = 0; //结果
        int length = s.size();
        //开始遍历回文中心
        for(int i = 0; i < length; ++ i){
            for(int j = 0; j <= 1; ++ j){
                //回文中心有一个或者两个的情况
                int left = i;
                int right = i + j;
                while(left >= 0 && right < length && s[left--] == s[right++]){
                    result ++;
                }
            }
        }
        return result;
    }   
};
