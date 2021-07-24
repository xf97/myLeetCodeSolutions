/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode * re_BuildTree(const vector<int> & _preOrder, const vector<int> _inOrder, int _preLeft, int _preRight, int _inLeft, int _inRight){
        //递归构造，每次就构造一个节点
        //递归边界
        if(_preLeft > _preRight){
            //等于不行，等于指向同一个节点
            return nullptr;
        }
        //构造根节点
        TreeNode * node = new TreeNode(_preOrder[_preLeft]);
        //要知道左子树的长度
        int rootIndex = find(_inOrder.begin(), _inOrder.end(), _preOrder[_preLeft]) - _inOrder.begin();
        int leftSubTreeLength = rootIndex - _inLeft;
        //划分左右子树
        node->left = re_BuildTree(_preOrder, _inOrder, _preLeft + 1, _preLeft + leftSubTreeLength, _inLeft, _inLeft + leftSubTreeLength);
        node->right = re_BuildTree(_preOrder, _inOrder, _preLeft + leftSubTreeLength + 1, _preRight, _inLeft + leftSubTreeLength + 1, _inRight);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //从前序和中序遍历构造二叉树
        //挺麻烦这题，难倒不难，从前向后遍历前序，在中序中确定他的位置以及后两个元素的关系
        //前序遍历(根，根的左子，根的右子)
        //中序遍历(根的左子，根，根的右子)
        //干翻字节
        //用递归方便一点
        //为了避免参数的值拷贝，使用参数确定位置
        //二十分钟，一次提交，时间击败-44.96%，空间击败-6.95%
        //题目保证树里面的值互不相同
        return re_BuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
