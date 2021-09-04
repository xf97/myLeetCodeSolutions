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
    int getSuccessor(TreeNode * node){
        TreeNode * right = node->right;
        while(right->left){
            right = right->left;
        }
        return right->val;
    }

    int getPreccessor(TreeNode * node){
        TreeNode * left = node->left;
        while(left->right){
            left = left->right;
        }
        return left->val;
    }    

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //第一次做这种题哈
        //有点小蒙，感觉有点懂了
        //看了题解了，太棒了递归的思想
        //绝了，很赞，三十分钟
        //空节点
        if(root == nullptr){
            return root;
        }
        if(root->val > key){
            //在左边
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            //在右边
            root->right = deleteNode(root->right, key);
        }
        else{
            //是自己了
            //是叶节点
            if(root->left == nullptr && root->right == nullptr){
                root = nullptr;
            }
            //有右子节点
            else if(root->right){
                //后继节点覆盖本节点
                root->val = getSuccessor(root);
                //在自己右子树里删除后继节点
                root->right = deleteNode(root->right, root->val);
            }
            //最后处理有左节点的
            else if(root->left){
                root->val = getPreccessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
        /*
        TreeNode * target = findNode(root, key);
        if(target == nullptr){
            //没得这个节点
            return root;
        }
        //然后找到他的前序节点
        TreeNode * prev = nullptr;
        findPrevNode(&prev, &root, target);
        //cout<<target->val<<" "<<prev->val<<endl;
        return root;
        */
    }
};