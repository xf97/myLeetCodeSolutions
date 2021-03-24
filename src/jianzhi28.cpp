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
    bool isSymmetric(TreeNode* root) {
        //要把空节点给考虑进去
        //nice，一次过，十五分钟
        //时间击败：86.79%，空间击败：49.68%
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return true;
        }
        else{
            bool result = isSymmetric(root->left, root->right); //函数重载
            return result;
        }
    }

    bool isSymmetric(const TreeNode * _node1, const TreeNode * _node2){
        //分情况讨论
        if(_node1 == nullptr && _node2 == nullptr){
            //cout<<"*\n";
            return true;
        }
        else if(_node1 == nullptr || _node2 == nullptr){
            //只有一方为空
            //cout<<"$\n";           
            return false;
        }
        else if(_node1->val != _node2->val){
            //cout<<"&\n";          
            cout<<_node2->val<<" "<<_node2->val<<endl;
            //两个节点都存在，但是数值不等
            return false;
        }
        else{
            
            //cout<<_node2->val<<" "<<_node2->val<<endl;
            //两个节点都存在，并且数值相等，继续向下
            //左对右，右对左
            return isSymmetric(_node1->left, _node2->right) && isSymmetric(_node1->right, _node2->left);
        }
    }
};
