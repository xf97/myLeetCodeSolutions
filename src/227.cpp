class Solution {
public:
    int calculate(string s) {
        //我膨胀了，我现在也敢仰望中等题了
        //中缀表达式转后缀表达式，然后计算值
        //做出来啦！没看答案！
        /*
        time defeat: 20.62%
        space defeat: 82.49%
        */
        stack<int> nums;    //存储数字的栈
        stack<char> opes;   //存储操作符的栈
        stack<int> cacheNum;   //先暂存数字
        //中缀转后缀
        for(const auto & ch : s){
            if(isdigit(ch)){
                //是数字，现存起来
                cacheNum.push(ch - '0');
            }
            else if(isblank(ch)){
                //是空格，压入数字
                if(!cacheNum.empty()){
                    nums.push(getNum(cacheNum));
                }
                continue;
            }
            else{
                //是运算符，先压入数字
                if(!cacheNum.empty()){
                    nums.push(getNum(cacheNum));
                }
                if(opes.empty()){
                    //操作符栈为空就直接压入
                    opes.push(ch);
                }
                else{
                    //非空，比较当前操作符和栈顶运算符的优先级
                    //若高，则直接压入
                    //若低，则弹出栈顶元素，然后再比较
                    while(!opes.empty() && priority(opes.top(), ch)){
                        int num1 = nums.top();
                        nums.pop();
                        int num2 = nums.top();
                        nums.pop();
                        //cout<<getResult(num2, num1, opes.top())<<endl;
                        nums.push(getResult(num2, num1, opes.top()));
                        opes.pop();
                    }
                    opes.push(ch);
                }
            }
        }
        //处理最后的数字
        if(!cacheNum.empty()){
            nums.push(getNum(cacheNum));
        }
        //处理边界情况，没有操作符
        if(opes.empty()){
            return atoi(s.c_str());
        }
        //遍历完后，操作符逐个出栈，与运算数栈栈顶两个元素运算，结果压回运算数栈
        while(!opes.empty()){
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            nums.push(getResult(num2, num1, opes.top()));
            opes.pop();
        }
        //返回最后的结果
        return nums.top();
    }

    int getNum(stack<int> & _stack){
        //在原值上修改
        int weight = 0; //位权
        int result = 0; //结果
        //cout<<_stack.top()<<"****"<<endl;
        while(! _stack.empty()){
            result += _stack.top() * static_cast<int>(pow(10, weight));
            weight ++;
            _stack.pop();
        }
        //cout<<result<<endl;
        return result;
    }

    int getResult(const int _num1, const int _num2, const char _ope){
        if(_ope == '+'){
            return _num1 + _num2;
        }
        else if(_ope == '-'){
            return _num1 - _num2;
        }
        else if(_ope == '*'){
            return _num1 * _num2;
        }
        else{
            return _num1 / _num2;   //除法只保留整数部分
        }
    }

    //运算符只有+ - * /
    //比较运算符_ope1和_ope2的优先级，_ope1高就返回true，否则就返回false
    bool priority(const char _ope1, const char _ope2){
        if(_ope1 == '*' || _ope1 == '/'){
            //_ope2的优先级不会高于_ope1
            return true;
        }
        else if(_ope2 == '*' || _ope2 == '/'){
            //此时_ope1是+ -，_ope2的优先级高
            return false;
        }
        else{
            //此时_ope1和_ope2都是+ -
            return true;
        }
    }
};
