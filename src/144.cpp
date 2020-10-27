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
递归－前序遍历，是根左右
time defeat: 100%
space defeat: 12%
time consuming: 10 mins
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; //遍历结果
        //极端情况　
        if(root == NULL){
            return result;
        }
        else{
            preRecFind(root, result);
            return result;
        }
    }
    
    void preRecFind(const TreeNode * node, vector<int> & _result){
        //使用const减少空间浪费，使用引用支持参数修改
        if(node == NULL){
            return;
        }
        else{
            _result.emplace_back(node->val);    //推入元素，使用emplace_back减少空间开销
            //递归
            preRecFind(node->left, _result);
            preRecFind(node->right, _result);
            return;
        }
    }
};
