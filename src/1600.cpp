class ThroneInheritance {
    //基本上看懂了，有点困难，题目太难理解了，吐了
    //名字互不相同
    //第一次提交，超时，48/49
    //学到了，集合的count比vector的find快
    //四次提交，三十五分钟，时间击败-85.82%，空间击败-98.51%
public:
    ThroneInheritance(string kingName): king(move(kingName)) {
        //使用成员初值列 
        //curOrder.emplace_back(kingName);
    }
    
    void birth(string parentName, string childName) {
        //第一次使用move函数，减少左值复制拷贝
        parentAndKids[move(parentName)].emplace_back(move(childName));
    }
    
    void death(string name) {
        deathName.insert(move(name));
    }
    
    vector<string> getInheritanceOrder() {
        //我终于理解了，今日份阅读理解，多叉树的前序遍历
        //继承顺序就是，只要这个人不死，你就给我拿进来
        vector<string> result;
        preOrder(king, result); //多叉树前序遍历
        return result;
    }
private:
    string king;
    //vector<string> deathName;   //用vector可能导致超时 
    unordered_set<string> deathName;
    unordered_map<string,  vector<string>> parentAndKids;
    //递归前序遍历函数
    void  preOrder(const string & _name, vector<string> & _order){
        //死了没 ，死了滚蛋
        if(!deathName.count(_name)){
            //不死就能进继承顺序
            _order.emplace_back(move(_name));
        }
        //然后，你所有的孩子都加进来
        if(parentAndKids.count(_name)){
            //有孩子的话
            for(const auto & i : parentAndKids[_name]){
                //前序遍历 
                preOrder(i, _order);
            }
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
