/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int mindiff=1e9;
bool flag=0;
void inod(TreeNode* root,int &prev,int &mindiff)
{
    if(!root) return;

    inod(root->left,prev,mindiff);
    if(flag==0)
    {
        prev=root->val;
        flag=1;
    }
    else
    {
    int diff=(root->val)-prev;
    if(diff<mindiff)
    {
        mindiff=diff;
    }
    prev=root->val;
    }
    inod(root->right,prev,mindiff);

}

    int minDiffInBST(TreeNode* root) {
        int prev=1e9;
    inod(root,prev,mindiff);
     return mindiff;
}

};