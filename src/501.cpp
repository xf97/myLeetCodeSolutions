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
最基本的方法，遍历二叉树，使用hash_map记录出现次数
*/
//时间击败　66%
//空间击败　21%
//耗时　20min
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result; //结果数组
        unordered_map<int, int>  mode;  //众数表，元素一数字，元素二出现次数
        if(root == NULL){
            return result;
        }
        else{
            //非空树，递归检查二叉树
            recFindMode(root, mode);
            int maxNum = 0;
            for(auto i = mode.begin(); i != mode.end(); i++){
                if(i->second >= maxNum){
                    maxNum = i->second;
                }
            }
            for(auto i = mode.begin(); i != mode.end(); i++){
                if(i->second == maxNum){
                    result.emplace_back(i->first);
                }
            }
            return result;
        }
    }
    
    void recFindMode(const TreeNode* _node, unordered_map<int, int> & _mode){
        if(_node ==  NULL){
            return;
        }
        else{
            _mode[_node->val] ++;
            recFindMode(_node->left, _mode);
            recFindMode(_node->right, _mode);
            return;
        }
    }
};
