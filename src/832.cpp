class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        //还是这种题我喜欢
        //两分钟，一次提交，时间击败-90.88%, 空间击败-47.26%
        for(auto & line : image){
            reverse(line.begin(), line.end());
            for(auto & ele: line){
                ele = (!ele);
            }
        }
        return image;
    }
};
