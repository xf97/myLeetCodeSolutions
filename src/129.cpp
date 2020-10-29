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
最基本的方法－深度遍历，保存每一层的结果，碰到叶子存储路径
time defeat: 82%
space defeat: 9%
time consuming: 30 mins
*/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        //极端情况
        if(root == NULL){
            return 0;
        }
        else if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        else{
            vector<int> path;   //用来存储每条路径的数组
            vector<int> temp;   //用来存储一条路径的数组
            recDfs(root, temp, path);
            /*
            for(auto i : path){
                cout<<i<<endl;
            }*/
            return accumulate(path.begin(), path.end(), 0);
        }
    }
    
    void recDfs(const TreeNode * _node, vector<int> & _nowPath, vector<int> & _allPath){
        if(_node == NULL){
            return;
        }
        else if(_node->left == NULL && _node->right == NULL){
            //碰到叶子节点
            _nowPath.emplace_back(_node->val);
            //组合出当前数字
            string temp = "";
            for(int i: _nowPath){
                temp += to_string(i);
            }
            //压入结果
            _allPath.emplace_back(atoi(temp.c_str()));
            //回退当前结果
            _nowPath.pop_back();
            return;
        }
        else{
            _nowPath.emplace_back(_node->val);
            //深度遍历
            recDfs(_node->left, _nowPath, _allPath);
            recDfs(_node->right, _nowPath, _allPath);
            //释放当前节点
            _nowPath.pop_back();
            return;
        }
    }
};
