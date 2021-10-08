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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //这个题不该是简单题呀，想一下
        //学到了，第一个夹在中间的节点
        //题目保证节点值唯一
        //十分钟，一次提交，时间击败-23.85%，空间击败-86.01%
        while(root){
            //都大于，在左子树
            if(root->val > p->val && root->val > q->val){
                root = root->left;
            }
            else if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else{
                //夹在中间了兄弟们
                //或者是自己就是节点
                return root;
            }
        }
        //没找到公共祖先
        return nullptr;
    }
};
