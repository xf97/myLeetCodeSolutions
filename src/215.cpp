class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //我要对字节报仇
        //堆排序，优先队列
        //不用处理边界情况
        //十分钟，一次提交，时间击败-98.64%，空间击败-20.14%
        priority_queue<int,  vector<int>,  greater<int>> pq; //小顶堆
        int index = 0;  //遍历下标
        int length = nums.size();   //长度
        //先塞元素进去
        //k一定小于nums.size()，题目保证
        while(pq.size() < k && index < length){
            pq.push(nums[index]);
            index ++;
        }
        //然后，进去的每一个都要和最小的值比较，只有比最小值大，你才可以进去
        while(index < length){
            if(nums[index] < pq.top()){
                index ++;
            }
            else{
                //大于等于了
                pq.pop();
                pq.push(nums[index]);
                index ++;
            }
        }
        return pq.top();
    }
};
