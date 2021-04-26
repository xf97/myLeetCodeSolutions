class Solution {
public:
    int fib(int n) {
        //简单方法，用递归做
        //题目保证输入n>=0
        //两分钟，一次提交，时间击败-20.88%，空间击败-80.89%
        /*
        if(n <= 1){
            return n;
        }
        else{
            return fib(n - 1) + fib(n - 2);
        }
        */
        //再用动态规划做一个
        //也就是循环
        //五分钟，一次通过，时间击败-100%，空间击败-7%
        if(n <= 1){
            return n;
        }
        else{
            vector<int> fibArray(n + 1, 0); //初始化数组，(n+1)个值为0的元素
            fibArray[0] = 0;
            fibArray[1] = 1;    //初始化头两项
            for(int i = 2; i <= n; i ++){
                fibArray[i] = fibArray[i - 1] + fibArray[i - 2]; 
                //cout<<i<<" "<<fibArray[i]<<endl;
            }
            return fibArray[n];
        }
    }
};
