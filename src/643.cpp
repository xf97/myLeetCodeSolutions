class Solution {
public:
    //能不能一次遍历就解决问题?
    /*
    time defeat: 94.71%
    space defeat: 16.68%
    */
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int maxSum = INT_MIN;   //哪一段子数组的总和大，哪一段的平均数就大
        //边界情况
        if(nums.size() == k){
            return double(accumulate(nums.begin(), nums.end(), 0)) / k; 
        }
        //求初始的sum
        sum = maxSum = accumulate(nums.begin(), nums.begin() + k, 0);
        //cout<<sum<<" "<<maxSum;
        //开始滑动
        for(int i = k; i <= nums.size() - 1; i++){
            sum = sum - nums[i - k] + nums[i];  //减掉开头那个的，要最后这个新进来的
            maxSum = max(maxSum, sum); 
        }
        return static_cast<double>(maxSum) / k;
    }
};