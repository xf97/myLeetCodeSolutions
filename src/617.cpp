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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //我感觉我对C++指针的理解恢复了些，所以练一道指针题
        //基本思想，同序遍历，返回根
        //边界情况处理
        /*
        time defeat: 75.20%
        space defeat: 68.82%
        */
        if(root1 == nullptr){
            return root2;
        }
        else if(root2 == nullptr){
            return root1;
        }
        else{
            //要使用new去申请新的空间
            TreeNode * resultTree = new TreeNode(root1->val + root2->val);
            //递归去搜索就可以了
            //要同序，要给两个子节点赋值
            resultTree->left = mergeTrees(root1->left, root2->left);
            resultTree->right = mergeTrees(root1->right, root2->right);
            return resultTree;
        }
    }
};
