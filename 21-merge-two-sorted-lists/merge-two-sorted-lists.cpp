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
void f(ListNode*nhead,ListNode*h1,ListNode*h2)
{
    if(!h1&&!h2)return;
    if(!h1&&h2)
    {
        ListNode*t=new ListNode(h2->val);
        nhead->next=t;
        nhead=nhead->next;
        f(nhead,h1,h2->next);
    }
   else if(h1&&!h2)
    {
        ListNode*t=new ListNode(h1->val);
        nhead->next=t;
        nhead=nhead->next;
        f(nhead,h1->next,h2);
    }
    else
    {
        if(h1->val<h2->val)
        {
         ListNode*t=new ListNode(h1->val);
        nhead->next=t;
        nhead=nhead->next;
        f(nhead,h1->next,h2);
        }
        else 
        {
        ListNode*t=new ListNode(h2->val);
        nhead->next=t;
        nhead=nhead->next;
        f(nhead,h1,h2->next);
        }
       
    }
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
               ListNode* nhead=new ListNode();
       ListNode*t= nhead;
       f(nhead,list1,list2);
        return t->next;

    }
};