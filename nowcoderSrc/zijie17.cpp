//没时间了，还是整个水仙花数适合我
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isShuiXianHua(int num){
    //100-999，不会溢出
    vector<int> digits(3,  0);
    int tempNum = num;
    int weight = 100;
    int index = 0;
    while(num > 0){
        int digit = num / weight;
        digits[index] = digit;
        index ++;
        num -= (weight *digit);
        weight /= 10;
    }
    //cout<<digits[0]<<"  "<<digits[1]<<" "<<digits[2]<<endl;
    return (pow(digits[0], 3) + pow(digits[1],3) + pow(digits[2], 3)) == tempNum;
}

int main(){
    vector<int> nums;
    int temp = 0;
    while(cin>>temp){
        nums.push_back(temp);
    }
    //开始检测
    for(int i = 0; i < nums.size(); i += 2){
        //cout<<nums[i]<<endl;
        int low =  nums[i];
        int high = nums[i+1];
        //cout<<low<<"*"<<high<<endl;
        vector<int> aResult;
        for(int j = low; j <= high; j ++){
            if(isShuiXianHua(j)){
                aResult.push_back(j);
            }
            else{
                continue;
            }
        }
        if(aResult.size()){
                for(int i = 0; i < aResult.size(); i ++){
                    if(i != aResult.size() - 1){
                        cout<<aResult[i]<<"  ";
                    }
                    else{
                        cout<<aResult[i];
                    }
                }
        }
        else{
            cout<<"no";
        }
        cout<<endl;
    }
    //cout<<isShuiXianHua(370)<<endl;
    return 0;
}
