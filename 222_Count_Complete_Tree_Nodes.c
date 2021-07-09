int countLeft(struct TreeNode* root){
    if(root == NULL) return 0;
    return countLeft(root->left) + 1;
}
int countRight(struct TreeNode* root){
    if(root == NULL) return 0;
    return countRight(root->right) + 1;
}
int countNodes(struct TreeNode* root){
    if(root == NULL) return 0;
    int l,r;
    l = countLeft(root);
    r = countRight(root);
    if(l == r) return pow(2,l)-1;
    return countLeft(root->left) + countRight(root->right) + 1; 


}
/**
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int countNodes(struct TreeNode* root){
    if(root == NULL) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;

}
