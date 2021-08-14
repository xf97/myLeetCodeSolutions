class Solution {
private:
    void reFind(vector<int> & nums, int target, int index, int & result){
        //递归边界
        if(index == nums.size() && target == 0){
            result ++;
            return;
        }
        else if(index == nums.size()){
            //不太行
            return;
        }
        else{
            //先取负
            nums[index] *= -1;
            reFind(nums, target + nums[index], index + 1, result);
            //回溯
            nums[index] *= -1;
            //再取正
            reFind(nums, target + nums[index], index + 1, result);
            return;
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //干翻腾讯CSIG!
        //探索加回溯，即使同种符号数量相同，只要位置不同，就是不同表达式
        //深度搜索，不会重复
        //靠，深搜方法应该是没问题的，超时了，103/138
        //优化了一下就没问题了，十分钟，两次提交
        //时间击败-5.11%，空间击败-90.65%
        //莫非是动态规划
        int result = 0;
        int index = 0;  //目前到哪一个下标
        reFind(nums, target, index, result);
        return result;
    }
};
