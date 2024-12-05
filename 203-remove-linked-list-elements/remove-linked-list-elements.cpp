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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL) return head;
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode* nodek=temp;

        while(temp!=NULL){
            if(temp->next!=NULL && temp->next->val==val){
                ListNode* node=temp->next;
                while(node!=NULL && node->val==val) node=node->next;
                if(node==NULL) temp->next=NULL;
                else {
                temp->next=node;
                temp=temp->next;
                }
            }else temp=temp->next;
        }
        return nodek->next;
    }
};