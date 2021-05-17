/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        //下班了，赶紧整完
        //两分钟，一次提交，时间击败-41.32%，空间击败-32.88%
        vector<int> result;
        if(root == nullptr){
            return result;
        }
        else{
            preDfs(root, result);
            return result;
        }
    }

    void preDfs(const Node const * _node, vector<int> & _value){
        if(_node == nullptr){
            return;
        }
        else{
            _value.emplace_back(_node->val);
            for(auto child : _node->children){
                preDfs(child, _value);
            }
            return;
        }
    }
};
