/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            //二叉树的题，还是先想用C++写一下
            //要考虑性质，不能蛮干
            //前序递归，考察每一个节点，指定节点应该一个在左，一个在右，注意一个自身就是根节点的情况
            //两层遍历，O(n2)
            //可以，十五分钟，一次提交，差点On2就超时了
            //时间击败-5.18%，空间击败-78.74%
            if(root  == nullptr){
                return root;
            }
            else{
                //前序
                //要处理本身是的情况
                bool leftFlag = inThisSubTree(root->left, p, q);
                bool rightFlag = inThisSubTree(root->right,  p,  q);
                if((root ==  p || root == q) && (leftFlag || rightFlag)){
                    return root;
                }
                else if( leftFlag && rightFlag){
                    //一个在左边一个在右边，找到了
                    return root;
                }
                //都在左边，往左去
                else if(leftFlag == true &&  rightFlag == false){
                    return lowestCommonAncestor(root->left, p, q);
                }
                else{
                    //否则否右去
                    return lowestCommonAncestor(root->right, p, q);
                }
                //必然存在公共节点
                return nullptr;
            }
    }

    bool  inThisSubTree(TreeNode * _node, TreeNode * _p,  TreeNode * _q){
        if(_node == nullptr){
            return false;
        }
        else if(_node == _p ||  _node == _q){
            return true;
        }
        else{
            //继续递归
            bool result = (inThisSubTree(_node->left, _p,  _q) || inThisSubTree(_node->right,  _p,  _q));
            return result; 
        }
    }
};
*/
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
    bool inThisSubTree(const TreeNode * _node, const TreeNode * _p, const TreeNode * _q){
        //现在只用遍历这棵树
        if(_node == nullptr){
            return false;
        }
        else if(_node == _p || _node == _q){
            return true;
        }
        else{
            //遍历吧
            return inThisSubTree(_node->left, _p, _q) || inThisSubTree(_node->right, _p, _q);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //干翻蚂蚁金服
        //可以递归
        //时间复杂度应该是On2
        //开始，注意判断节点是自己的情况
        //十五分钟，一次提交
        if(root == p || root == q){
            //一个节点等于自己，另一个只能是在自己下面
            return root;
        }
        else{
            //在自己左边吗
            bool leftFlag = inThisSubTree(root->left, p, q);
            //在自己右边吗
            bool rightFlag = inThisSubTree(root->right, p, q);
            //判断
            if(leftFlag && rightFlag){
                //一个在左一个在右
                return root;
            }
            else if(leftFlag && !rightFlag){
                //都在左边
                return lowestCommonAncestor(root->left, p, q);
            }
            else{
                //都在右边
                return lowestCommonAncestor(root->right, p, q);
            }
        }
    }
};
