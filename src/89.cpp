class Solution {
public:
    vector<int> grayCode(int n) {
        //就喜欢做菜的中等题
        vector<int> result; //结果
        if(n ==  0){
            result.push_back(0);
            return result;
        }
        //不能偷鸡，偷鸡失败
        /*
        //看完题目后，我其实很疑惑，我感觉有种偷鸡方法
        //昨晚看西班牙打意大利，现在人巨困
        for(int i = 0; i < pow(2, n); i ++){
            result.push_back(i);
        }
        */
        //这题有问题呀，没告诉我格雷码如何形成的呀
        //自愧不如，看了题解，如果知道格雷码是如何形成的（比如推导规律），这道题就简单多了
        //时间复杂度O2^n，空间复杂度-On
        //十五分钟，两次提交，时间击败-19.64%, 空间击败-60.67%
        int limit =  1 << n;    //2的幂次记得用移位
        for(int i = 0; i < limit; i++){
            //格雷编码推导公式-i^i/2
            result.push_back(i ^ (i>>1));
        }
        return result;
    }
};
