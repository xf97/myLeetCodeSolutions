class Solution {
//time defeat: 5.48%
//space defeat: 90.14%
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        //看题目，每个人都去找自己的自己能做最能赚钱的部分
        int maxProfit = 0;  //最大收益
        //要对工人进行排序
        sort(worker.begin(), worker.end());
        //然后，记录难度和工资的关联关系
        vector<pair<int, int>> diffAndPro;
        for(int i = 0; i < profit.size(); i++){
            diffAndPro.emplace_back(make_pair(difficulty[i], profit[i]));
        }
        //对工资进行排序，由高到底
        sort(diffAndPro.begin(), diffAndPro.end(),  [](const pair<int, int> &x, const pair<int, int> &y) -> bool {return x.second > y.second;});
        //然后开始遍历
        for(int i = 0; i < worker.size(); i++){
            int ability = worker[i];
            for(int j = 0; j < diffAndPro.size(); j++){
                //从前向后，前面的是工资高的，碰到就可以加入
                if(ability >= diffAndPro[j].first){
                    maxProfit += diffAndPro[j].second;
                    break;
                }
                else{
                    continue;
                }
            }
        }
        return maxProfit;
    }
};
