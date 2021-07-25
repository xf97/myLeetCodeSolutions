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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //干翻字节，干翻拼多多
        //细心一些，可以用递归做
        //五分钟，一次提交通过
        //时间击败-69.86%，空间击败-84.44%
        //要处理空树
        if(root == nullptr){
            return false;
        }
        else if(root->val == targetSum && root->left == nullptr && root->right == nullptr){
            //到达叶节点
            return true;
        }
        else if(root->left || root->right){
            //非叶节点
            return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        }
        else{
            //是叶节点，但是值对不上
            return false;
        }
    }
};
