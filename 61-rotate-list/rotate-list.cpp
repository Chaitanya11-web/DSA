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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 ||head==NULL)return head;
     ListNode* lastNode=head;
      ListNode* temp=head;
      int count=1;
      while(lastNode->next!=NULL){
        count++;
        lastNode=lastNode->next;
      }
      k=k%count;
      if(k==0)return head;
      count=count-k;
      while(count!=1){
        temp=temp->next;
        count--;
      }
 
      ListNode* newHead=temp->next;
           temp->next=NULL;
      lastNode->next=head;
      return newHead;
    }
};