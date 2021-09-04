class Solution {
private:
    //vector<int> nums;
    mt19937 gen;    //随机数发生器，用于产生高性能随机数
    uniform_int_distribution<int> dis;  //生成区间内的随机数
    vector<int> pre;    

public:
    Solution(vector<int>& w): gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        //对first_last之间的元素逐个累计求和，结果放在pre中
        //back_inserter是个迭代器，在末尾插入元素
        partial_sum(w.begin(), w.end(), back_inserter(pre));
        //首个想法是构建数组
        //八分钟，一次提交，超时，55/57
        //感觉要数学吧
        //或者啥哈希表啥的
        //题解离大谱！这东西是人做的？你说你那个对，我这个也对呀
        /*
        srand(time(0));
        int length = w.size();
        for(int i = 0; i < length; ++ i){
            int weight = w[i];
            while(weight -- ){
                nums.emplace_back(i);
            }
        }
        */
    }
    
    int pickIndex() {
        /*
        for(auto i = nums.begin(); i < nums.end(); ++ i){
            cout<<(*i)<<" ";
        }
        */
        //return nums[rand() % nums.size()];
        int x = dis(gen);   //这个类似于rand() % nums.size()
        //lower_bound用于找出范围内第一个不大于x的元素
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */