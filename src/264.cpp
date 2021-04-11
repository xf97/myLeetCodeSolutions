class Solution {
public:
    int nthUglyNumber(int n) {
        //我又来玷污中等题了
        //先用简单的方法，十分钟完成，超出时间限制，500/596
        //难的方法，三十分钟完成，时间击败：7.4%，空间击败：5.01%
        //1<=n<=1690
        if(n == 1){
            return 1;
        }
        else{
            //要用优先队列，以确定当前最小的丑数
            int count = 0;  //计数器
            set<long> uglyNumber; //用于判断是否优先队列中已经存在该元素
            //最小堆
            priority_queue<long, vector<long>, greater<long>> uglyNumberPQueue;
            //压入初值
            uglyNumber.insert(1);
            uglyNumberPQueue.push(1);
            long minUglyNum = 0;    //返回值
            //获取n个丑数，退出循环时，即时当时需要的数字
            while(count < n){
                //获取当前最小丑数
                minUglyNum = uglyNumberPQueue.top();
                count ++;
                //将元素压入，set避免重复
                //压入2的
                long temp = minUglyNum * 2;
                if(uglyNumber.find(temp) == uglyNumber.end()){
                    uglyNumber.insert(temp);
                    uglyNumberPQueue.push(temp);
                }
                //压入3的
                temp = minUglyNum * 3;
                if(uglyNumber.find(temp) == uglyNumber.end()){
                    uglyNumber.insert(temp);
                    uglyNumberPQueue.push(temp);
                }
                //压入5的
                temp = minUglyNum * 5;
                if(uglyNumber.find(temp) == uglyNumber.end()){
                    uglyNumber.insert(temp);
                    uglyNumberPQueue.push(temp);
                }
                uglyNumberPQueue.pop();
            }
            return static_cast<int>(minUglyNum);
        }
    }

        /*
            int temp = 2;
            while(uglyNumber.size() < n){
                if(isUglyNumber(temp)){
                    uglyNumber.emplace_back(temp);
                    temp ++;
                }
                else{
                    temp ++;
                }
            }
            return uglyNumber.back();
        }
    }

    bool isUglyNumber(int _number){
        while(_number % 2 == 0){
            _number >>= 1;
        }
        while(_number %3 == 0){
            _number /= 3;
        }
        while(_number % 5 == 0){
            _number /= 5;
        }
        return _number == 1;
    }
    */
};
