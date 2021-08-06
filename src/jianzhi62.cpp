class Solution {
private:
    int f(int n, int m){
        if(n == 1){
            return 0;
        }
        int x = f(n - 1, m);
        return (m + x) % n;
    }
public:
    int lastRemaining(int n, int m) {
        //干翻蚂蚁金服
        //约瑟夫环问题，用数学
        //一次提交，十五分钟，时间击败-98.77%，空间击败-17.95%
        return f(n, m);
    }
};
