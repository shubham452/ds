Construct Binary Tree from Parent Array

https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1

class Solution {
  public:
    Node* createTree(vector<int>& parent) {
        // code here
        int n=parent.size();
        vector<Node*> node(n);
        for(int i=0;i<n;i++)
        {
            node[i] = new Node(i);
        }
        Node *root = NULL;
        
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
            {
                root= node[i];
            }
            else
            {
                Node *p= node[parent[i]];
                if(!p->left)
                {
                    p->left=node[i];
                }
                else if(!p->right)
                {
                    p->right=node[i];
                }
            }
            
        }
        return root;
    }
};
---------------------------------------------------------------------------------
