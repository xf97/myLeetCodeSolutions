class Solution {
public:
    int maxArea(vector<int>& height) {
        //感觉是个计算的题
        //从左向右计算，从右向左收拢
        //容积值等于 min(左边, max(右边))) * 长度
        //记录最大值
        //n大于等于2
        //数组中所有元素非负
        //边界情况，其实可以不处理
        //十五分钟，第一种方法，超时，通过52/60，复杂度On2
        //双指针方法，三分钟，一次提交通过，时间击败-27.16%，空间击败-52.68%
        if(height.size() == 2){
            return min(height[0], height[1]) * 1;
        }
        int result = INT_MIN;   //结果
        //看了题解，知道了双指针，那现在自己来实现
        int lPoint = 0; //左指针
        int rPoint = height.size() - 1; //右指针
        while(lPoint < rPoint){
            //开始试探
            int tempMax = (min(height[lPoint], height[rPoint]) * (rPoint - lPoint));
            result = max(result, tempMax);
            //移动双指针，总是移动小的那边
            //因为移动大的那边只会让数字更小
            if(height[lPoint] <= height[rPoint]){
                lPoint ++;
            }
            else{
                rPoint --;
            }
        }
        return result;
        /*
        //int型的构造析构和赋值的消耗差不多，因此在循环内声明
        for(int i = 0; i < (height.size() - 1); i ++){
            int tempMax = INT_MIN;  
            for(int j = (i + 1); j < height.size(); j++){
                //计算容积值
                int curArea = (min(height[i], height[j]) * (j - i));
                //计算最大值
                tempMax = (tempMax > curArea) ? tempMax : curArea;
            }
            //赋值
            result = (tempMax > result) ? tempMax : result;
        }
        //现在返回最大值
        return result;
        */
    }
};
