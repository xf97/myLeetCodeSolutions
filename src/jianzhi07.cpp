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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //今日第二次膨胀 (指第二次触碰中等题)
        //看看40分钟能不能剑指出来
        //利用性质, 从前到后遍历前序，然后找到最前节点在中序中的位置，划分左右子树，递归向下
        //边界条件
        /*
        time defat: 43.12%
        space defeat: 93.59%
        */
        if(preorder.size() == 0 || inorder.size() == 0){
            return nullptr;
        }
        //异常值
        else if(preorder.size() != inorder.size()){
            return nullptr;
        }
        else{
            return buildTreeCore(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
        }
    }

    TreeNode * buildTreeCore(const vector<int> & _pre, const vector<int> & _in, const int _preS, const int _preE, const int _inS, const int _inE){
        //首先，构造本次的根节点
        TreeNode * node = new TreeNode(_pre[_preS]);
        node->left = node->right = nullptr;

        //然后，检查是否递归完成
        if(_preS == _preE && _inS == _inE){
            return node;
        }

        //然后，找到本次根节点在中序中的位置
        int i = _inS;
        for(; i <= _inE; i++){
            if(_in[i] != _pre[_preS]){
                continue;
            }
            else{
                break;
            }
        }

        //计算左子树长度
        int leftLen = i - _inS;
        //然后划分左右子树
        //左子树存在
        if(leftLen > 0){
            node->left = buildTreeCore(_pre, _in, _preS + 1, _preS + leftLen, _inS, i - 1);
        }
        //右子树存在
        if(_preS + leftLen < _preE){
            node->right = buildTreeCore(_pre, _in, _preS + leftLen + 1, _preE, i + 1, _inE);
        }
        return node;
    }
};
