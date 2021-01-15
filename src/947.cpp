class Solution {
public:
    //逐步删除，会导致超时，使用官方题解，通过连通性的方法解题
    //深度搜索
    void dfs(int x, vector<vector<int>> &edge, vector<int> &vis) {
        vis[x] = true;  //置该节点为遍历过
        //深度搜索，所有连通分量的vis置位
        for (auto &y : edge[x]) {
            if (!vis[y]) {
                dfs(y, edge, vis);
            }
        }
    }

    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        vector<vector<int>> edge(n);    //边集
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    //同行或同列，存在边，推入边集
                    //第i个点连通到j
                    edge[i].push_back(j);
                }
            }
        }
        vector<int> vis(n); //遍历每个节点，计算与该节点的连通分量，与它连通的所有节点都可删除只剩一个
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {  //没遍历过这个点，构造它的连通分量
                num++;  //连通分量的数量
                dfs(i, edge, vis);  //深度搜索去构造分量
            }
        }
        return n - num; //点数减掉分量数，出结果
    }
    /*
    int removeStones(vector<vector<int>>& stones) {
        //逐步搜索，逐步移除
        //递归方法
        //边界情况
        if(stones.size() <= 1){
            return 0;
        }
        int maxNum = 0; //能够被移除的石子数量
        //拿到一个，判断它是不是可以被移除，然后递归向下
        for(auto i : stones){
            if(sameLine(i, stones)){
                //如果同行或同列，移除它
                vector<vector<int>> temp;
                for(auto j: stones){
                    if(i[0] == j[0] && i[1] == j[1]){
                        continue;
                    }
                    else{
                        temp.push_back(j);
                    }
                }
                maxNum = (removeStones(temp) + 1) > maxNum? (removeStones(temp) + 1) : maxNum;
            }
            else
                continue;
        }
        return maxNum;
    }
    
    //该函数用于判断是否存在同行同列的石头
    bool sameLine(vector<int>& _stone, vector<vector<int>>& _manyStones){
        for(auto i: _manyStones){
            if(i[0] == _stone[0] && i[1] == _stone[1]){
                //同一块石头，跳过
                continue;
            }
            else if((i[0] == _stone[0] && i[1] != _stone[1]) || (i[0] != _stone[0] && i[1] == _stone[1])){
                //同行或同列
                return true;
            }
            else{
                continue;
            }
        }
        return false;
    }
    */
};
