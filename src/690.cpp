/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        //是一个类似树求和的问题
        //可以尝试用队列
        //时间复杂度On，空间复杂度On
        //边界情况
        //题目比较复杂，头大，两次提交二十分钟，简单题
        //时间击败-9.89%，空间击败-96.25%
        if(employees.size() == 0){
            return 0;
        }
        int result = 0;
        queue<int> idQueue; //队列
        idQueue.push(id);   //初始队列入队
        while(!idQueue.empty()){
            //获得队头
            int index = 0;
            auto pEmployee = employees[index];
            while(pEmployee->id != idQueue.front()){
                //cout<<pEmployee->id<<" "<<idQueue.front()<<endl;
                pEmployee = employees[++ index];
            }
            //计算队头值
            result += (pEmployee->importance);
            //压入队尾
            for(const auto subId : (pEmployee->subordinates)){
                //每个人的直接领导只有一个，所以不会重复压入
                idQueue.push(subId);
            }
            //队头出列
            idQueue.pop();
        }
        return result;
    }
};
