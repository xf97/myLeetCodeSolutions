class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        //扫描，On2
        //无需边界检查
        //六分钟，一次提交，时间击败-5.69%，空间击败-89.93%
        vector<pair<int, string>> restAndIndex;
        for(int i = 0; i < list1.size(); i ++){
            for(int j = 0; j < list2.size(); j ++){
                if(list1[i] == list2[j]){
                    //没有重复元素
                    restAndIndex.emplace_back(make_pair(i + j, list1[i]));
                }
                else{
                    continue;
                }
            }
        }
        //排序
        //答案总是存在一个
        sort(restAndIndex.begin(), restAndIndex.end()); //按元素1升序排列
        //返回结果
        vector<string> result;
        int minIndexSum = restAndIndex[0].first;
        result.emplace_back(restAndIndex[0].second);
        for(int i = 1; i < restAndIndex.size(); i ++){
            if(restAndIndex[i].first != minIndexSum){
                break;
            }
            else{
                result.emplace_back(restAndIndex[i].second);
            }
        }
        return result;
    }
};
