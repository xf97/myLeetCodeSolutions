class Solution {
public:
    int add(int a, int b) {
        //看了题解才看懂，很有创意
        //用位运算
        //不理解概念的话确实很难，也算是学到了
        //两次提交，时间击败-100%，空间击败-46.43%
        while(b != 0){
            int carry = static_cast<unsigned int>(a & b) << 1;   //进位是与
            a = a ^ b;  //无进位和是疑惑
            b = carry;
        }
        return a;
    }
};
