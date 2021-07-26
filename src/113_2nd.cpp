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
    void findPaths(const TreeNode * _node, int _target, vector<int> & _path, vector<vector<int>> & _results){
        //终止条件
        if(_node == nullptr){
            return;
        }
        else if(_node->left == nullptr && _node->right == nullptr){
            //叶节点判定
            if(_node->val == _target){
                _path.emplace_back(_target);
                _results.emplace_back(_path);
                //释放节点
                _path.pop_back();
                return;
            }
            else{
                return;
            }
        }
        else{
            //非叶节点
            _path.emplace_back(_node->val);
            //左
            findPaths(_node->left, _target - _node->val, _path, _results);
            //右
            findPaths(_node->right, _target - _node->val, _path, _results);
            //释放节点
            _path.pop_back();
            return;
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //干翻字节！
        //加油，明天好运
        //递归，参数传值
        //很熟练，很好，十分钟，时间击败-85.30%，空间击败-30.03%
        vector<vector<int>> results;    //结果
        vector<int> temp;   //每条路径的暂存值
        //递归＋回溯
        if(root == nullptr){
            return results;
        }
        else{
            findPaths(root, targetSum, temp, results);
            return results;
        }
    }
};
