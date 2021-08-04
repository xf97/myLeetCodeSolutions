class Solution {
private:
    unordered_map<int, vector<string>> ans; 
    unordered_set<string> wordSet;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //干翻蚂蚁金服
        //困难题，感觉有点难
        //探索回溯加滑动窗口？
        //果断题解
        //果断是记忆化搜索，不会，看看能不能自己实现吧
        //果然，我还是CV了
        //感觉会了，记忆化搜索是存储以前的遍历结果顺便递归加回溯
        //自己实现！
        //初始化字符集，使用集合的话避免每次find的消耗
        //自己实现了，两次提交，时间击败-100%，空间击败-61.65%
        wordSet = unordered_set(wordDict.begin(), wordDict.end());  //相当于哈希表(string, bool)
        //开始记忆化搜索
        backtrack(s, 0);    //传入字符串和起始搜索位置
        return ans[0];
    }

    void backtrack(const string & s, int index){
        if(!ans.count(index)){
            //没有搜索过这个下标
            //边界条件
            if(index == s.size()){
                //推入
                ans[index] = {""};
                return;
            }
            ans[index] = {};    //花括号初始化，开始逐步试探
            //向后试探
            for(int i = index + 1; i <= s.size(); ++ i){
                //截取出字符串
                string substr = s.substr(index, i - index);
                //这个字符串在字符集吗
                if(wordSet.count(substr)){
                    //在，接着向下探索
                    backtrack(s, i);
                    //把这个词推入ans[index]中
                    for(const string & str : ans[i]){
                        ans[index].emplace_back(str.empty()? substr : substr + " " + str); //保持拼接顺序
                    }
                }
            }
        }
    }
        /*
        wordSet = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0];  //返回从0开始的拼接
    }

    void backtrack(const string& s, int index) {
        //index表示，从这个下标开始，能够拼接出的句子列表
        if (!ans.count(index)) {
            //如果没有探索过这个位置
            if (index == s.size()) {
                ans[index] = {""};  //已经搜索到末尾了
                return;
            }
            ans[index] = {};
            for (int i = index + 1; i <= s.size(); ++i) {
                string word = s.substr(index, i - index);   //一样的，逐步拼接
                if (wordSet.count(word)) {
                    //有这个词
                    backtrack(s, i);    //接着向下探索
                    for (const string& succ: ans[i]) {
                        //把新词推入字符串
                        ans[index].push_back(succ.empty() ? word : word + " " + succ);
                    }
                }
            }
        }
        */
};
