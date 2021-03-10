class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //num1是num2的子集，所以每个元素都能在num2中找到
        //不含重复元素，所以num1中的元素在num2中有且只有一个下标(利用api可以快速获得)
        //不能打乱（重排）num2中元素的顺序
        //基础的解法：复杂度在O(n2)
        //time defeat: 71.71%, space defeat: 99.22%
        /*
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
        */
        //自己打题解，用栈和字典
        //只用在nums2中先构建一个"下一个更大元素"的字典映射
        //96.05%, 39.44%
        stack<int> increStack;
        map<int, int> greaterMap;   //键是该元素，值是下一个比他大的值
        int temp = 0;
        for(const auto & i : nums2){
            if(! increStack.empty() && i > increStack.top()){
                //当前元素大于栈顶元素
                while(! increStack.empty() && i > increStack.top()){
                    temp = increStack.top();
                    greaterMap[temp] = i;
                    increStack.pop();
                }
                //置空后，将当前元素压入
                increStack.push(i);
            }
            else{
                increStack.push(i);
            }
        }
        //遍历完后，剩余元素的值全是-1
        while(! increStack.empty()){
            temp = increStack.top();
            greaterMap[temp] = -1;
            increStack.pop();
        }
        //然后取值
        vector<int> result; //结果数组
        for(const auto & i: nums1){
            result.emplace_back(greaterMap[i]);
        }
        return result;
    }
};
