/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    Node * prev;    //前序节点
    Node * head;    //头节点
    void inorderDfs(Node * node){
        if(node == nullptr){
            return;
        }
        //中序遍历
        inorderDfs(node->left);
        //处理这个节点
        if(prev == nullptr){
            //在处理第一个节点
            head = node;
        }
        else{
            prev->right = node;
        }
        node->left = prev;
        prev = node;
        inorderDfs(node->right);
    }

public:
    Node* treeToDoublyList(Node* root) {
        //干翻蚂蚁金服！
        //一个节点是左指针，指向左子树的最右子节点，如果存在，不存在的话就
        //指向左子树
        //右指针指向右子树的最左子节点，如果不存在，就指向父节点的父节点
        //可以递归着做
        //先弄到头节点
        //看了题解，太强了，要用中序遍历的性质呀
        /*
        Node * head = new Node(0);
        head = root;
        while(head->left){
            head = head->left;
        }
        //递归处理每个节点
        transfer(root);
        return head;
        */
        prev = nullptr;
        if(root == nullptr){
            return root;
        }
        inorderDfs(root);
        //关联头尾
        prev->right = head;
        head->left = prev;
        return head;
    }
};
