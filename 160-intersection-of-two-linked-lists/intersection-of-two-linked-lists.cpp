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
      ListNode * temp=headA;
      ListNode * currA=headA;
      ListNode * currB=headB;
      int cnt1=0;
      int cnt2=0;
      while(temp!=NULL){
temp=temp->next;
cnt1++;
      }
      temp=headB;
      while(temp!=NULL){
        temp=temp->next;
        cnt2++;
      } 
     if(cnt1>cnt2){
        while(cnt1>cnt2){
            currA=currA->next;

cnt1--;
        }
     }
     else{
        while(cnt1<cnt2){
           
            currB=currB->next;
            cnt2--;
        }
     }
     while(currA!=currB){
        currA=currA->next;
        currB=currB->next;
     }
return currA;
    }
};