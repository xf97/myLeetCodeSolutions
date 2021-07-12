//只能够先对简单题重拳出击一下了
//又到了我最喜欢的牛客acm模式编程题时间了(不是)
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>   //控制输出精度
using namespace std;
//还是简单题好欺负
int main(){
    //n小于10000, m小于1000
    vector<int> nums;
    int temp = 0;
    while(cin>>temp){
        nums.push_back(temp);
    }
    vector<double> results;    //结果数组
    //每两个两个的向外取，然后分别计算和
    for(int i=0; i<nums.size(); i+=2){
        double n=static_cast<double>(nums[i]);    //首项
        int m=nums[i+1];    //持续几项
        double result=0.0;    //这一轮的结果
        while(m--){
            result += n;
            n = sqrt(n);
        }
        results.push_back(result);
    }
    for(const auto & i : results){
        cout<<fixed<<setprecision(2)<<i<<endl;
    }
    return 0;
}
