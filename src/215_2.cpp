class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //准备微软的题，干翻微软！
        //用堆
        //允许重复元素进堆
        //十分钟，一次提交，时间击败-80.57%，空间击败-10.05%
        priority_queue<int, vector<int>, greater<int>> pq;  //最小堆，找最大值
        //k小于等于数组size
        int length = nums.size();
        int index = 0;
        while(index < k){
            //先填充k个
            pq.push(nums[index ++]);
        }
        //然后再继续填充，你比我最小的都大，那你进去他出来
        //允许重复
        while(index < length){
            if(nums[index] >= pq.top()){
                pq.pop();
                pq.push(nums[index]);
            }
            index ++;
        }
        return pq.top();
    }
};
