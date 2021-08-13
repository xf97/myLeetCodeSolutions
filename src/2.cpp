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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //想要做一种偷鸡做法，但是一看长度最长为100，偷鸡还得转成字符串
        //就有点麻烦了
        //干翻腾讯CSIG
        //还是模拟把
        //注意进位，注意不等长情况
        //边界处理，虽然看起来没用
        //二十分钟，两次提交，时间击败-45.15%，空间击败-18.44%
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        int carry = 0;  //进位
        ListNode * p1 = l1;
        ListNode * p2 = l2; //遍历指针
        //需要新建链表
        ListNode * fakeHead = new ListNode(0);
        ListNode * temp = fakeHead;
        //当两个都有的时候
        while(p1 && p2){
            int sum = p1->val + p2->val + carry;
            carry = sum / 10;   //更新进位
            sum %= 10;  //去掉进位
            //新建节点
            ListNode * node = new ListNode(sum);
            //连入链表
            temp->next = node;
            temp = node;
            //推进指针
            p1 = p1->next;
            p2 = p2->next;
        }
        //当一个链表推进完时
        //让p1指向未完链表
        p1 = (p2 == nullptr) ? p1 : p2;
        //看看有没有进位
        if(carry == 0){
            //没有的话，直接连入
            temp->next = p1;
        }
        else{
            //有进位，处理
            while(carry && p1){
                int sum = p1->val + carry;
                carry = sum / 10;
                sum %= 10;
                ListNode * node = new ListNode(sum);
                temp->next = node;
                temp = node;
                p1 = p1->next;
            }
            //如果还有进位
            if(carry){
                ListNode * node = new ListNode(carry);
                temp->next = node;
                temp = node;    
            }
            else{
                //如果没有了
                temp->next = p1;
            }
        }
        return fakeHead->next;
    }
};
