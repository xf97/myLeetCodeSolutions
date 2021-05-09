class Solution {
public:
    bool checkRecord(string s) {
        //一次扫描字符串，边扫描边记录
        //时间复杂度On, 空间复杂度o1
        //五分钟，一次提交，时间击败-100%，空间击败-52.17%
        //边界处理
        if(s.size() <= 1){
            return true;
        }
        int aCount = 0; //a的出现次数
        bool pCount = false;    //连续迟到标志
        for(int i = 0; i < s.size(); i++){
            if(pCount){
                return false;
            }
            else if(s[i] == 'A'){
                aCount ++;
                if(aCount > 1){
                    return false;
                }
            }
            else if(s[i] == 'L'){
                if(i < (s.size() - 2) && (s[i + 1] == 'L') && (s[i + 2] == 'L')){
                    pCount = true;
                }
            }
            else{
                continue;
            }
        }
        return aCount <= 1 && pCount == false;
    }
};
