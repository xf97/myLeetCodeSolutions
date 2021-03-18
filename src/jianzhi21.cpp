class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        //刚刚做困难题做的我气，做个简单泄愤
        //空数组，只有一个元素的数组
        if(nums.size() == 0 || nums.size() == 1){
            return nums;
        }
        else{
            //双指针，一个从前往后，一个从后往前
            //当前指针指向偶数，后指针指向奇数时交换数字
            //时间击败：44.14%,空间击败：46.33%
            //谨记-比较运算符的优先级高于位运算符
            int pPre = 0;
            int pLast = nums.size() - 1;
            while(pPre <= pLast){
                //移动，让前指针去找偶数
                while(pPre <= pLast && (nums[pPre] & 0x1) != 0){
                    pPre ++;    //停下时指向偶数
                }
                while(pPre <= pLast && (nums[pLast] & 0x1) == 0){
                    pLast --;
                }
                //cout<<pPre<<" "<<nums[pPre]<<" "<<pLast<<" "<<nums[pLast]<<endl;
                //停下时，交换
                if(pPre <= pLast){
                    //int的构造和赋值的开销区别不大，因此可以在内部声明
                    int temp = nums[pPre];
                    nums[pPre] = nums[pLast];
                    nums[pLast] = temp;
                }
            }
            return nums;
        }
    }
};
