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
    void preOrderDfs(TreeNode * node, vector<TreeNode *> & nodes){
        if(node == nullptr){
            return;
        }
        else{
            //压入自己 
            nodes.emplace_back(node);
            //根左右
            preOrderDfs(node->left, nodes);
            preOrderDfs(node->right, nodes);
            return;
        }
    }

public:
    void flatten(TreeNode* root) {
        //干翻出这个题的公司！
        //一种比较土的方法是，用一个数组保存先序遍历的结果 
        //时间复杂度On，空间复杂度On
        //然后再串联它们
        //十五分钟，一次提交，时间击败-92.87%，空间击败-26.36%
        if(root ==  nullptr){
            return;
        }
        vector<TreeNode *> nodes;
        //开始先序遍历
        preOrderDfs(root, nodes);
        //然后开始串联
        int length = nodes.size();
        for(int i = 0; i < length; ++ i){
            if(i == length - 1){
                nodes[i]->left = nullptr;
                nodes[i]->right = nullptr;
            }
            else{
                nodes[i]->left = nullptr;
                nodes[i]->right = nodes[i + 1];
            }
        }
        return;
    }
};
