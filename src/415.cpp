class Solution {
public:
    string addStrings(string num1, string num2) {
        //干翻字节！
        //18年练习过的题，当时在腾讯还要做好久
        //大数问题，只能够用string存储，避免溢出
        //非负整数
        //十分钟，一次提交，18年12ms，21年4ms，还是进步了，而且做得快了很多
        //时间击败-76.89%，空间击败-18.77%
        //string加reverse
        string result = "";
        //补前导0
        if(num1.size() < num2.size()){
            string temp = num1; //深度拷贝
            num1 = num2;
            num2 = temp;
        }
        //num1是长的，补齐num2的长度
        //string重载了+，支持前端插入
        while(num2.size() < num1.size()){
            num2 = '0' + num2;
        }
        //cout<<num1<<" "<<num2<<endl;
        //同等长度了，开始从后向前
        int carry = 0;
        for(int i = num1.size() - 1; i >= 0; -- i){
            //计算当前位
            int digit = (num1[i] - '0') + (num2[i] - '0') + carry;
            carry =0;
            while(digit >= 10){
                digit -= 10;
                carry ++;
            }
            //当前位放到结果中
            //不愿意付出string构造函数的代价
            result.push_back('0' + digit);
        }
        //最后检查是否有最高位进位
        if(carry){
            result.push_back('0' + carry);
        }
        //翻转
        reverse(result.begin(), result.end());
        //结果必然不会存存在多余的前导0
        return result;
    }
};
