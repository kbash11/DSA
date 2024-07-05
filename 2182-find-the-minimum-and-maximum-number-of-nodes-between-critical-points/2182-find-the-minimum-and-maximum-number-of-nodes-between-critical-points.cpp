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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==NULL){
            return {-1,-1};
        }
        vector<int> arr;
        ListNode* prev=head;
        ListNode* curr=head->next;
        int ind=1;
        while(curr->next){
            if((curr->next->val >curr->val && prev->val > curr->val) || (curr->next->val < curr->val && prev->val < curr->val)){
                arr.push_back(ind);
            }
            prev=curr;
            curr=curr->next;
            ind++;
        }
        if(arr.size()<2){
            return {-1,-1};
        }
        int maxi=arr[arr.size()-1]-arr[0];
        int mini=INT_MAX;
        for(int i=1;i<arr.size();i++){
            mini=min(mini,arr[i]-arr[i-1]);
        }
        return {mini,maxi};
    }
};