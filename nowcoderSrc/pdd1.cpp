/*
终于不是场景题了
#干翻拼多多
#难点是时间复杂度On，空间O1
#不能排序
#三个数的最大乘积
*/
/*
    #三个数的最大乘积就是以下两种情况的最大值
    #三个最大正数的乘积
    #两个最小负数和一个最大正数的乘积
    #空间O1就离谱
    #我想用一个3个元素的优先队列的小顶堆和2个元素的大顶堆的优先队列
    #插入复杂度Ologn
*/    

//两次提交，二十五分钟
//时间击败—88%，空间击败-86%
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>    //使用优先队列

using namespace std;

int main(){
    //时间复杂度On，使用常数空间
    int length; //数字长度
    cin>>length;
    vector<long> nums(length);
    long temp = 0;
    int index = 0;
    while(cin>>temp){
        nums[index++] = temp;
    }   
    //边界处理
    if(length <= 3){
        long result = 1;
        for(const long & i : nums){
            result *= i;
        }
        cout<<result;
        return 0;
    }
    //定义优先队列
    //大根堆装最小的，小根堆装最大的
    priority_queue<long> minNums;    //默认大根堆
    priority_queue<long, vector<long>, greater<long>> maxNums;    //小根堆
    for(const long & i : nums){
        if(minNums.size() < 2){
            minNums.push(i);
        }
        else{
            //跟堆顶比较
            int temp = minNums.top();
            if(i < temp){
                minNums.pop();
                minNums.push(i);
            }
        }
        
        if(maxNums.size() < 3){
            maxNums.push(i);
        }
        else{
            int temp = maxNums.top();
            if(i > temp){
                maxNums.pop();
                maxNums.push(i);
            }
        }
    }
    //现在拿到想要的数字
    long minNum1 = minNums.top();
    minNums.pop();
    long minNum2 = minNums.top();
    minNums.pop();
    long maxNum1 = maxNums.top();
    maxNums.pop();
    long maxNum2 = maxNums.top();
    maxNums.pop();
    long maxNum3 = maxNums.top();
    maxNums.pop();
    //cout<<minNum1<<" "<<minNum2<<" "<<maxNum1<<" "<<maxNum2<<" "<<maxNum3<<endl;
    //计算结果
    long result = (minNum1 * minNum2 * maxNum3);
    //cout<<result<<"***"<<endl;
    //会用到重复元素吗，不会，只要nums长度大于三
    result = (result > (maxNum1 * maxNum2 * maxNum3)) ? result : (maxNum1 * maxNum2 * maxNum3);
    cout<<result;
    return 0;
}
