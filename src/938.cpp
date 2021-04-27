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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        //基本方法，遍历（无论广度还是深度都work），保存符合范围的节点，然后求和返回
        //范围为闭区间
        //不会是空树-树中最少有一个节点
        //Node.val互不相同-感觉暂时没用
        //即使不为空树，也添加边界条件
        //八分钟，一次提交通过，时间击败-61.21%，空间击败-6.90%
        if(root == nullptr){
            return -1;
        }
        else{
            //保存节点的vector
            vector<int> targetNodesVal;
            //开始遍历
            dfs(root, low, high, targetNodesVal);
            //边界条件处理
            if(targetNodesVal.size() == 0){
                return 0;
            }
            else{
                return accumulate(targetNodesVal.begin(), targetNodesVal.end(), 0);
            }
        }
    }

    //深度优先遍历，前序遍历
    void dfs(const TreeNode * _node, const int _lowLimit, const int _highLimit, vector<int> & _valList){
        //边界处理
        //空节点
        if(_node == nullptr){
            return;
        }
        else{
            //非空节点，判断
            if(_node->val >= _lowLimit && _node->val <= _highLimit){
                _valList.emplace_back(_node->val);
            }
            //向下遍历
            dfs(_node->left, _lowLimit, _highLimit, _valList);
            dfs(_node->right, _lowLimit, _highLimit, _valList);
            return;
        }
    }
};
