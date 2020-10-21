class Solution {
    /*
    基本想法，扫描输入字符串，删除 长按 元素
    不行-进阶想法，双指针
    */
     /*
	time defeat: 53.4%
	space defeat: 15.9%
     */
public:
    bool isLongPressedName(string name, string typed) {
        //边际情况
        if(name.empty() || typed.empty()){
            return false;
        }
        if(name[0] != typed[0]){
            return false;
        }
        //两个指针
        int nameIndex = 0;
        int typeIndex = 0;
        while(nameIndex < name.size() && typeIndex < typed.size()){
            //字母匹配，同时移动
            if(name[nameIndex] == typed[typeIndex]){
                nameIndex ++;
                typeIndex ++;
            }
            //字母不匹配，但存在 长按 情况，移动typed指针
            else if(name[nameIndex] != typed[typeIndex] && typed[typeIndex] == typed[typeIndex - 1]){
                typeIndex ++;
            }
            //字母不匹配并且也不存在长按，失败
            else if(name[nameIndex] != typed[typeIndex] && typed[typeIndex] != typed[typeIndex - 1]){
                return false;
            }
            else{
                continue;
            }
        }
        if(nameIndex == name.size()){
            //同时匹配到末尾
            if(typeIndex == typed.size())
                return true;
            else{
                //如果typed没有到末尾，那么剩下的字母应该都是一样的
                for(int i = typeIndex + 1; i < typed.size(); i++){
                    if(typed[i] != typed[i - 1]){
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
};
