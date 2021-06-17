class MyHashMap {
public:
    /** Initialize your data structure here. */
    //键值都大于等于0
    //五分钟，一次提交，时间击败-8.10%，空间击败-93.50%
    MyHashMap() {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto index =find(keys.begin(), keys.end(), key);
        if(index != keys.end()){
            values[index - keys.begin()] = value;
        }
        else{
            keys.emplace_back(key);
            values.emplace_back(value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto index =find(keys.begin(), keys.end(), key);
        if(index != keys.end()){
            return values[index - keys.begin()];
        }
        else{
           return -1;
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto index =find(keys.begin(), keys.end(), key);
        if(index != keys.end()){
            keys[index - keys.begin()] = -1;
            return;
        }
        else{
           return;
        }
    }

private:
    vector<int> keys;
    vector<int> values;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
