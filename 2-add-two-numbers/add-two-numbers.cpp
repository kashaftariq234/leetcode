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
    /*ListNode* reverse(ListNode* head){
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }*/
    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    ListNode* add(ListNode* first, ListNode* second){
        int carry =0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        while(first != NULL || second != NULL || carry != 0){
            int val1 =0;
            if(first != NULL){
                val1 = first -> val;
            }
            int val2 =0;
            if(second != NULL){
                val2 = second -> val;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertAtTail( ansHead, ansTail , digit);
            carry = sum /10 ;
            if(first != NULL){
                first = first -> next;
            }
            if(second != NULL){
                second = second -> next;
            }
        }
          return ansHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //first reverse
       // l1 = reverse(l1);
        //l2 = reverse(l2);
        //add the sum
        ListNode* ans = add(l1 , l2);
        //ans = reverse(ans);
        return ans;
    }
};