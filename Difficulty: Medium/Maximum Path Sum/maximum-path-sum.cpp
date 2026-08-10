/* Structure of binary tree node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
int maxi=INT_MIN;
  
int rec(Node* root)
{
    if(!root) return 0;
    
    int l=max(0,rec(root->left));
    int r=max(0,rec(root->right));
    
    maxi=max(maxi,l+r+root->data);
    
    return max(l,r)+root->data;
    
}
    int findMaxSum(Node *root) {
        // code here
        maxi=root->data;
        rec(root);
        return maxi;
    }
};