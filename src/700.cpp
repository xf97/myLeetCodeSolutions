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
    TreeNode* searchBST(TreeNode* root, int val) {
        //保持手感，做道简单题
        //根据二叉搜索树的性质来做，时间复杂度Olog2n
        //递归搜索，每层只用遍历一个节点
        //六分钟，一次提交，时间击败-88.09%，空间击败-5.34%
        if(root == nullptr){
            //cout<<root<<" "<<1<<endl;
            return root;
        }
        else if(root->val == val){
            //cout<<2<<endl;
            return root;
        }
        else if(root->val > val){
            //cout<<3<<endl;
            return searchBST(root->left, val);
        }
        else{
            //cout<<4<<endl;
            return searchBST(root->right, val);
        }
    }
};
