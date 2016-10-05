

int maxDepth(treenode* A) {

    if (A == NULL) return 0;
    
    
    int l = maxDepth(A->left);
    int r = maxDepth(A->right);
    int max = (l >= r) ? l : r;
    
    return 1 + max;


}
