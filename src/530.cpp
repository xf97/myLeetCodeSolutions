/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    /*
    1.根据二叉搜索树的性质，最小绝对值应该出现在同一棵子树中--错误
    深度遍历，求值
    2. 不错，补充，最小绝对值还可以出现在两个地方，左子树的最右叶子和根节点，右子树的最左节点和根节点--错误
    3. 最土方法，遍历，获得一个新节点，就计算一次新的最小绝对值
    */
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
