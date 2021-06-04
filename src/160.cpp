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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //先统一长度，时间复杂度On
        //十分钟，一次提交，时间击败-67.58%，空间击败-47.79%
        //边界情况
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }
        else{
            //遍历
            int lengthA = 0;
            int lengthB = 0;
            ListNode * pointA = headA;
            ListNode * pointB = headB;
            while(pointA != nullptr || pointB != nullptr){
                if(pointA != nullptr){
                    lengthA ++;
                    pointA = pointA->next;
                }
                if(pointB != nullptr){
                    lengthB ++;
                    pointB = pointB->next;
                }
            }
            //挪动头指针
            //cout<<lengthA<<" "<<lengthB<<endl;
            while(lengthA > lengthB){
                headA = headA->next;
                lengthA --;
            }
            while(lengthB > lengthA){
                headB = headB->next;
                lengthB --;
            }
            //cout<<lengthA<<"***"<<lengthB<<endl;
            //然后开始寻找相交
            while(headA != nullptr && headB != nullptr){
                if(headA == headB){
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
            return nullptr;
        }
    }
};
