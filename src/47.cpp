class Solution {
    /*
    我的代码一直报错，蒙了
class Solution:
    '''
    是个逐渐减小问题规模的过程，在选定第一位后，就是从后面的n-1位选定在选定一位的过程
    直到所有位都被选定
    '''
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        temp = list()   #暂存数组，当该数组长度与nums(或者valid)相同时，找到一个全排列
        result = list() #结果数组
        sorted(nums)    #由小到大排列
        self.recFind(result, nums, 0, temp)   #逐步缩小范围去查找
        #result = list(set(result))  #去重
        return result
    
    def recFind(self,  _result, _nums, _cur, _nowResult):
        if  _cur == len(_nums):
            _result.append(_nowResult)
        else:
            for index in range(len(_nums)):
                if _nums[index] == -1:
                    continue
                else:
                    _nowResult.append(_nums[index])
                    _nums[index] =  -1
                    self.recFind(_result, _nums, _cur + 1, _nowResult)
                    _nums[index] = _nowResult.pop()
                return 
    */

　　/*

    时间击败:99.30%
    空间击败:85.55%
    */
    vector<int> vis;    //记录每个位置是否使用过的数组

public:
    //基本思想：搜索－回溯
    //采用引用，直接修改参数　
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            //找到一个全排列，压入答案
            ans.emplace_back(perm);     //emplace_back相比于push_back效率更高
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            //否则就尝试每一个未被压入的数据
            //vis[i] 如果为１，表示该数据已经被使用
            //或运算符之后的部分用于跳过重复数字
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            //压入一个可用数字
            perm.emplace_back(nums[i]);
            vis[i] = 1;     //改变使用位
            backtrack(nums, ans, idx + 1, perm);    //下一步递归
            vis[i] = 0; //如果不使用这一位
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;    //结果数组
        vector<int> perm;   //暂存数组
        vis.resize(nums.size());    //有效位初始化
        sort(nums.begin(), nums.end()); //从小到大排列，方便跳过重复数字
        backtrack(nums, ans, 0, perm);  //开始搜索－回溯
        return ans;
    }
};
