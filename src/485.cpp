class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        /*
        time defeat: 59.44%
        space defeat: 71.23%
        */
        //已经有思路，一次遍历，解决问题
        //边界情况
        if(nums.size() == 0){
            return 0;
        }
        //边界情况1
        else if(nums.size() == 1 || nums.size() == 2){
            return count(nums.begin(), nums.end(), 1);
        }
        //普适情况
        else{
            int _1Num = 0;  //连续1的数量
            int temp1Num = 0;   //每次遍历的暂存连续1数量
            //需要下标
            int i = 0;  //下标
            while(i < nums.size()){
                if(nums[i] == 1){
                    temp1Num ++;
                    i++;
                }
                else{
                    //此时连续1出现断档
                    //记录
                    _1Num = max(_1Num, temp1Num);
                    //数据置空
                    temp1Num = 0;
                    i++;
                }
            }
            //以上赋值方式，需要处理i == nums.size() - 1时的数据情况
            _1Num = max(_1Num, temp1Num);
            return _1Num;
        }
    }
};
