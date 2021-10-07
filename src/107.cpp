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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //层序遍历，然后翻转
        //十分钟，一次提交，时间击败-74.24%，空间击败-9.80%
        vector<vector<int>> result; //结果
        if(root == nullptr){
            return result;
        }
        queue<TreeNode *> q;    //队列
        q.push(root);
        while(!q.empty()){
            int size = q.size();    //获取这一层的节点数量
            vector<int> aLevel; //这一层从左往右的节点值
            for(int i = 0; i < size; ++ i){
                TreeNode * node = q.front();
                q.pop();
                aLevel.push_back(node->val);
                //下层节点压入
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            //记录这一层
            result.push_back(aLevel);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
