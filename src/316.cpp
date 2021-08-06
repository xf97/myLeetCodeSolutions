class Solution {
public:
    string removeDuplicateLetters(string s) {
        //干翻蚂蚁金服！
        //看了题解才会做，单调栈加贪心
        //二十五分钟
        vector<int> vis(26), nums(26);  //vis栈中是否有这个字符了，nums代表重复
        //初始化nums
        for(char ch : s){
            nums[ch - 'a'] ++;
        }
        
        string result;  //result可以充当栈，pop_back
        //对每个元素
        for(char ch : s){
            if(!vis[ch - 'a']){
                //如果栈没有这个元素
                //单调出栈，弹出字典序大的
                while(!result.empty() && result.back() > ch){
                    //查看后面还有几个ch可以用
                    if(nums[result.back() - 'a'] > 0){
                        //还有，让它滚
                        vis[result.back() - 'a'] = 0;
                        result.pop_back();
                    }
                    else{
                        break;
                    }
                }
                //压入这个元素
                vis[ch - 'a'] = 1;
                result.push_back(ch);
            }
            //有的话就不考虑
            nums[ch - 'a'] --;    
        }
        return result;
    }
};
