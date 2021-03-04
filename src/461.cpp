class Solution {
public:
    /*
    time defeat: 100%
    space defeat: 64.4%
    */
    int hammingDistance(int x, int y) {
        //然后用C++搞一遍
        //想通了，按位异或
        int bResult = x ^ y;
        //bitset长度设定为32的原因是x, y最大为2^31次方
        return bitset<32>(bResult).count();
    }
};
