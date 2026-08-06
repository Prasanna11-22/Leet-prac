class Solution {
public:
   vector<int> res;
   unordered_map<int,int> mp;

void inord(TreeNode* root)
{
    if(!root) return;

    inord(root->left);
     mp[root->val]++;
    inord(root->right);
}
   
    vector<int> findMode(TreeNode* root) {
     inord(root);
     vector<int> ans;

    int maxival=-1e9;
    int maxifreq=-1e9;
     for(auto i : mp)
     {
       int mp1=i.first;
        int mp2=i.second;
        if(maxifreq<=mp2)
        {
        if(maxifreq==mp2)
        {
             ans.push_back(mp1);
        }
        else
        {
            ans.clear();
            ans.push_back(mp1);
        }
        maxival=mp1;
        maxifreq=mp2;
        }
     }
        return ans;
    }
};