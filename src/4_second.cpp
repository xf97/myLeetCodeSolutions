class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //干翻腾讯！
        //虽然是个困难题，但是有个很朴素的想法就是用一个额外空间存储
        int m = nums1.size();
        int n = nums2.size();
        //声明额外数组，两个数组不会都为0
        //五分钟，一次提交，时间击败-87.04%，空间击败-38.39%
        vector<int> temp(m + n);    //时间复杂度Onlogn，空间O(m+n)
        int index = 0;
        //以下其实可以归并排序
        //再一步进阶，能否边查边确定
        for(int i = 0; i < m; ++ i){
            temp[index] = nums1[i];
            index ++;
        }
        for(int i = 0; i < n; ++ i){
            temp[index] = nums2[i];
            index ++;
        }
        //排序
        sort(temp.begin(), temp.end());
        //拿出中位数
        if((m + n) & 0x1){
            //奇数
            int middle = (m + n) >> 1;
            return static_cast<double>(temp[middle]);
        }
        else{
            //偶数
            int middle = (m + n) >> 1;
            double result = double(temp[middle] + temp[middle - 1]) / 2;
            return result;
        }
    }
};
