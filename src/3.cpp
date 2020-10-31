class Solution {
public:
    /*
    最基础的思想-逐个遍历，逐个向前推进
    time defeat: 12%
    space defeat: 9%
    time consuming: 20 mins
    */
    int lengthOfLongestSubstring(string s) {
        //边际情况
        if(s.empty()){
            return 0;
        }
        if(s.size() == 1){
            return 1;
        }
        int maxLength = 0;  //最大子串长度
        for(int index = 0; index < s.size()  && (index + maxLength) < s.size() ; index ++){
            int tempLength = 0; //当前遍历子串长度　
            string subStr = ""; //当前子串
            for(int nowIndex = index; nowIndex < s.size(); nowIndex ++){
                //判断重复了吗
                if(subStr.find(s[nowIndex])  < subStr.size()){
                    //是重复元素了
                    //更新长度
                    maxLength = tempLength > maxLength? tempLength : maxLength;
                    //开启下一轮循环
                    break;
                }
                else{
                    //不重复，更新暂时长度
                    subStr += s[nowIndex];  //更新当前子串
                    tempLength ++;
                }
            }
            //如果整个字符串无重复，则能够执行到此步
            maxLength = tempLength > maxLength? tempLength : maxLength; //更新长度
        }
        return maxLength;
    }
};
