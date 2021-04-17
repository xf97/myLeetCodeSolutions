class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //初步想法，O(n2)
        //超时，51/54，十分钟提交
        //边界情况
        if(nums.empty()){
            return false;
        }
        else{
            //考虑滑动窗口
            //维护一个长度为k的滑动窗口
            //使用有序集合，保持插入的顺序
            //三十分钟，两次提交，时间击败：14.83%，空间击败：5.80%
            set<long> slideWindow;
            //开始维护窗口
            for(int i = 0; i < nums.size(); i++){
                //判断，在左侧的滑动窗口里，有没有值是符合要求的
                //注意参数溢出
                //lower_bound二分查找，返回的是大于等于参数的最小数字
                //如果找到，就满足要求
                //同时要避免是自己本身，已经保证不等于本身
                //并且分段讨论了绝对值
                auto iter = slideWindow.lower_bound((static_cast<long>(nums[i]) - t));
                if (iter != slideWindow.end() && static_cast<long>(*iter) <= (static_cast<long>(nums[i]) + t)) {
                    return true;
                }
                //插入元素
                slideWindow.insert(nums[i]);
                //当窗口超过限制时，删除元素-按值删除
                if(i >= k){
                    //删除第一个元素
                    slideWindow.erase(nums[i - k]);
                    //cout<<(*slideWindow.begin())<<endl;
                }
            }
            return false;
        }
        /*
        else{
            //先找符合值要求的
            //t是值要求，k是位置要求
            for(int i = 0; i < nums.size(); i++){
                //另一个元素在k位置要求内
                int lIndex = ((i - k) >= 0) ? (i - k) : 0;  //左边边界
                int rIndex = ((i + k) < nums.size()) ? (i + k) : (nums.size() - 1); //右边边界
                for(int j = lIndex; j <= rIndex; j ++){
                    if(i == j){
                        //下标不同
                        continue;
                    }
                    else if(abs(static_cast<long>(nums[i]) - static_cast<long>(nums[j])) <= static_cast<long>(t)){
                        return true;
                    }
                    else{
                        continue;
                    }
                }
            }
            return false;
        }
        */
    }
};
