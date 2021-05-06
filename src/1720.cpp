class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        //非负整数，e[i-1] = a[i-1] xor a[i]
        //so a[i] = e[i-1] xor a[i-1]
        //输入的数组长度大于等于2
        //从前向后，步步推导
        //不用处理边界情况
        //时间复杂度-On, 空间-On
        //初始化结果
        //十五分钟，一次提交，时间击败-50.21%，空间击败-99.72%
        vector<int> result(encoded.size() + 1, 0);
        result[0] = first;
        //从前向后
        for(int i = 1; i < result.size(); i++){
            result[i] = encoded[i - 1] ^ result[i - 1];
        }
        return result;
    }
};
