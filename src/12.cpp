class Solution {
public:
    string intToRoman(int num) {
        //从小到大，逐级递归拼接
        //输入数字是1-3999
        //二十分钟，主要是打代码有点长，一次提交，时间击败-90.69%，空间击败-68.61%
        //好做的中等题现在都可以挑战了
        string result = "";
        if(num == 0){
            return result;
        }
        else if(num >= 1 && num <= 3){
            result = "I";
            return result + intToRoman(num - 1);
        }
        else if(num == 4){
            result = "IV";
            return result + intToRoman(num - 4);
        }
        else if(num >= 5 && num <= 8){
            result = "V";
            return result + intToRoman(num - 5);

        }
        else if(num == 9){
            result = "IX";
            return result + intToRoman(num - 9);
        }
        else if(num >= 10 && num <= 39){
            result = "X";
            return result + intToRoman(num - 10);
        }
        else if(num >= 40 && num < 50){
            result = "XL";
            return result + intToRoman(num - 40);
        }
        else if(num >= 50 && num <= 89){
            result = "L";
            return result + intToRoman(num - 50);
        }
        else if(num >= 90 && num <= 99){
            result = "XC";
            return result + intToRoman(num - 90);
        }
        else if(num >= 100 && num <= 399){
            result = "C";
            return result + intToRoman(num - 100);
        }
        else if(num >= 400 && num <= 499){
            result = "CD";
            return result + intToRoman(num - 400);
        }
        else if(num >= 500 && num <= 899){
            result = "D";
            return result + intToRoman(num - 500);
        }
        else if(num >= 900 && num <= 999){
            result = "CM";
            return result + intToRoman(num - 900);
        }
        else if(num >= 1000){
            result = "M";
            return result + intToRoman(num - 1000);
        }
        return result;
    }
};
