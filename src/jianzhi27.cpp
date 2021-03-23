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
    TreeNode* mirrorTree(TreeNode* root) {
        //所谓镜像，就是交换非叶节点的两个子节点
        //如果是叶节点或者是空节点，就不交换
        //不需要返回值
        //时间击败：100%，空间击败：70.17%
        mirrorTreeCore(root);
        return root;
    }

    void mirrorTreeCore(TreeNode * root){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return;
        }
        else{
            //否则，交换他们的子节点，无论是否为空
            TreeNode * temp = root->left;
            root->left = root->right;
            root->right = temp;
            //继续向两个子树进发
            if(root->left){
                mirrorTreeCore(root->left);
            }
            if(root->right){
                mirrorTreeCore(root->right);
            }
            return;
        }
    }
};
