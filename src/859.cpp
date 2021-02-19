class Solution {
    /*
    time defeat: 5.56%
    space defeat: 95.45%
    */
public:
    bool buddyStrings(string A, string B) {
        //同时遍历，有且只能有两个字符不同
        //还有另一种情况，两个字符串完全相同，并且存在同一字母出现多于两次的情况
        //边际情况
        if(A.size() != B.size()){
            return false;
        }
        //另一种边际情况
        if(A == B){
            int maxCount = 0;
            for(int i = 0; i < A.size(); i++){
                if(maxCount <= count(A.begin(), A.end(), A[i])){
                    maxCount = count(A.begin(), A.end(), A[i]);
                }
            }
            return maxCount >= 2;
        }
        //否则，同时遍历
        //以下数据结构用来记录字符串不同的部分
        //当且仅当以下数组长度为2且两个元素互为相反是是亲密字符串
        vector<pair<char, char>> indexAndDifference; 
        for(int i = 0; i < A.size(); i++){
            if(A[i] != B[i]){
                indexAndDifference.emplace_back(make_pair(A[i], B[i]));
            }
        } 
        //判断结果
        //首先是判断长度
        if(indexAndDifference.size() != 2){
            return false;
        }
        //然后是判断是否元素相反
        if(indexAndDifference[0].first == indexAndDifference[1].second && indexAndDifference[0].second == indexAndDifference[1].first){
            return true;
        }
        else{
            return false;
        }
    }
};