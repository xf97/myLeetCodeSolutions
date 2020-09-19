/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <numeric>  //导入对vector求和的头文件

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //递归遍历
        vector<int> result; //左叶子值数组
        if(root == NULL){
            return 0;
        }
        //开始递归
        inorderRec(result, root, -1);
        return accumulate(result.begin(), result.end(), 0);
    }

    //使用引用，支持直接修改参数
    void inorderRec(vector<int> & _result, const TreeNode* _node, const int _flag ){
        if(_node ==  NULL){
            return;
        }
        if(_flag == 1 && _node->left == NULL && _node->right == NULL){
            _result.emplace_back(_node->val);   //emplace_back相比push_back效率更高
            return;
        }
        else{
            inorderRec(_result,  _node->left, 1);
            inorderRec(_result, _node->right, 0);
        }
    }
};
