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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //碰到这种情况，感觉可以递归的去想
        //现在2.50，给自己45分钟，把它做出来
        //考虑极端情况，A是空树B是空树
        //碰到满足的，就终止返回
        //15.34完成，时间击败：41.45%，空间击败：56.90%
        if(A == nullptr || B == nullptr){
            //cout<<A->val<<" "<<B->val<<"xixi"<<endl;
            return false;
        }
        else{
            bool result = false;
            //首先校验根节点的
            result = doesTree1HasTree2(A, B);
            //如果根节点有问题，再看左子树的
            if(!result){
                result = isSubStructure(A->left, B);
            }
            //左子树有问题，再看右子树的
            if(!result){
                //cout<<A->val<<" "<<B->val<<"haha"<<endl;
                result = isSubStructure(A->right, B);
            }
            return result;
        }
    }

    bool doesTree1HasTree2(TreeNode * _bigTree, TreeNode * _smallTree){
        if(_smallTree == nullptr){
            cout<<"haha"<<endl;
            return true;
        }
        if(_bigTree == nullptr){
            return false;
        }
        //节点值是int，可以比较
        if(_bigTree->val != _smallTree->val){
            return false;
        }
        //cout<<_bigTree->val<<" "<<_smallTree->val<<endl;
        return doesTree1HasTree2(_bigTree->left, _smallTree->left) && doesTree1HasTree2(_bigTree->right, _smallTree->right);
    }
};
