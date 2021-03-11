#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//7.8%, 69%
int main(){
    //基本思路，读入字符串，从后向前扫描
    //使用一个辅助结构来帮助去重，去重的同时保持数字间的前后关系
    string num;
    vector<char> appearedNums;
    cin >> num;
    //要用到下标
    for(int i = num.size() - 1; i >= 0; i--){
        if(count(appearedNums.begin(), appearedNums.end(), num[i]) == 1){
            //出现过这个数字，跳过
            continue;
        }
        else{
            //向尾部部插入元素
            appearedNums.emplace_back(num[i]);
        }
    }
    //遍历完毕，输出
    for(const auto & i : appearedNums){
        cout<<i;
    }
    return 0;
}
