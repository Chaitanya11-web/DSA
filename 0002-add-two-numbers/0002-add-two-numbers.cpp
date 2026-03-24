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
      ListNode* head1=l1;
      ListNode* head2=l2;
      ListNode* dummy=new ListNode(0);
      ListNode* tail=dummy;
      int carry=0;
      int sum=0;
      while(head1!=NULL || head2!=NULL || carry!=0){
        if(head1!=NULL){
            sum+=head1->val;
            head1=head1->next;
        }
        if(head2!=NULL){
            sum+=head2->val;
            head2=head2->next;
        }
        if(carry!=0){
            sum+=carry;
        }
ListNode* newNode=new ListNode(sum%10);
carry =sum/10;
sum=0;
tail->next=newNode;
tail=tail->next;
      }  
      return dummy->next;
    }
};