class Solution {
public:
    string removeKdigits(string num, int k) {
        //干翻出这个题的公司
        //先统计位数，然后用大根堆，逐个弹出
        //剩下的按原始顺序返回就可以
        //果然还是比较难的，单调栈加队列，大师我误了
        //用vector模拟双端队列，整个队列单调不降
        vector<char> dq;
        for(const char & c : num){
            //弹出大于当前c的元素，并且扣减k
            //char可以直接比较大小
            while(dq.size() && dq.back() > c && k){
                k -= 1;
                dq.pop_back();
            }    
            dq.push_back(c);
        }
        //然后处理还剩余的k
        while(k){
            k -= 1;
            dq.pop_back();
        }
        //组织答案
        string result = "";
        bool prevZero = true;
        for(const char & c : dq){
            if(prevZero && c == '0'){
                continue;
            }
            prevZero = false;   //前导0结束
            result += c;
        }
        //最后处理0
        return (result == "") ? "0" : result;
        /*
        int length = num.size();
        if(length == k){
            return "0";
        }
        priority_queue<int, vector<int>, less<int>> pq;
        //开始遍历
        int index = 0;
        int temp = 0;
        while(index < length){
            temp = index;
            if(index == 0 && temp < length - 1 && num[temp + 1] == '0'){
                ++ temp;
            }
            //string转int
            int numLength = (temp == index) ? 1 : (temp - index + 1);
            int num1 = atoi(num.substr(index, numLength).c_str());
            index = temp + 1;
            cout<<num1<<endl;
            pq.push(num1);
        }
        //开始往外pop
        temp = k;
        while(k --){
            string target = to_string(pq.top());
            num.erase(num.find(target), target.size());
            pq.pop();
        }
        //然后
        return (atoi(num.c_str()) == 0) ? "0" : num;
        */
    }
};
