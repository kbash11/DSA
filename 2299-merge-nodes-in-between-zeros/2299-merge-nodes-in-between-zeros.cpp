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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev=head->next;
        ListNode* curr=head->next;
        int sum=0;
        while(curr!=NULL){
            sum+=curr->val;
            if(curr->val==0){
                prev->val=sum;
                sum=0;
                if(curr->next){
                    prev->next=NULL;
                    prev->next=curr->next;
                    prev=curr->next;
                }else{
                    prev->next=NULL;
                }
            }
            curr=curr->next;
        }
        return head->next;
        
    }
};