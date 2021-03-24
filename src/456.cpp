class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //现在有了挑战中等题的信息
        //先考虑边界情况，万一没有三个元素呢
        int length = nums.size();
        if(length <= 2){
            return false;
        }
        else{
            //然后再来考虑基本情况
            //最简单的方法就是遍历，考虑一个遍历的情况
            //遍历无法解决时间限制，通过率89/101
            /*
            for(int i = 0; i < nums.size() - 2; i++){
                //记录这个数字
                int _1stNum = nums[i];
                //进入后续序列找逆序对
                for(int j = i + 1; j < nums.size() - 1; j++){
                    if(nums[j] > _1stNum){
                        for(int z = j + 1; z < nums.size(); z ++){
                            if(nums[z] > _1stNum && nums[z] < nums[j]){
                                return true;
                            }
                            else{
                                continue;
                            }
                        }
                    }
                    else{
                        continue;
                    }
                }
            }
            */
            //看了题解，同时维护1和2
            //时间击败25%，空间击败：5%
            int left_min = nums[0];
            //使用Multiset而不使用set的原因是会移除了一个重复元素
            multiset<int> right_all;    //右侧所有元素，使用multiset会默认从小到大排序
            //填充右侧元素
            for(int i = 2; i < length; i++){
                right_all.insert(nums[i]);
            }
            //然后，开始找3
            for(int i = 1; i < length - 1; i++){
                if(left_min < nums[i]){
                    //1成立
                    //看2
                    auto it = right_all.upper_bound(left_min);  //在右侧要能有大于1但是小于3的数字
                    if(it != right_all.end() && *it < nums[i]){
                        //找到
                        return true;
                    }
                }
                //否则，更新
                left_min = left_min < nums[i] ? left_min : nums[i]; //更新1
                right_all.erase(right_all.find(nums[i + 1]));   //去掉即将成为3的2
            }
            return false;
        }
    }
};
