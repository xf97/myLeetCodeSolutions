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
    TreeNode * constructTree(const vector<int> & _inorder, int _iLeft, int _iRight, const vector<int> & _posterorder, int _pLeft, int _pRight){
        //递归构造
        //递归边界
        if(_iLeft > _iRight){
            return nullptr;
        }
        //先构造根节点
        TreeNode * node = new TreeNode(_posterorder[_pRight]);
        //区分左右子树
        //题目保证数字不重复
        int nodeIndex = find(_inorder.begin(), _inorder.end(), _posterorder[_pRight]) - _inorder.begin();
        int leftSubTreeLength = nodeIndex - _iLeft;
        //cout<<_posterorder[_pRight]<<_iLeft<<_iRight<<_pLeft<<_pRight<<endl;
        //向下构造
        node->left = constructTree(_inorder, _iLeft, _iLeft + leftSubTreeLength - 1, _posterorder, _pLeft, _pLeft + leftSubTreeLength - 1);
        node->right = constructTree(_inorder, _iLeft + leftSubTreeLength + 1, _iRight, _posterorder, _pLeft + leftSubTreeLength, _pRight - 1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //同样的构建方法
        //干翻蚂蚁链
        //中序遍历，[左子树，根，右子树]
        //后序遍历[左，右，根]
        //通过参数指针，避免参数出现多次拷贝
        //草了，因为一个参数卡了半天，
        //二十五分钟，一次提交，时间击败--88.91%，空间击败-74.79%
        TreeNode * root = constructTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        return root;
    }
};
