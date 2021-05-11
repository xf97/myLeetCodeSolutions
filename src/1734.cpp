class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        //e[i] = p[i] ^ p[i+1]->e[i] ^ p[i] = (0 ^ p[i+1])
        //因为p[i+1]是正整数，所以 e[i] ^ p[i] = p[i+1]
        //看了题解，果然是到数学题
        //问题的关键在于得出p[0]
        //十分钟，一次提交（看了题解），时间击败-24.30%，空间击败-88.84%
        int total = 0;
        for(int i = 1; i <= (encoded.size() + 1); i++){
            total ^= i;
        }
        int oddNum = 0;
        for(int i = 1; i < encoded.size(); i += 2){
            oddNum ^= encoded[i];
        }
        vector<int> result(encoded.size() + 1, 0); //结果数组
        result[0] = (total ^ oddNum);
        //然后推到后续的元素就可以了
        for(int i = 1; i < result.size(); i++){
            result[i] = (result[i - 1] ^ encoded[i - 1]);
        }
        return result;
    }
};
