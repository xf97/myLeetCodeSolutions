/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode *> appearNode;
        if(head == NULL || head->next == NULL){
            return false;
        }
        else{
            appearNode.emplace_back(head);
            auto nowNode = head->next;
            while(nowNode != NULL){
                if(find(appearNode.begin(), appearNode.end(), nowNode) != appearNode.end()){
                    //出现环
                    return true;
                }
                else{
                    appearNode.emplace_back(nowNode);
                    nowNode = nowNode->next;
                }
            }
        }
        return false;
    }
};
