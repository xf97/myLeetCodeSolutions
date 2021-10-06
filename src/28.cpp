class Solution {
public:
    int strStr(string haystack, string needle) {
        //这个简单，做两道题，恢复手感
        //先从简单的开始
        //简单的遍历，复杂度Omn
        //七分钟，一次提交，时间击败-12.62%，空间击败-79.35%
        int n = haystack.size();    
        int m = needle.size();
        if(m == 0){
            return 0;
        }
        int maxLimit = n - m;
        for(int i = 0; i <= maxLimit; ++ i){
            int j = i;
            while(j < n && j - i < m && haystack[j] == needle[j - i]){
                ++ j;
            }
            if(j - i == m){
                return i;
            }
            else{
                continue;
            }
        }
        return -1;
    }
};
