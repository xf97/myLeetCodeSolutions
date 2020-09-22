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
思路　是一个动态规划的方式　要试探在最上层和第二层布置监控的数量
得出最小的监控数量　布置的规则是隔两层放置
广度优先遍历　分层的　递归
*/
//我自己的解法，困难题，109/170的通过率
/*
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        queue<TreeNode*>  q;
        queue<TreeNode*> leftQ;
        queue<TreeNode*> rightQ;
        q.push(root);
        int _1stLevel = recBfs(q, 0);
        int _2ndLeftLevel = INT_MAX;
        int _2ndRightLevel = INT_MAX;
        if(root->left != NULL){
            leftQ.push(root->left);
            _2ndLeftLevel = recBfs(leftQ, 0);
        }
        if(root->right != NULL){
            rightQ.push(root->right);
            _2ndRightLevel = recBfs(rightQ, 0);
        }
        int _2ndLevel = 0;
        cout<<_1stLevel<<" "<<_2ndLeftLevel<<" "<<_2ndRightLevel<<endl;
        if(_2ndLeftLevel ==  INT_MAX &&  _2ndRightLevel == INT_MAX){
            _2ndLevel = INT_MAX;
        }
        else if(_2ndRightLevel != INT_MAX  &&  _2ndLeftLevel == INT_MAX){
            _2ndLevel = _2ndRightLevel;
        }
        else if(_2ndLeftLevel!= INT_MAX  &&  _2ndRightLevel == INT_MAX){
            _2ndLevel = _2ndLeftLevel;
        }
        else{
            _2ndLevel = _2ndLeftLevel + _2ndRightLevel;
        }
        return min(_1stLevel, _2ndLevel);
    }

    int recBfs(queue<TreeNode*> _q, int _flag){
        if(_q.empty()){
            return 0;
        }
        int cameraNum = 0;
        int thisLevelSize = _q.size();
        if(_flag % 3 == 0){
            cameraNum = thisLevelSize;
        }
        else{
            cameraNum = 0;
        }
        queue<TreeNode*> nextLevelQ;
        while(!_q.empty()){
            TreeNode* node = _q.front();    //获取队首节点
            //cout<<node->val<<endl;
            //下层节点入队
            if(node->left != NULL){
                nextLevelQ.push(node->left);
            }
            if(node->right != NULL){
                nextLevelQ.push(node->right);
            }
            _q.pop();   //队首出队
        }
        if(_flag %  3 == 2 && nextLevelQ.size() == 0){
            //没有下一层来帮忙监控本层，则应该本层添加监控
            cameraNum = thisLevelSize;
        }
        //cout<<"下一层.\n";
        return cameraNum + recBfs(nextLevelQ, _flag + 1);
    }*/
    //官方题解　
    struct Status {
    int a, b, c;
};

class Solution {
public:
    Status dfs(TreeNode* root) {
        if (!root) {
            return {INT_MAX / 2, 0, 0};
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));
        int c = min(a, lb + rb);
        return {a, b, c};
    }

    int minCameraCover(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return b;
    }
};
