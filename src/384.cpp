class Solution {
    /*
    很棒，思想完全是对的，被测试用例摆了一道
    两次提交，时间击败-63.20%，空间击败-27.66%
    */
    vector<int> init;
    int length;
public:
    Solution(vector<int>& nums): init(nums), length(nums.size()) {
        //要保存初始状态
        srand(time(0)); //选定随即元
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return init;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //随机取下标，交换
        vector<int> temp(init); //深层拷贝
        for(int i = 0; i < length; ++ i){
            //随机取另外一个下标
            int anotherOne = (rand() % length);
            /*
            while(anotherOne == i){
              anotherOne = (rand() % length);  
            }
            */
            swap(temp[i], temp[anotherOne]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
