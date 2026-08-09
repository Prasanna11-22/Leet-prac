class Solution {
public:

ListNode* reverselink(ListNode* head,int k,ListNode* nexhead)
{
    ListNode* prev=nexhead;
    ListNode* curr=head;
    ListNode* nex=head;

    while(curr&&k>0)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        k--;
    }

    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;

        ListNode* t=head;
       
   //nullptr;
        for(int i=0;i<k;i++)
        {
            if(!t)
            {
                return head;
            }
            t=t->next;
        }

        ListNode* nexhead=reverselink(head,k,t);
        
       head->next=reverseKGroup(t,k);

        return nexhead;
    }
};