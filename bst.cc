#include <iostream>

using namespace std;

struct BSTNode {

  int data;
  BSTNode *left;
  BSTNode *right;
};


BSTNode* getNewNode (int data) {

  BSTNode *newNode = new BSTNode ();
  newNode->data = data;
  newNode->left = newNode->right = NULL;

  return newNode;

}


BSTNode* insert (BSTNode* root, int data) {


  if (root == NULL) {

    root = getNewNode(data);

  } else if (data <= root->data) {
    
    root->left = insert(root->left,data);

  } else {

    root->right = insert(root->right,data);
  }


  return root;
}


bool search (BSTNode* root, int data) {

  if (root == NULL) return false;
  
  if (root->data == data) return true;

  if (data <= root->data) 
    return search(root->left,data);
  else
    return search(root->right,data);

}



int maxDepth(BSTNode* A) {

    if (A == NULL) return 0;
    
    
    int l = maxDepth(A->left);
    int r = maxDepth(A->right);
    int max = (l >= r) ? l : r;
    
    return 1 + max;


}


void preorder (BSTNode* root) {

  if (root == NULL) return;

  cout << root->data << " ";
  preorder (root->left);
  preorder (root->right);

}

void inorder (BSTNode* root) {

  if (root == NULL) return;

  inorder (root->left);
  cout << root->data << " ";
  inorder (root->right);

}

void postorder (BSTNode* root) {

  if (root == NULL) return;

  postorder (root->left);
  postorder (root->right);
  cout << root->data << " ";

}


int main () {


  BSTNode *root;
  root = NULL;

  root = insert (root,15);
  root = insert (root,10);
  root = insert (root,20);
  root = insert (root,25);
  root = insert (root,8);
  root = insert (root,12);


  cout << "searching for 15  " << search(root,15) << endl;
  cout << "searching for 25 " << search(root,25) << endl;
  cout << "searching for 9 " << search(root,9) << endl;
  cout << "searching for 12 " << search(root,12) << endl;
  cout << "searching for 13 " << search(root,13) << endl;

  cout << "max Depth: " << maxDepth(root) << endl;

  cout << "Printing in preorder: ";
  preorder(root);
  cout << endl;

  cout << "Printing in inorder: ";
  inorder(root);
  cout << endl;

  cout << "Printing in postorder: ";
  postorder(root);
  cout << endl;


  return 0;
}
