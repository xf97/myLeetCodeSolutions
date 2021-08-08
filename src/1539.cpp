class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //干翻蚂蚁金服
        //仔细看，二分也不是个好办法
        //哈希表，就不用On2.
        //而是On的时间和空间
        //五分钟，一次提交
        //时间击败-87.70%，空间击败-8.47%
        unordered_set<int> nums;
        int maxNum = 0;
        for(const int & i : arr){
            nums.insert(i);
            maxNum = i;
        }
        //然后从头遍历
        int count = 0;
        int num = 1;
        //现在数组内遍历
        while(num <= maxNum){
            if(nums.count(num)){
                //有这个数
                num ++;
            }
            else{
                //缺失这个数
                //cout<<num<<" "<<count<<endl;
                 count ++;
                 if(count == k){
                     return num;
                 }
                 num ++;
            }
        }
        //遍历完整个数组都不够，那么就找外围
        num --;
        while(count < k){
            num ++;
            count ++;
        }
        return num;
    }
};
