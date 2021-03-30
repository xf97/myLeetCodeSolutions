class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        //中等题，估计半个小时做出来
        //要利用后序遍历的性质，从后往前，逐个分割左右子树
        //再递归判断
        //注意，二叉搜索树，左子树的值都比根小，右子树的值都比根大
        //根据以上性质分割左右子树
        //边界情况及递归终止条件
        //35分钟，三次提交完成，时间击败：100%，空间击败：9.38%
        /*
        for(const auto & i: postorder){
            cout<<i<<" ";
        }
        cout<<endl;
        */
        int len = postorder.size();
        if(len <= 1){
            return true;
        }
        else{
            //所有数字互不相同，没有等于情况
            //找左子树
            int rootValue = postorder.back();   //根植
            int leftTree = 0;
            //不可能超限，因为必然等于最后一位
            while(postorder[leftTree] < rootValue){
                leftTree ++;
            }
            //然后去找右子树
            int rightTree = leftTree;
            while(rightTree < len - 1){
                if(postorder[rightTree] <= rootValue){
                    return false;
                }
                rightTree ++;
            }
            //cout<<leftTree<<" "<<rightTree<<endl;
            //左右子树都符合，那么切分左右子树，继续向下
            bool result = true;
            if(leftTree > 0){
                //有左子树，切分向下
                vector<int> leftTreePostOrder(postorder.begin(), postorder.begin() + leftTree);
                result = verifyPostorder(leftTreePostOrder);
            }
            if(rightTree == len - 1 && rightTree != leftTree && result == true){
                //有右子树，切分向下
                //cout<<"haha"<<endl;
                vector<int> rightTreePostOrder(postorder.begin() + leftTree, postorder.end() - 1);
                result = verifyPostorder(rightTreePostOrder);
            }
            return result;
        }
    }
};
