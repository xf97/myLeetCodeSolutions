#include <iostream>
#include <vector>
#include  <string>
#include <algorithm>
#include <set>

using namespace  std;

//被acm模式折磨的痛不欲生
//好长时间，不过终于弄懂了acm的输入模式
//时间击败-61%，空间击败-23%
int main(){
    //核心思想就是从后向前输出，已经输出过的不输出
    //最麻烦的是读取输入
    vector<vector<int>> idList;
    int group;
    cin>>group;    //测试组数
    //然后读取每一组的数据
    while(group--){
        int num;    //每一组的数量
        cin>>num;    //不用处理换行符，不是以文件形式传入
        vector<int> aGroup(num);
        //顺序读入每个数
        for(int i=0; i<num; i++){
            int temp;
            cin>>temp;
            aGroup[i] = temp;
        }
        idList.emplace_back(aGroup);
    }
    //现在顺次构造输出
    vector<vector<int>> result(idList.size());
    for(int i = 0; i < idList.size(); i++){
        set<int> alreadyAppear;    //已经出现过的数字
        for(int j = idList[i].size()-1; j >= 0; j--){
            if(find(alreadyAppear.begin(), alreadyAppear.end(), idList[i][j]) != alreadyAppear.end()){
                //已经出现过，那么不管他
                continue;
            }
            else{
                //否则，可以打印
                result[i].push_back(idList[i][j]);
                alreadyAppear.insert(idList[i][j]);
            }
        }
    }
    for(const auto & i: result){
        for(const auto & j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
