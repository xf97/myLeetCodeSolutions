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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //干翻字节，我又来了，写链表和树还是用C++的指针舒服
        //用队列，直接翻转奇数层
        //时间击败-21.07%，空间击败-42.07%
        vector<queue<TreeNode *>> dq(2);    //队列，层序遍历，存指针，两个队列，交叉使用
        int flag  = 0;  //1右往左，0左往右
        int newFlag = 1;
        vector<vector<int>> result; //结果
        //边界处理，会有空树
        if(root ==  nullptr){
            return result;
        }
        //根节点压入
        dq[flag].push(root);
        vector<int> aLevelResult;
        //开始遍历
        while(!dq[flag].empty()){
            TreeNode * node = dq[flag].front();
            dq[flag].pop();
            aLevelResult.push_back(node->val);
            if(node->left){
                dq[newFlag].push(node->left);
            }
            if(node->right){
                dq[newFlag].push(node->right);
            }
            if(dq[flag].empty()){
                //一层完了
                flag = newFlag;
                newFlag = (flag == 1)? 0 :  1;  //新一层
                result.emplace_back(aLevelResult);
                aLevelResult.clear();
            }
        }
        //翻转奇数层
        for(int i = 0; i <  result.size(); ++ i){
            if(i & 0x1){
                //奇数层
                reverse(result[i].begin(), result[i].end());
            }
        }
        return result;
    }
};
