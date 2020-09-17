struct UnionFind {
    /*
    绝大部分时候的困难题都是一头雾水
    官方题解
    我个人理解后标注注释
　　时间击败: 60%
    空间击败: 50%
    */
    vector <int> ancestor;  //记录每个节点的祖先节点

    UnionFind(int n) {
        ancestor.resize(n); //初始化祖先数组
        for (int i = 0; i < n; ++i) {   //初始化复制
            ancestor[i] = i;
        }
    }

    int find(int index) {
        //如果index等于自己的初始值
        //那么返回index
        //否则就一路向上返回他的祖先值
        return index == ancestor[index] ? index : ancestor[index] = find(ancestor[index]);
    }

    void merge(int u, int v) {
        //节点u的祖先就指向v的祖先
        ancestor[find(u)] = find(v);
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int nodesCount = edges.size();  //正常时：边 = 节点－１
        UnionFind uf = UnionFind(nodesCount + 1);    //初始化并查集
        auto parent = vector<int>(nodesCount + 1);  //初始化父节点集合
        for (int i = 1; i <= nodesCount; ++i) { //初始化父亲节点数组
            parent[i] = i;
        }
        int conflict = -1;  //冲突标志位
        int cycle = -1; //环路标志位
        for (int i = 0; i < nodesCount; ++i) {
            auto edge = edges[i];
            //node 1是父节点，node 2是子节点
            int node1 = edge[0], node2 = edge[1];
            if (parent[node2] != node2) {
                //如果子节点的父节点已经被赋值为另一个值，则此处出现了一个子节点拥有两个父节点的情况
                //冲突出现，记录冲突
                conflict = i;
            } else {
                //赋值node2的父亲节点
                parent[node2] = node1;
                //如果此时就出现了你爸的祖先和你的祖先是同一个，那么出现环路
                //即，在知道自己的爸爸前已经知道了自己的祖先
                if (uf.find(node1) == uf.find(node2)) {
                    cycle = i;  //每次出现都会被覆盖，最后该值保留为最后一个节点
                } else {
                    //否则，把自己的祖先跟父节点的祖先合并
                    uf.merge(node1, node2);
                }
            }
        }
        if (conflict < 0) {
            //如果没有出现冲突，那么
            auto redundant = vector<int> {edges[cycle][0], edges[cycle][1]};    //返回节点
            return redundant;
        } else {
            //出现冲突
            auto conflictEdge = edges[conflict];
            if (cycle >= 0) {
                //如果此时也出现环路
                //那么冲突边即是parent[v],v
                auto redundant = vector<int> {parent[conflictEdge[1]], conflictEdge[1]};
                return redundant;
            } else {
                //否则返回冲突
                auto redundant = vector<int> {conflictEdge[0], conflictEdge[1]};
                return redundant;
            }
        }
    }
};

