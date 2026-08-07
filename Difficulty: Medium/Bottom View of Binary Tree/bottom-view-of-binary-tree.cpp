/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  vector<int> res;
  map<int,int> nodes;
  
  void bfs(Node *root)
  {
      if(!root) return;
      queue<pair<Node*,int>> q;
      
      q.push({root,0});
      
      while(!q.empty())
      {
          Node* t=q.front().first;
          int axis=q.front().second;
          q.pop();
          
          nodes[axis]=t->data;
          
          if(t->left) q.push({t->left,axis-1});
          if(t->right) q.push({t->right,axis+1});
      }
  }
    vector<int> bottomView(Node *root) {
        // code here
        bfs(root);
        
        for(auto i : nodes)
        {
            res.push_back(i.second);
        }
        return res;
    }
};