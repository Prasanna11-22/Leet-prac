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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       if(!head) return nullptr;
       
        set<int> s(nums.begin(),nums.end());
        ListNode* t=new ListNode(0,head);
        ListNode* prev=t;
        ListNode* temp=t->next;

       while(temp)
       {
        if(s.find(temp->val)!=s.end())
        {
            prev->next=temp->next;

            if((temp->next)&&(s.find(temp->val)==s.end()))
            prev=temp->next;
        }
        else prev=temp;
        temp=temp->next;
       }

        return t->next;
    }
};