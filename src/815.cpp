class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //困难题，还挺麻烦，有点干不翻蚂蚁金服了
        //暂时饶他一命吧
        //看看题解
        //看了题解，自己实现，BFS层序搜索，一次扩展的公交车一次出完队
        //首先构建 车站-公交车的映射关系
        //车站-哪些公交车
        //自己的版本，44/45，超时
        unordered_map<int, vector<vector<int>>> stationAndBus;
        //初始化
        for(const auto & route : routes){
            for(const auto & station : route){
                stationAndBus[station].emplace_back(route);
            }
        }
        //队列
        queue<int> stations;
        stations.push(source);
        int result = 0;
        while(!stations.empty()){
            //头车站出队
            //把这一批车站全部出队完，然后又加入他们的站台
            for(auto size = stations.size(); size > 0; -- size){
                int top = stations.front();
                stations.pop();
                //判断
                if(top == target){
                    return result;
                }
                //否则换乘
                for(auto & i : stationAndBus[top]){
                    for(const auto & j : i){
                        stations.push(j);   //把换乘的站台推入
                    }
                    i.clear();  //为什么要清空呢，要不又会换乘回来
                }
            }
            result ++;
        }
        /*
        auto query = unordered_map<int, vector<vector<int>*>> {};
        for (auto&& route : routes)
            for (auto e : route)
                query[e].push_back(&route);
        auto q = queue { deque { source } };
        for (auto cnt = 0; !q.empty(); ++cnt) {
            for (auto i = q.size(); i; --i) {
                auto f = q.front();
                q.pop();
                if (f == target) return cnt;
                for (auto&& r : query[f]) {
                    for (auto&& e : *r)
                        q.emplace(e);
                    r -> clear();
                }
            }
        }
        */
        return -1;
    }
};
