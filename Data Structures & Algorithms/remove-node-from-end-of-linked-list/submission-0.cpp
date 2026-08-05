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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head, *cur=head;
        int k=n;
        while(k-- && temp!=NULL){
            temp=temp->next;
        }
        if(temp==NULL){
            head=head->next;
            return head;
        }
        while(temp!=NULL && temp->next!=NULL){ 
            cur=cur->next;
            temp=temp->next;
        }
        
        cur->next=cur->next->next;
        return head;
    }
};
