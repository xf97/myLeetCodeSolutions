/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    //我开始膨胀到要做困难题了
    //挺艰难的，虽然通过了，但做了1个小时
    //时间击败：5.35%，空间击败：38.04%
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //通过前序遍历序列化二叉树
        //要处理空节点，空节点记为字符串null
        //递归
        string result = "[";
        if(root == nullptr){
            result += "]";
            return result;
        }
        else{
            //启动递归
            serializeCore(root, result);
            result += "]";
            return result;
        }
    }

    void serializeCore(const TreeNode * _node, string & _str){
        //处理空节点
        if(_node == nullptr){
            _str += "null,";
            return;
        }
        else{
            //否则，前序遍历
            _str += (to_string(_node->val) + ",");
            serializeCore(_node->left, _str);
            serializeCore(_node->right, _str);
            return;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //根据前序遍历，反序列化回来
        //仍然是递归，根据前序遍历的性质
        //初始化根节点
        TreeNode * root = nullptr;
        if(data == "[]"){
            //空树
            return root;
        }
        else{
            //递归向下，要有指向指针的指针
            //对字符串进行一些处理，去除头尾[]，然后逗号分隔
            string temp = data.substr(1, data.size() - 2);
            deserializeCore(&root, temp);
            return root;
        }
    }

    void deserializeCore(TreeNode ** _node, string & _str){
        //读出数字时返回true，读出null时返回false
        int value = 0;
        if(read1ValidNode(_str, value)){
            //_str已经截断
            //已经获取了值，现在，赋值新节点
            *_node = new TreeNode();
            (*_node)->val = value;
            (*_node)->left = nullptr;
            (*_node)->right = nullptr;
            //向下继续前序遍历
            deserializeCore(&((*_node)->left), _str);
            deserializeCore(&((*_node)->right), _str);
            return;
        }
    }

    bool read1ValidNode(string & _nodeValue, int & _value){
        if(_nodeValue == ""){
            return false;
        }
        string temp = "";
        int i = 0;
        for(; i < _nodeValue.size(); i ++){
            if(_nodeValue[i] == ','){
                break;
            }
            temp += _nodeValue[i];
        }
        //截断
        if(i < _nodeValue.size()){
            _nodeValue = _nodeValue.substr(i + 1);
        }
        else{
            _nodeValue = "";
        }
        if(temp == "null"){
            return false;
        }
        else{
            _value = atoi(temp.c_str());
            return true;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
