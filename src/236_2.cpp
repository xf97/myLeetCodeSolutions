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
private:
    bool inThisTree(const TreeNode * root, const TreeNode * target){
        //查看target是不是在root这个树上
        if(root == nullptr){
            return false;
        }
        else if(root == target){
            return true;
        }
        else{
            return inThisTree(root->left, target) || inThisTree(root->right, target);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //递归的方法
        //两个同时在左，向左
        //两个同时在右，向右
        //一个在左一个在右，找到
        //一个相等，另一个在自己这棵树上，找到
        //p和q一定在这个二叉树中
        //十五分钟，一次提交，时间击败-5.29%，空间击败-73.39%
        if(root == p){
            return root;
        }
        else if(root == q){
            return root;
        }
        else{
            bool pLeftFlag = inThisTree(root->left, p);
            bool pRightFlag = inThisTree(root->right, p);
            bool qLeftFlag = inThisTree(root->left, q);
            bool qRightFlag = inThisTree(root->right, q);
            if(pLeftFlag && qRightFlag){
                return root;
            }
            else if(pRightFlag && qLeftFlag){
                return root;
            }
            else if(pLeftFlag && qLeftFlag){
                return lowestCommonAncestor(root->left, p, q);
            }
            else{
                return lowestCommonAncestor(root->right, p, q);
            }
        }
    }
};
