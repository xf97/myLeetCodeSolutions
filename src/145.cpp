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
/*
C++后序递归遍历
time defeat: 100%
space defeat: 61.02%
time consuming: less than 10 mins
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result; //结果数组
        if(root == NULL){
            return result;
        }
        //递归后序遍历
        doPostOrder(result, root);
        return result;
    }
    
    //使用引用，造成原地修改；使用const，加快速度 
    void doPostOrder(vector<int>& _result, const TreeNode* _node){
        if(_node == NULL){
            return;
        }
        else{
            doPostOrder(_result, _node->left);
            doPostOrder(_result, _node->right);
            _result.emplace_back(_node->val);
            return;
        }
    }
};
