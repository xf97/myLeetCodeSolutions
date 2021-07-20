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
    vector<int> rightSideView(TreeNode* root) {
        //开始今日份干翻字节
        //二叉树用C++写
        //第一个方法，层序遍历，不用分层，只要每层的最后一个节点-从左至右遍历
        //就压最后一个进来就好了
        //时间复杂度On，空间复杂度Ologn-辅助层序遍历的队列
        //十七分钟，中等题，一次提交，时间击败-72.66%，空间击败-18.87%
        //边界情况
        vector<int> result; //结果
        if(root == nullptr){
            return result;
        }
        vector<queue<TreeNode *>> vq(2);   //辅助层序遍历的队列，用于分层
        int index =  0;
        //压入队列
        vq[index].push(root);
        while(!vq[index].empty()){
            TreeNode  * node = nullptr; //vq[index].front();   //获取队头值
            int newIndex = (index == 0) ? 1 : 0;
            while(!vq[index].empty()){
                node = vq[index].front();
                //压入下一层节点
                if(node->left){
                    vq[newIndex].push(node->left);
                }
                if(node->right){
                    vq[newIndex].push(node->right);
                }
                vq[index].pop();
            }
            //为空时node指向该层最后一个节点
            //压入
            result.push_back(node->val);
            index = newIndex;
        }
        return result;
    }
};
