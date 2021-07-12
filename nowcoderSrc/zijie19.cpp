//这说是道简单题怎么通过率那么低
//我看懂了，从n个数字里，选择3个数字，这三个数字的最大差值不超过d
//返回符合条件的集合数量
//等下午来做
//不该是简单题
//十分钟，方法可行，但是超时

#include <iostream>
#include <vector>
using namespace std;

const int MOLD = 99997867;

int main(){
    int n = 0;    //字节大街长度
    cin>>n;
    int d = 0;    //最远距离
    cin>>d;
    //int maxDis  = -1;    //现在的最大距离
    int temp = 0;
    vector<int> byteDanceStreet;    //字节大街数组
    while(cin>>temp){
        byteDanceStreet.push_back(temp);
    }
    long long result =  0;    //结果
    //三重循环，选定每一个人的位置
    //看了题解，题目里的动态规划是唬人的
    //可以简化这个循环
    for(int left = 0; left < byteDanceStreet.size() - 2; left ++){
        int right = left + 2;
        while(right < byteDanceStreet.size() && (byteDanceStreet[right] -byteDanceStreet[left] <= d)){
            //满足要求的情况下，right一直向右前进
            right ++;
        }
        //直到两人距离太远了，那么这时候统计有几个方案能用
        //先检查是否是能满足三个
        if(right - left -1 >=2){
            temp = right - left - 1;    //窗口长度
            //现在固定了left一个人，从另外的地方取出其他两个人的位置
            //Cn2=n!/2!*(n-2)! = n*(n-1)//2
            result += (temp * (temp - 1) / 2);
            result %= MOLD;
        }
        //left += 1;
    }
    /*
    for(int i = 0; i < byteDanceStreet.size() - 2; i ++){
        for(int j = i + 1; j < byteDanceStreet.size() - 1; j ++){
            for(int k = j + 1; k <  byteDanceStreet.size(); k ++){
                //检查最远距离
                if(byteDanceStreet[k] - byteDanceStreet[i] <= d){
                    result ++;
                    result %=MOLD;
                }
            }
        }
    }
    */
    cout<<(result % MOLD);
    return 0;
}
