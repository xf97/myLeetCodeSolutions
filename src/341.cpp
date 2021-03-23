/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> values;   //存储列表值的数组
    vector<int>::iterator nowIte;   //迭代器

    void dfs(const vector<NestedInteger> &nestedList){
        //深度优先搜索，把是整数的元素压入values
        //vector的遍历保留原顺序
        for(const auto & i : nestedList){
            //已经提供的方法
            if(i.isInteger()){
                //是整数，压入
                values.emplace_back(i.getInteger());
            }
            else{
                //已经提供的方法
                dfs(i.getList());
            }
        }
    }
public:
    //第一次遇见这种类型的题目，有点懵
    //看了下题解，了解了，现在自己实现
    //要善用已经定义好的方法
    //时间击败：90.84%，空间击败：70.16%
    NestedIterator(vector<NestedInteger> &nestedList) {
        //获取整数序列并且初始化迭代器
        dfs(nestedList);
        nowIte = values.begin();
    }
    
    int next() {
        return *nowIte++; //返回数值并前进一位
    }
    
    bool hasNext() {
        return nowIte != values.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
