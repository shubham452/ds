#include <bits/stdc++.h>
using namespace std;
struct Node {
   int data;
   struct Node *left;
   struct Node *right;
};
struct Node *
newNode (int data) {
   struct Node *node = new Node;
   node->data = data;
   node->left = node->right = NULL;
   return (node);
}
/*struct Detail {
   int size;
   int max;
   int min;
   int ans;
   bool isBST;
};*/

bool isBST (Node * root, int min, int max) {
   if (root == NULL) {
      return true;
   }
   if (root->data < min || root->data > max) {
      return false;
   }
   return isBST (root->left, min, root->data - 1) &&
   isBST (root->right, root->data + 1, max);
}
int size (Node * root) {
   if (root == NULL) {
      return 0;
   }
   return 1 + size (root->left) + size (root->right);
}
int largestBST (Node * root) {
   // Current Subtree is BST.
   if (isBST (root, INT_MIN, INT_MAX) == true) {
      return size (root);
   }
   // Find largest BST in left and right subtrees.
   return max (largestBST (root->left), largestBST (root->right));
}
int main () {
   struct Node *root = newNode (67);
   root->left = newNode (72);
   root->right = newNode (77); root->left->left = newNode (57);
   /* struct Node *root;
    root=newNode(20);
    root->left=newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);*/
   printf ("Size of the largest BST is %d", largestBST (root));
   return 0;
}