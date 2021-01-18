class Solution {
public:
    string countAndSay(int n) {
        //递归
        if(n == 1){
            return to_string(n);
        }
        else{
            //否则，自己这一项就等于对上一项进行解释
            string lastNum = countAndSay(n - 1);
            //cout<<lastNum<<endl;
            //然后，描述这个字符串
            vector<string> sameNumString;
            string tempStr = "";
            for(int i = 0; i < lastNum.size(); ){
                tempStr.append(1, lastNum[i]); 
                if(i == lastNum.size() - 1){
                    sameNumString.emplace_back(tempStr);
                    break;
                }
                if(lastNum[i] == lastNum[i+1]){
                    i ++;
                }
                else{
                    sameNumString.emplace_back(tempStr);
                    tempStr = "";
                    i++;
                }
            }
            string resultStr = "";
            for(int i = 0; i < sameNumString.size(); i++){
                resultStr += to_string(sameNumString[i].size());
                resultStr.append(1, sameNumString[i][0]);
            }
            return resultStr;
        }
        return "";
    }
};