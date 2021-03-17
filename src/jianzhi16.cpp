class Solution {
public:
    double myPow(double x, int n) {
        //要考虑三种测试情况
        //功能正常的测试，当测试用例处于输入域边界时的情况，还有错误的输入情况
        //要考虑指数为负数的情况
        //对于异常输入返回-1.0
        //299/304个，得，还得用位运算提升速度
        //递归加位运算后，301/304的通过率，这个题用书上的方法做不出来，递归超限
        //指数给的太大了
        //过了！指数超限了，所以转换后溢出了，提前用long变量保存就好了
        /*
        时间击败：100%
        空间击败：41.16%
        */
        if(x == 0.0 && n == 0){
            //浮点数等于，可能由于精度原因导致不能准确判断
            //本来想用equal去判断x和0.0的相等关系，但是奈何leetcode不支持
            return -1.0;    //0的0次幂，数学上无定义
        }
        else if(n == 0){
            //任何数的0次幂都是1
            return 1.0;
        }
        else if(x == 1.0 || n == 1){
            return x;
        }
        else{
            //标准情况
            //要提防指数是负数的情况
            bool isNegative = false;
            long tempN = n;
            if(tempN < 0){
                isNegative = true;
            }
            unsigned long absN = abs(tempN); //先弄成正整数的
            double result = powWithNonNegative(x, absN);
            //现在再来处理指数为负的情况
            if(isNegative){
                result = 1 / result;
            }
            return result;
        }
    }

        double powWithNonNegative(const double _base, long _exp){
            //利用x**n = x ** (n/2) * x ** (n/2)来递归
            if(_exp == 0){
                return 1.0;
            }
            if(_exp == 1 || _base == 1.0){
                return _base;
            }
            double result = powWithNonNegative(_base, _exp >> 1);   //右移一位相当于/2
            result *= result;
            //如果n是奇数，那么要把/2损失的一次补上
            if(_exp & 0x1){
                result *= _base;
            }
            return result;
        }
};
