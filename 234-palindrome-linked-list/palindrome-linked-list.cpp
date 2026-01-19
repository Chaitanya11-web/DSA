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
    bool isPalindrome(ListNode* head) {
        bool ans=true;
        ListNode* temp=head;
        ListNode* curr=head;
        ListNode* fut=NULL;
         ListNode* prev=NULL;
        int count=0;
        while(temp!=NULL){
temp=temp->next;
count++;
        }
        
        count=count/2;
        int k=count;
        while(count!=0){
            curr=curr->next;
            count--;
        }
        while(curr!=NULL){
fut=curr->next;
curr->next=prev;
prev=curr;
curr=fut;
        }
    ListNode* head1=head;
     ListNode* head2=prev;    
for(int i=0;i<k;i++){
    if(head1->val!=head2->val){
        ans=false;
        return false;
    }
    else{
        head1=head1->next;
        head2=head2->next;
        ans=true;
    }
    
}
return ans;
    }
};