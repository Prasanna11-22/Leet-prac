/*
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};
*/

class Solution {
	public:
	
	map<int, int> nodes;
	vector<int> res;
	
	void levord(Node* root)
	{

		if (!root)
			return;
		
		queue<pair<Node*, int>> q;
		
		q.push({root, 0});
		
		while (!q.empty())
			{
			
			Node* t = q.front().first;
			int axis=q.front().second;
			q.pop();
			
			if (nodes.find(axis) == nodes.end())
			{
				nodes[axis] = (t->data);
			}
			
			if (t->left)
				q.push({t->left, axis - 1});
			if (t->right)
				q.push({t->right, axis + 1});
			
		}
	}

vector<int> topView(Node *root) {
	levord(root);
	
	for (auto i : nodes)
		{
		res.push_back(i.second);
	}
	return res;
}
};
