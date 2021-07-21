class RandomizedCollection {
private:
    //第一次做困难的数据结构设计题
    //干翻字节！希望南京加油，让我可以出去玩
    //因为疫情这个事，精神都有一点提不起来
    //加油呀，干翻字节
    //看了题解知道咋做的，时间击败-12.96%，空间击败-6.31%
    //其实也不算难，敢于设计就好了
    //set基于红黑树实现，自动排序
    //unordered_set基于哈希表实现，消耗内存小，插入和查找都是常熟级别，但是不排序
    vector<int> nums;   //存储
    unordered_map<int, unordered_set<int>> idx; //记录数字和nums下标的字典
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);    //推入元素
        //unordered_set用insert推入
        idx[val].insert(nums.size() - 1);
        //只有原本不在集合里的元素插入才返回true
        return idx[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        //将要被删除的元素与末尾元素交换，然后删除
        if(idx.find(val) == idx.end()){
            //不存在这个元素
            return false;
        }
        //获取被删除元素下标
        int index = *(idx[val].begin());
        nums[index] = nums.back();  //覆盖元素
        //删除下标
        idx[val].erase(index);
        idx[nums[index]].erase(nums.size() - 1);
        //插入新元素
        if(index < nums.size() - 1){
            idx[nums[index]].insert(index);
        }
        if(idx[val].size() == 0){
            idx.erase(val);
        }
        //弹出这个元素
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        //与元素数量呈线性相关，直接随机返回就行了
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
