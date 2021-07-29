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
    void preFind(const TreeNode * _node, vector<int> & _result){
        if(_node == nullptr){
            return;
        }
        else{
            //根左右
            _result.push_back(_node->val);
            //左
            preFind(_node->left, _result);
            //右
            preFind(_node->right, _result);
            return;
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //今日份干翻阿里
        //两分钟，时间击败-100%，空间击败-84.74%
        //一次提交
        vector<int> result;
        //开始前序遍历
        preFind(root, result);
        return result;
    }
};
