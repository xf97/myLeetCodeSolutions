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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //今日份干翻字节！
        //才是个二叉树层序遍历，太菜了，这种还敢中等呢？(膨胀)
        //今天给你整个只用Ologn的 (指辅助空间)算法
        //八分钟，一次提交，时间击败-81.41%，空间击败-30.87%
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }
        //辅助存储空间
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<int> aLevel;
            //一层一层的遍历
            int size =  q.size();
            TreeNode * node =  nullptr;    //感觉赋值的消耗比不停地构造析构低
            for(int i = 0; i < size; ++ i){
                node = q.front();
                q.pop();
                aLevel.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            result.emplace_back(aLevel);
        }
        return result;
    }
};
