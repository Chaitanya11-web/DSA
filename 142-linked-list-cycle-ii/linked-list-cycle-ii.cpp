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
ListNode * findCycle(ListNode * head,ListNode * fast){
    ListNode *slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    } 
    return slow;
}
    ListNode *detectCycle(ListNode *head) {
        ListNode * head1=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return findCycle( head,fast);
            }
        }
        return NULL;
    }
};