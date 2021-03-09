//题目保证了输入的有效性
//去重加排序，用set
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
time defeat: 55.8%
space defeat: 44.8%
*/

int main(){
    vector<int> inputNums;
    int tempNum = 0;    //暂存变量
    while(cin >> tempNum){
        inputNums.emplace_back(tempNum);
    }
    //获取了输入以后，开始分组
    int i = 0;    //遍历下标
    vector<int> result;
    while(i < inputNums.size()){
        int length = inputNums[i];    //获取长度
        int tempLength = length;
        set<int> nums;
        while(length > 0){
            nums.insert(inputNums[i + length]);
            length --;
        }
        //排序
        result.assign(nums.begin(), nums.end());
        sort(result.begin(), result.end());
        //输出
        for(const auto & i : result){
            cout<<i<<endl;
        }
        //置空
        result.clear();
        i += (++tempLength);    //更新下标
    }
    return 0;
}
