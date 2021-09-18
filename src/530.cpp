/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
    //哇，新知识，搜索二叉树中序遍历是有序的递增数组
    //time consuming: less than 1 hour
public:
    int getMinimumDifference(TreeNode* root) {
        int minD = INT_MAX;   //存储绝对值
        if(root == NULL){
            //边界情况，好像不用考虑？
            return minD;
        }
        else{
            //开始深度遍历
            vector<int> appearNodeVal;
            getMinDistance(root, minD, appearNodeVal);
            return minD;
        }
    }
    
    void getMinDistance(TreeNode *_node, int & _minD, vector<int> & _valList){
        //终止条件
        if(_node == NULL){
            return;
        }
        else{
            //更新最小绝对值
            for(auto i : _valList){
                if(abs(_node->val - i) < _minD){
                    _minD = abs(_node->val - i);
                }
            }
            //记录出现节点
            if(find(_valList.begin(), _valList.end(), _node->val) == _valList.end()){
                //只记录未出现过的 值
                _valList.emplace_back(_node->val);
            }
            //遍历进下一层
            getMinDistance(_node->left, _minD, _valList);
            getMinDistance(_node->right, _minD, _valList);
            return;
        }
    }
};
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void inorderTravel(TreeNode * node, vector<int> & val){
        if(node == nullptr){
            return;
        }
        //左根右
        inorderTravel(node->left, val);
        val.push_back(node->val);
        inorderTravel(node->right, val);
        return;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        //中序遍历
        //边界情况
        //十分钟，一次提交，时间击败-97.52%，空间击败-14.13%
        if(root == nullptr){
            return -1;
        }
        vector<int> val;
        inorderTravel(root, val);
        //然后计算绝对值
        int result = INT_MAX;
        int length = val.size();
        for(int i = 0; i < length - 1; ++ i){
            if(abs(val[i] - val[i + 1]) < result){
                result = abs(val[i] - val[i + 1]);
            }
        }
        return result;
    }
};
