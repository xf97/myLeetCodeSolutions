/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //中等题，先用简单方法，时间复杂度会比较高
        //先复制基础版链表，再复制随机节点
        //靠，一次提交就过了
        //时间击败：28.06%，空间击败：83.38%
        if(head == nullptr){
            return head;
        }
        else{
            Node * newHead =  new Node(head->val);
            //遍历Node
            Node * preNode = newHead;
            Node * temp = head->next;
            while(temp != nullptr){
                Node * newNode = new Node(temp->val);
                preNode->next = newNode;
                temp = temp->next;
                preNode = preNode->next;
            }
            //然后，再次遍历链表，为随机节点复制
            Node * newTemp = newHead;
            temp = head;
            while(temp != nullptr){
                //获取随机节点
                Node * randomNode = temp->random;
                if(randomNode == nullptr){
                    newTemp->random = nullptr;
                    temp = temp->next;
                    newTemp = newTemp->next;
                }
                else{
                    //在新节点中，找到对应的随机节点
                    Node * tempNewRandom = newHead;
                    Node * tempRandom = head;
                    while(tempRandom != randomNode){
                        tempRandom = tempRandom->next;
                        tempNewRandom = tempNewRandom->next;
                    }
                    newTemp->random = tempNewRandom;
                    temp = temp->next;
                    newTemp = newTemp->next;
                }
            }
            return newHead;
        }
    }
};
