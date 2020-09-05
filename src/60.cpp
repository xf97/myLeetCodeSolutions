class Solution {
public:
    string getPermutation(int n, int k) {
        //思路1：生成所有的排列方式，再从小到大排列，然后输出第n个 -->可能面临空间、时间危险
        //思路2：使用k为步进数量，直接输出第k个排列-->需要搞清楚排列的生成顺序。
        //先采用思路2
        //极端情况
        /*
        标准思路与我的思路类似，都是从前往后逐个确定，都使用剩下(n-1)的阶乘来计算当前元素值
        只是没使用数学方法推导计算公式
        string result = "";
        if( n == 1){
            return "1";
        }
        else{
            int tempK = k;
            int tempN = n;
            while(tempK > getJieCheng(tempN - 1)){
                int tempJieCheng =  getJieCheng(tempN - 1);
                int num = ceil(float(tempK) / tempJieCheng);
                //cout<<num<<endl;
                result += to_string(num);
                tempK -= (floor(tempK / tempJieCheng) * tempJieCheng);
                tempN -= 1;
            }
            cout<<"hahaha";
            return result;    
        }
        */
       static constexpr array factorial {1,1,2,6,24,120,720,5040,40320}; //0-8阶乘值
        vector nums(n, 0);
        iota(begin(nums), end(nums), 1); //iota函数递增赋值
        string ret; //结果字符串
        --k;
        for (int i = n - 1; i != -1; --i) {
            auto it = begin(nums) + k / factorial[i]; //求得该位的值，k除阶乘值加偏移量
            ret += ('0' + *it);
            nums.erase(it); //擦除使用过的值
            k %= factorial[i]; //更新k，对剩下长度的字符串
        }
        return ret;  
    }

    
    /*
    int getJieCheng(int _n){
        unsigned long long factorial = 1;
        for (int i = 1; i <= _n; i++){
            factorial *= i;
        }
        return factorial;
    }*/
};
