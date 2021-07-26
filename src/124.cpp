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
    int maxSum;

    int maxGain(TreeNode * _node){
        //该函数计算以节点_node为根节点的路径最大和
        //边遍历边维护最大和
        if(_node == nullptr){
            return 0;
        }
        int leftGain = max(maxGain(_node->left), 0);    //负数就不计入了
        int rightGain = max(maxGain(_node->right), 0);

        //更新最大和
        maxSum = max(maxSum, _node->val + leftGain + rightGain);
        //返回结果
        return _node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        //本来是要去背八股文的，结果网页一直打不开，垃圾github，垃圾微软
        //先干翻字节吧，困难题
        //看了题解，现在自己实现
        //十分钟，两次提交，时间击败-85.39%，空间击败-69.20%
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }
};
