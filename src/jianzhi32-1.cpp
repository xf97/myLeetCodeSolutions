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
    vector<int> levelOrder(TreeNode* root) {
        //这个不难，不用当中等题
        //前序遍历二叉树，用队列存储元素，先进先出
        //出去一个，就把它的子节点压进，直到队列为空
        //一次通过，15分钟，时间击败：100%，空间击败：55.42%
        vector<int> result; //结果， 因为不管何种结果都将返回该结构，因此一次构造和析构函数的代价是必须的
        if(root == nullptr){
            return result;
        }
        else if(root->left == nullptr && root->right == nullptr){
            //只有根节点
            result.emplace_back(root->val);
            return result;
        }
        else{
            //声明队列
            queue<TreeNode *> nodeQueue;
            //首先把根节点压进去
            nodeQueue.push(root);
            //然后开始遍历
            while(! nodeQueue.empty()){
                //记录队头
                TreeNode * node = nodeQueue.front();
                //cout<<node->val<<endl;
                result.emplace_back(node->val);
                //压入子节点，从左到右
                if(node->left != nullptr){
                    //cout<<"haha\n";
                    nodeQueue.push(node->left);
                }
                if(node->right != nullptr){
                    //cout<<"xixi\n";
                    nodeQueue.push(node->right);
                }
                //队头出列
                nodeQueue.pop();
            }
            return result;
        }
    }
};
