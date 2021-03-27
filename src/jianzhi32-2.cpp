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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //这个题相对于前一题难，这一题更应该作为中等题
        //要记录本层有几个节点，用来确定层数
        //广度优先，还是要用队列
        //十四分钟完成，一次成功
        //时间击败：81.73%，空间击败：82.89%
        vector<vector<int>> result; //此时已经可以声明
        if(root == nullptr){
            return result;
        }
        else{
            queue<TreeNode *> nodeQueue;   //队列
            nodeQueue.push(root);
            //本层有一个，还不知道下一层有几个
            int toBePrinted = 1;
            int nextLevel = 0;
            vector<int> aLevelNode; //存储一层节点的值
            //开始按层次遍历
            while(! nodeQueue.empty()){
                //获取队头
                TreeNode * head = nodeQueue.front();
                //记录本层的节点
                aLevelNode.emplace_back(head->val);
                //下层节点入队
                if(head->left != nullptr){
                    nodeQueue.push(head->left);
                    nextLevel ++;
                }
                if(head->right != nullptr){
                    nodeQueue.push(head->right);
                    nextLevel ++;
                }
                //队头使命完成，出队
                nodeQueue.pop();
                toBePrinted --;
                //如果本层打印完，就压入本层节点，然后重置值
                if(toBePrinted == 0){
                    result.emplace_back(aLevelNode);
                    aLevelNode.clear(); //重置
                    toBePrinted = nextLevel;
                    nextLevel = 0;
                }
            }
            return result;
        }
    }
};
