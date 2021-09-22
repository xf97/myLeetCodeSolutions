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
class BSTIterator {
private:
    //十分钟，一次提交，时间击败-39.07%，空间击败-46.98%
    int length; //树中节点数量
    int index;  //当前指向 
    vector<int> val;    //节点值

    void inorderDfs(const TreeNode * node){
        if(node == nullptr){
            return;
        }
        //中序
        inorderDfs(node->left);
        val.push_back(node->val);
        inorderDfs(node->right);
        return;
    }

public:
    BSTIterator(TreeNode* root) {
        //中序遍历开始
        val.push_back(-1);  //推入首元素
        inorderDfs(root);
        length = val.size();
        index = 0;
    }
    
    int next() {
        return val[++index];
    }
    
    bool hasNext() {
        return index < length - 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
