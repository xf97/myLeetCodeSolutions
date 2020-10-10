/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//time defeat: shijiantaichangle,kanbuchulaijibaileduoshao
//space defeat: 17%
//time consuming: less than 6 mins
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //特殊情况
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        else{
            //否则，开始检测环
            vector<ListNode *> appearNode;  //已出现过的节点数组
            appearNode.emplace_back(head);
            ListNode* nowNode = head->next;
            //开始遍历节点
            while(nowNode != NULL){
                if(find(appearNode.begin(), appearNode.end(), nowNode) != appearNode.end()){
                    return nowNode; //找到入环的第一个节点
                }
                else{
                    appearNode.emplace_back(nowNode);
                    nowNode = nowNode->next;
                }
            }
            return nowNode;
        }
    }
};
