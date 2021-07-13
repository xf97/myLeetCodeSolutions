//这是最后一个字节的简单题，且做(欺负)且珍惜
//这能是简单题？
//不管什么，冲他，模拟应该就可以了
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
bool checkKeZi(vector<int>  _cards){
    //先检查有没有四个刻子
    //没有的话，直接滚蛋
    set<int> cardKinds(_cards.begin(), _cards.end());
    if(cardKinds.size() != 5){
        return false;
    }
    //cout<<cardKinds.size()<<endl;
    int result = 0;
    for(auto iter = cardKinds.begin(); iter != cardKinds.end(); iter ++){
        int counts =  count(_cards.begin(), _cards.end(), *iter);
        if( counts != 3 && counts != 2){
            return false;
        }
        else{
            continue;
        }
    }
    return true;
}


bool checkShunZi(vector<int>  _cards){
   //排序
    sort(_cards.begin(), _cards.end());
    set<int> cardKinds(_cards.begin(), _cards.end());
    for(auto &  i : cardKinds){
        if(count(_cards.begin(),  _cards.end(), i) > 4){
            return false;
        }
    }
    //顺子数量
    int result = 0;
    //复杂度有点大
    for(int i = 0;  i  <  _cards.size() - 2; i ++){
        //找后续两张牌的下标
        auto _2ndCard =  find(_cards.begin(), _cards.end(), _cards[i] + 1);
        auto _3rdCard =  find(_cards.begin(), _cards.end(), _cards[i] + 2);
        //如果两个都不为空
        if(_2ndCard != _cards.end() && _3rdCard != _cards.end()){
            //那么有顺子
            result ++;
            //置0
            _cards[_2ndCard - _cards.begin()] = 0;
            _cards[_3rdCard - _cards.begin()] = 0;
            _cards[i]  = 0;
        }
        else{
            continue;
        }
    }
    if(result == 4){
        //并且剩余两张非0的牌必须相同
        sort(_cards.begin(), _cards.end());
        return count(_cards.begin(), _cards.end(), 0) == 12 &&  _cards[_cards.size() - 2] == _cards[_cards.size() - 1];
    }
    return false;
}

bool isHuPai(vector<int>   _cards){
    //判断当前牌组是否胡牌
    //是四个刻子吗
    if(checkKeZi(_cards)){
        //cout<<"1&&"<<endl;
        return true;
    }
    //是四个顺子吗
    else if(checkShunZi(_cards)){
        //cout<<"2&&&"<<endl;
        return true;
    }
    //都是垃圾
    return false;
}



int main(){
    vector<int> myCards;    //现有的13张牌
    int temp = 0;
    while(cin>>temp){
        myCards.push_back(temp);
    }
    vector<int>  results;    //结果
    //模拟压入
    for(int i = 1; i < 10; i ++){
        vector<int> tempCards(myCards.begin(), myCards.end());
        tempCards.push_back(i);
        //cout<<i<<endl;
        //判断是否胡牌
        if(isHuPai(tempCards)){
            results.push_back(i);
        }
        else{
            continue;
        }
    }
    //检查能不能因为四个刻子和牌，如果有压入和牌可能，如果没有不压入
    //checkKeZi(myCards, results);
    //检查能不能因为四个顺子和牌
    //checkShunZi(myCards, results);
    if(results.size() == 0){
        results.push_back(0);
    }
    //sort(results.begin(), results.end());
    for(const auto & i : results){
        cout<<i<<" ";
    }
    return  0;
}
*/
        #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isHu(vector<int> nums){//其实是一个dfs的过程
    if (nums.empty())    return true;//递归出口
    //记录与首元素相同的数字的个数，因为数组有序，并且最多出现4次，所以不用遍历所有区间
    int cnt = count(nums.begin(), nums.begin()+4, nums[0]);

    //注意：下面的几个if不能加上else奥，因为每种情况都需要考虑
    //取了雀头之后的size肯定能被3整除（因为除了雀头都是三个一组取的）
    if (nums.size() % 3 != 0 && cnt >= 2){//当前两个元素相等时，尝试以他两作为雀头
        if ( isHu(vector<int>(nums.begin() + 2, nums.end())) )   return true;
    }

    if (cnt >= 3){//尝试取一个刻子（三个相同的数字）
        if ( isHu(vector<int>(nums.begin() + 3, nums.end())) )    return true;
    }

    //首元素以顺子的形式出现
    //先判断首元素+1和+2的元素是否存在，只有同时存在才有可能构成顺子
    if(count(nums.begin(), nums.end(), nums[0]+1) > 0 && count(nums.begin(), nums.end(), nums[0] + 2) > 0){
        //把该顺子从数组中去掉，继续判断剩下的顺子
        vector<int> nums_new(nums.begin() + 1, nums.end());//去掉一个首元素（顺子的第一个）
        nums_new.erase(find(nums_new.begin(), nums_new.end(), nums[0] + 1));//去掉一个首元素+1（顺子的第二个）
        nums_new.erase(find(nums_new.begin(), nums_new.end(), nums[0] + 2));//去掉一个首元素+2（顺子的第三个）
        if (isHu(nums_new)) return true;
    }
    return false;
}

int main(){
    vector<int> nums(13), count(10,  0);//已有的13张牌，以及计数器，记录每张牌出现的次数
    vector<int> res;
    for (int i = 0; i < 13; ++i){
        cin >> nums[i];
        ++count[nums[i]];
    }    
    sort(nums.begin(), nums.end());//先排序
    for (int i = 1; i <= 9; ++i){//遍历下一张可能的牌
        if (count[i] == 4)    continue;//最多就4张，真的不能再多了
        auto it = lower_bound(nums.begin(), nums.end(), i);
        nums.insert(it, i);//插入i

        if(isHu(nums) )     res.push_back(i);   //判断是否ok

        it = lower_bound(nums.begin(), nums.end(), i);
        nums.erase(it);//恢复原始nums数组
    }

    if (res.empty()) cout << 0 << endl;
    else{
        for (const auto &v : res)   cout << v <<" ";
    }
    return 0;
}
