class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //干翻蚂蚁金服！
        //边点重叠不算重叠
        //不对，细心一点
        //为0自然不重叠
        //二十分钟，三次提交，不太细心
        //时间击败-100%，空间击败-79.69%
        if(rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] || rec2[1] == rec2[3]){
            return false;   //面积为0
        }
        //如果面积不为0，那么考虑补集
        //只要不是不重叠那么就是重叠
        return !(rec2[2] <= rec1[0] ||  //右还在左的左边
                 rec2[0] >= rec1[2] ||  //左还在右的右边
                 rec2[1] >= rec1[3] ||  //下还在上的上边
                 rec2[3] <= rec1[1]     //上还在下的下边
        );
    }
};
