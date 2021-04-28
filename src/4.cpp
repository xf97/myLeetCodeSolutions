class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //归并排序，然后寻找中位数
        //不要求原地归并，可以双路归并
        //两个数组已经排序，并且不会两个数组同时为空
        //边界
        //困难题解决，一次提交，十五分钟，时间击败-68.39%，空间击败-36.00%
        //这个题做个简单题合适一些
        if(nums1.size() == 0 && nums2.size() == 0){
            return 0;   //自动转换类型
        }
        vector<int> finalNums(nums1.size() + nums2.size(), 0);  //初始化归并后数组，避免后续连续插入的消耗
        int nums1Point = 0;
        int nums2Point = 0; //两个指针
        int i = 0;  //归入指针
        //归并
        while(nums1Point < nums1.size() && nums2Point < nums2.size()){
            if(nums1[nums1Point] <= nums2[nums2Point]){
                finalNums[i] = nums1[nums1Point];
                nums1Point ++;
            }
            else{
                finalNums[i] = nums2[nums2Point];
                nums2Point ++;
            }
            i ++;
        }
        //把没走完的部分压进来
        if(nums1Point == nums1.size()){
            while(nums2Point < nums2.size()){
                finalNums[i] = nums2[nums2Point];
                nums2Point ++;
                i ++;
            }
        }
        else if(nums2Point == nums2.size()){
            while(nums1Point < nums1.size()){
                finalNums[i] = nums1[nums1Point];
                nums1Point ++;
                i ++;
            }
        }
        //最后取中位数
        if(finalNums.size() % 2 == 0){
            //偶数长度
            return (finalNums[finalNums.size() / 2] + finalNums[(finalNums.size() / 2) - 1]) / 2.0;
        }
        else{
            //奇数长度
            return finalNums[finalNums.size() / 2]; //自动类型转换, int -> double
        }
    }
};
