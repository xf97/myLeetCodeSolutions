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
    int result; //结果
    //求深度函数
    int getDepth(const TreeNode * _node){
        if(_node == nullptr){
            return 0;
        }
        int leftDepth = getDepth(_node->left);
        int rightDepth = getDepth(_node->right);
        //深度更新到直径
        result = max(result, leftDepth + rightDepth + 1);
        //返回深度
        return max(leftDepth, rightDepth) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //遍历，深搜，直径等于左子树深度加右子树深度
        //然后返回最长的路径
        //题目保证节点数目大于等于1
        //边界处理
        //一次提交，十分钟，看了题解，才理解是什么意思
        //时间击败-90.25%, 空间击败-34.09%
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return 0;
        }
        else{
            //求深度
            result = 1;
            //边求深度边更新直径
            getDepth(root);
            return result - 1;
        }
    }

};
