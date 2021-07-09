/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int childDepth(struct TreeNode* root,int depth){
    if(root == NULL) return depth;
    int leftDepth = childDepth(root->left,depth+1);
    int rightDepth = childDepth(root->right,depth+1);
    return leftDepth>rightDepth?leftDepth:rightDepth;
    
}

int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    int leftDepth = childDepth(root->left,1);
    int rightDepth = childDepth(root->right,1);
    return leftDepth>rightDepth?leftDepth:rightDepth;

}
int maxDepth(struct TreeNode* root){

    if(!root) return 0;
    
    int d = 1;
    int max_left = maxDepth(root->left);
    int max_right = maxDepth(root->right);
    d += (max_left>max_right)?max_left:max_right;
    return d;
    
}
