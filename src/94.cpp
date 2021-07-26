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
    void inorderDfs(const TreeNode * _node, vector<int> & _result){
        if(_node == nullptr){
            return;
        }
        else{
            //先左
            inorderDfs(_node->left, _result);
            //根
            _result.push_back(_node->val);
            //右
            inorderDfs(_node->right, _result);
            return;
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //干翻字节
        //中序遍历，用递归做
        //三分钟，一次提交，时间击败-42.13%，空间击败-13.76%
        vector<int> result;
        if(root == nullptr){
            return result;
        }
        inorderDfs(root, result);
        return result;
    }
};
