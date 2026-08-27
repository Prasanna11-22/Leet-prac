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
ListNode* reverse(ListNode* head,int k ,ListNode* prevhead)
{
    ListNode* prev=prevhead;
    ListNode* curr=head;
    ListNode* nxt=head;

    while(curr&&k>0)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        k--;
    }

    return prev;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* t=head;
        for(int i=0;i<k;i++)
        {
            if(!t) return head;
            t=t->next;
        }

        ListNode* nxthead=reverse(head,k,nxthead);

        head->next= reverseKGroup(t,k);

        return nxthead;

        
    }
};