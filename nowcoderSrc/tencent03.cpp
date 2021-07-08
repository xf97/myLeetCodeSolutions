//腾讯，我来重拳出击了
//a-y不到z
//这不能用模拟推导
//应该是数学题，进制转化的
//看了题解，确实是要提前推导，而不是一位一位加上去
#include <iostream>
#include  <string>
#include <algorithm>
#include  <vector>
#include <cmath>
using  namespace std;

//当首字母固定时，该类一共有
//25^3+25^2+25+1个

int main(){
    string code ="";
    cin>>code;    //编码
    //遍历编码，逐个组合
    long result = 0;    //担心超限
    int  length = code.size();    //编码长度
    vector<int> nums{1, 26, 651,16276};    //static_cast<int>(pow(25,1)), static_cast<int>(pow(25,2)), static_cast<int>(pow(25,3)) };
    //nums.push_back(26);
    /*
    for(int i = 0;  i < length; i++){
        result +=   (code[i] - 'a') *  nums[length - i - 1] ;    
    }
    result += (length - 1);
    */
    //从前向后，逐个作反应
    //数字要从后向前，我终于反应过来了
    switch(length){
        case 4:
            result += (code[3] - 'a') *  nums[0] + 1 ;
        case 3:
            result += (code[2] - 'a') *  nums[1] + 1;
        case 2:
            result += (code[1] - 'a') *  nums[2] + 1;
        case 1:
            result += (code[0] - 'a') * nums[3];
        default:
            break;
    }
    cout<<result;
    return 0;
}
