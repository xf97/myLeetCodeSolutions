class KthLargest {
    //兄弟来，维护一个堆
    //小顶堆

    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;
public:
    KthLargest(int k, vector<int>& nums) {
        //填充堆
        //时间复杂度Onlogk，空间Ok，分析正确 
        //四次提交，有些细节没处理好，时间击败-78.17%，空间-67.87%
        limit = k;
        for(const int & num: nums){
            add(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > limit){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
