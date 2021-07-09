/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
任一個節點的左子樹的所有節點值均小於該節點自身的值
任一個節點的右子樹的所有節點值均大於該節點自身的值
二元搜尋樹的左子樹和右子樹也都是二元搜尋樹
*/

bool helper(struct TreeNode* root,struct TreeNode* l, struct TreeNode* r){
    /* an empty tree is BST*/
    if(root == NULL) return true;
    /* false if this node violates the min/max constraint */
    if(l!=NULL && root->val <= l->val) return false;
    if(r!=NULL && root->val >= r->val) return false;
    
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint*/
    return helper(root->left,l,root) && helper(root->right,root,r);
}
bool isValidBST(struct TreeNode* root){
    return helper(root,NULL,NULL);
}
