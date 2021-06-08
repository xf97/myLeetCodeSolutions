class Solution {
public:
    int countBinarySubstrings(string s) {
        //一开始读不懂题目，或者说，不能理解一道62.8%通过率的题目居然这么难
        //然后看了题解，顿悟，现在自己实现
        //五分钟，一次提交，时间复杂度-On, 空间复杂度-O1
        //时间击败-86.42%，空间击败-76.57%
        //s.size() >= 1
        int length = s.size();
        //边界情况
        if(length <= 1){
            return 0;
        }
        int index = 0, lastLength = 0, result = 0;
        while(index < length){
            char c = s[index];
            int count = 0;
            while(index < length && c == s[index]){
                index ++;
                count ++;
            }
            result += min(lastLength, count);
            lastLength = count;
        }
        return result;
    }
};
