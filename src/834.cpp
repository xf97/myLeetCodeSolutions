/*
困难动态规划-xf再次拉胯
*/
//使用官方题解，但自己打注释
class Solution {
public:
    //ans结果数组, sz本节点的子节点到本节点的距离和(直接子节点), dp以本节点为根的树中的所有节点到本节点的举例之和
    vector<int> ans, sz, dp;
    vector<vector<int>> graph;  //二叉树的图

    //得到所有点的深度和子节点数量
    void dfs(int u, int f) {
        sz[u] = 1;  //到自己的边长度
        dp[u] = 0;
        for (auto& v: graph[u]) {
            if (v == f) {   //不计算父亲节点
                continue;
            }
            dfs(v, u);  //换根
            dp[u] += dp[v] + sz[v]; //更新u节点的值
            sz[u] += sz[v]; //更新sz数组
        }
    }

    //吐槽一句，官方题解的变量命名和注释也太差了
    //代码的可读性很差劲
    //看不懂这一段
    void dfs2(int u, int f) {
        ans[u] = dp[u];
        for (auto& v: graph[u]) {
            if (v == f) {
                continue;
            }
            int pu = dp[u], pv = dp[v];
            int su = sz[u], sv = sz[v];

            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];

            dfs2(v, u);

            dp[u] = pu, dp[v] = pv;
            sz[u] = su, sz[v] = sv;
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        //指定规模并且初始化
        ans.resize(N, 0);
        sz.resize(N, 0);
        dp.resize(N, 0);
        graph.resize(N, {});
        for (auto& edge: edges) {
            //遍历每一条边
            int u = edge[0], v = edge[1];   //u起点 v终点，u也是v的爸爸
            //将连通关系压入图，使用emplace_back能加快速度
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        dfs(0, -1); //开始深度优先遍历 初始值-0根节点 -1根节点不存在的父节点 
        dfs2(0, -1); //开始深度优先遍历 初始值-0根节点 -1根节点不存在的父节点 
        return ans;
    }
};
