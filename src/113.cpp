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
    /*
    深度优先遍历，递归，保留上层路径
    time defeat: 8.17%
    space defeat: 5.06%
    */
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result; //结果数组 
        vector<int> temp;   //暂存每条路径上数值的数组
        vector<vector<int>> paths;  //遍历路径数组，用来去重
        vector<int> nowPath;    //保存单条路径的数组
        //极端情况
        if(root == NULL){
            return result;
        }
        nowPath.emplace_back(0);    //路径压入根节点
        recDfsFind(result, temp, root, sum, paths, nowPath);    //开始递归
        return result;
    }
    
    //const为了提高效率，& 为了能够直接修改参数
    void recDfsFind(vector<vector<int>>& _result, const vector<int> _nowResult, const TreeNode* _node, const int _target, vector<vector<int>>& _paths, const vector<int> _nowPath){
        if(_node == NULL){
            return;
        }
        else if(_node->left == NULL && _node->right == NULL){
            vector<int> nowResult = _nowResult;
            nowResult.emplace_back(_node->val);
            //找到一条路径
            if(accumulate(nowResult.begin(), nowResult.end(), 0) == _target){
                if(count(_paths.begin(), _paths.end(), _nowPath) == 0){
                    _result.emplace_back(nowResult);
                }
            }
            return;
        }
        else{
            vector<int> nowResult = _nowResult;
            nowResult.emplace_back(_node->val);
            vector<int> nowPath = _nowPath;
            nowPath.emplace_back(1);
            recDfsFind(_result, nowResult, _node->left, _target, _paths, nowPath);
            nowPath.pop_back();
            nowPath.emplace_back(2);
            recDfsFind(_result, nowResult, _node->right, _target, _paths, nowPath);
            return;
        }
    }
};
