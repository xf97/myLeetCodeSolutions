class Solution {
public:
    void sortColors(vector<int>& nums) {
        //今日玷污中等题，一来想到的方法是快慢指针
        //On次遍历就能够解决问题
        //要求原地排序
        //要处理边界情况
        //题目保证，nums.size() >=  1
        //nice，十五分钟，一次提交，没看题解，时间击败-46.02%，空间击败-75.84%
        int size =  nums.size();
        if(size  ==  1){
            return;
        }
        //声明快慢指针
        //这一部分感觉可以抽出来做一个函数
        int slow = 0;   //慢指针，指向排序好下标的下一个
        int fast = 0;   //快指针，指向当前扫描到的部分
        //一次遍历解决，先处理0的
        while(slow < size && fast < size){
            if(nums[slow] ==  0){
                slow ++;
                fast = slow;
            }
            else if(nums[slow] != 0 && nums[fast] == 0){
                //交换
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
                slow ++;
                fast ++;
            }
            else{
                //nums[slow] != 0 && nums[fast] != 0
                fast ++;
            }
        }
        fast = slow;
        //现在处理1的
        while(slow < size && fast < size){
            if(nums[slow] ==  1){
                slow ++;
                fast =  slow;   //fast不能慢于slow
            }
            else if(nums[slow] != 1 && nums[fast] == 1){
                //交换
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
                slow ++;
                fast ++;
            }
            else{
                //nums[slow] != 1 && nums[fast] != 1
                fast ++;
            }
        }
        //2的就不用处理了，自然有序
        /*
        //查看一下当前状态
        for(auto & i : nums){
            cout<<i<<" ";
        }
        cout<<endl;
        */
        return;
    }
};
