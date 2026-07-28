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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp=head;
        stack<ListNode*> st;
        while(temp!=NULL){
            st.push(temp);
            
        cout<<"Added to Stack :"<<temp->val<<endl;
        temp=temp->next;
        }
        
        head=temp=st.top();
        cout<<"Stack completed top -> "<<temp->val<<endl;
        // ListNode* node=st.top();
        st.pop();
        while(!st.empty()){
            temp->next=st.top();
            st.pop();
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
    }
};
