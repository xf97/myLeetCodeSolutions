#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//7.74%, 75.81%
int main(){
    //顺序读取输入，按8位分割
    vector<string> result;
    string cacheStr = "";
    string temp = "";
    while(getline(cin, cacheStr)){
        if(cacheStr.empty()){
            cout<<cacheStr<<endl;
        }
        while(cacheStr.size() > 8){
            temp = cacheStr.substr(0, 8);
            result.emplace_back(temp);
            cacheStr = cacheStr.substr(8);
        }
        //处理非8整数长度的字符串
        if(cacheStr.size() > 0){
            cacheStr.append(8 - cacheStr.size(), '0');
        }
        result.emplace_back(cacheStr);
    }
    //输出
    for(const auto & i : result){
        cout<<i<<endl;
    }
    return 0;
}
