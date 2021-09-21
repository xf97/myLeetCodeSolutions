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
    //脑子确实不太转，爷懂了
    //题目保证树中节点值互不相同
    unordered_map<int, TreeNode *> parents;
    vector<int> result;

    void findParent(TreeNode * node){
        //从父节点的角度来找子节点，就不用记录上一节点 
        //不会压入空节点
        if(node->left){
            parents[node->left->val] = node;
            findParent(node->left);
        }
        if(node->right){
            parents[node->right->val] = node;
            findParent(node->right);
        }
    }

    void getResult(TreeNode * node, TreeNode * from, int distance, int k){
        if(node ==  nullptr){
            return;
        }
        if(distance == k){
            result.push_back(node->val);    //要避免重复压入
        }
        //因为会有从子往上的，所以要考察来源
        if(node->left != from){
            getResult(node->left, node, distance + 1, k);
        }
        if(node->right != from){
            getResult(node->right, node, distance + 1, k);
        }
        if(parents[node->val] != from){
            getResult(parents[node->val], node, distance + 1, k);   //从下向上的
        }
        return;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //看了题解，自己实现
        //时间击败-48.95%，空间击败-60.31%
        findParent(root);   
        getResult(target, nullptr, 0, k);
        return result; 
    }
};
