class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //num1是num2的子集，所以每个元素都能在num2中找到
        //不含重复元素，所以num1中的元素在num2中有且只有一个下标(利用api可以快速获得)
        //不能打乱（重排）num2中元素的顺序
        //基础的解法：复杂度在O(n2)
        //time defeat: 71.71%, space defeat: 99.22%
        vector<int> result; //结果数组
        int num2Len = nums2.size(); 
        int index = 0;
        for(const auto & i : nums1){
            //获得i在nums2中的位置（一定找得到）
            index = find(nums2.begin(), nums2.end(), i) - nums2.begin();  
            index ++;
            while(index < num2Len){
                if(nums2[index] > i){
                    //找到比i大的值
                    result.emplace_back(nums2[index]);
                    break;
                }
                else{
                    index ++;
                }
            }
            if(index == num2Len){
                result.emplace_back(-1);
            }
        }
        return result;
    }
};
