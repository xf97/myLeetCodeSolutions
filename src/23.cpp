/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode * merge2Lists(ListNode * _node1, ListNode * _node2){
        //假头节点
        ListNode * fakeHead = new ListNode();
        ListNode * node = fakeHead;
        while(_node1 && _node2){
            //两个表不为空时合并
            if(_node1->val < _node2->val){
                //升序合并
                node->next = _node1;
                node = node->next;
                _node1 = _node1->next;
            }
            else{
                node->next = _node2;
                node = node->next;
                _node2 = _node2->next;
            }
        }
        //处理多出来的节点
        if(_node1){
            while(_node1){
                node->next = _node1;
                node = node->next;
                _node1 = _node1->next;
            }
        }
        if(_node2){
            while(_node2){
                node->next = _node2;
                node = node->next;
                _node2 = _node2->next;
            }
        }
        return fakeHead->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //这个题，感觉不应该是个困难题
        //我俩俩合并就好了
        //时间复杂度On2，空间O1，原地合并
        //干翻字节！
        //十五分钟，这个困难题有点简单
        //一次提交，时间击败-14.12%，空间击败-60.12%
        ListNode * newHead = nullptr;   //合并后头节点
        for(int i = 0; i < lists.size(); ++ i){
            newHead = merge2Lists(newHead, lists[i]);
        }
        return newHead;
    }
};
