class Solution {
public:
    /*
    time defeat: 27.36%
    space defeat: 46.52%
    */
    int findComplement(int num) {
        //用C++再实现一遍，首先还是求出二进制形式
        //手写10进制转二进制
        vector<int> bNum;   //二进制num
        //10 - 2： 除2取余，逆序排列
        int tempNum = 0;
        while(num >= 1){
            tempNum = num % 2;
            bNum.emplace_back(tempNum);
            num /= 2; 
        }
        //逆序
        reverse(bNum.begin(), bNum.end());
        //然后，求补
        vector<int> resultBNum;
        for(auto i : bNum){
            if(i == 1){
                resultBNum.emplace_back(0);
            }
            else{
                resultBNum.emplace_back(1);
            }
        }
        //最后，2进制转回来
        //题目输入正整数
        int resultNum = 0;
        int length = resultBNum.size();
        for(int i = 0; i < length; i++){
            resultNum += (resultBNum[i] * static_cast<int>(pow(2, length - i -1))); 
        }
        return resultNum;
    }
};
