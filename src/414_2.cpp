class Solution {
    //time defeat: 51.54%
    //space defeat: 19.18%
public:
    int thirdMax(vector<int>& nums) {
        //基本思想: 去重，排序取第三
        //第二个想法：因为要去重，所以用有序集合
        //题目保证nums不为空
            set<int> pq;
            for(int num : nums){
                pq.insert(num);
                if(pq.size() > 3){
                    pq.erase(pq.begin());
                }
            }
            return (pq.size()  == 3) ? *pq.begin() : *pq.rbegin();
        /*
        //先去重，利用set
        set<int> tempSet(nums.begin(), nums.end());
        nums.assign(tempSet.begin(), tempSet.end());
        sort(nums.begin(), nums.end()); //升序排序
        //边际情况
        if(nums.size() <= 2){
            return nums[nums.size()-1]; //不存在第三大的数，返回最大的
        }
        //普适情况
        return nums[nums.size()-3];
        */
    }
};
