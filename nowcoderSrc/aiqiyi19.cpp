//又到了我最喜欢的牛客acm模式时间
//开冲
#include <iostream>
#include <cmath>    //要用10的次方
#include <sstream> //要用到string转换
using namespace std;

//这是一个逆向思路的题
//先找规律，以位数去考虑
//或者二分法，一个一个去尝试
//还是看了题解，基本上了解了
//自己实现
//头大，还学会了一个二分查找

long long  getSum(long long _num){
    long long result = 0;
    while(_num > 0){
        result += _num;
        _num /= 10;
    }
    return result;
}

int main(){
    long long sum = 0;    //防止溢出
    cin>>sum;
    long long tempSum = sum;    //暂存
    //先要判定位数
    int length = to_string(sum).size();
    long long result = 0;    //把每一位累加上来
    while(sum > 0 && length > 0){
        //取下这一位
       // cout<<length<<endl;
        //cout<<string(length, '1')<<endl;
        stringstream ss;
        //读入
        ss<<string( length, '1');
        long  long weight = 0;
        ss>>weight;
        //int weight = atoi(string( length, '1').c_str());
        //cout<<weight<<endl;
        int digit = sum / weight;
        //cout<<digit<<endl;
        //加上去
        result += (pow(10,  length - 1) *digit);
        //减位数
        length  --;
        sum -= (digit * weight);
    }
    //如果判断有没有这个数呢
    //逆过来算一遍
    if(tempSum != getSum(result)){
        cout<<-1;
    }
    else{
         cout<<result;
    }
    return 0;
}


