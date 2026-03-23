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
    ListNode* deleteMiddle(ListNode* head) {
       
        int cnt=0;
      ListNode* temp=head;
      while(temp!=NULL){
        temp=temp->next;
        cnt++;
      }  
      cnt=cnt/2;
      if(cnt==0)return NULL;
      ListNode* curr=head;
      while(cnt!=1){
curr=curr->next;
cnt--;
      }
      temp=curr->next;
      curr->next=temp->next;
      delete temp;
      return head;
    }
};