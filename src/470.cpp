// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        //今日最后一题，这个还真是不会，感觉有点智力题的感觉
        //我理解这种题了，我用1-7，现在要生成1-10，偏移肯定不行
        //方法应该是用rand7产生大于10的随机序列，从里面均匀取值
        //第一次做这种题，涉及很多数学知识，确实开阔眼界了
        //时间击败-92.33%，空间击败-29.05%
        int num = (rand7() - 1) * 7 + rand7();  //均匀产生1-49的数字
        while(num > 40){
            //小于40的映射到1-10才是等概率
            num = (rand7() - 1) * 7 + rand7();
        }
        //num % 10 = [0, 9], 那么要加一
        return 1 + num % 10;
    }
};
