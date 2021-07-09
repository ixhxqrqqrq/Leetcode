struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* search(struct TreeNode** root,int data){
    struct TreeNode *current = (*root);
    //printf("Visiting elements\n");
    while(current->val != data){
        if(current != NULL){
            //printf("%d ",current->val);

            //go to left tree
            if(current->val > data){
                current = current->left;
            }
            //go to right tree
            else{
                current = current->right;
            }
            //not found
            if(current == NULL){
                return NULL;
            }
        }

    }
    return current;
}

void insert(struct TreeNode** root, int data){
    struct TreeNode* tempNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* current;
    struct TreeNode* parent;

    tempNode->val = data;
    tempNode->left = NULL;
    tempNode->right = NULL;

    //if tree is empty
    if((*root) == NULL){
        (*root) = tempNode;
    }
    else{
        current = (*root);
        parent = NULL;

        while(1){
            parent = current;

            //go to left of the tree
            if(data < parent->val){
                current = current->left;

                //insert to the left
                if(current == NULL){
                    parent->left = tempNode;
                    return;
                }
            }
            //go to right of the tree
            else{
                current = current->right;

                //insert to the right
                if(current == NULL){
                    parent->right = tempNode;
                    return;
                }
            }
        }
    }
}
void insert2(struct TreeNode** root, int data){
    struct TreeNode* tempNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* current;
    struct TreeNode* parent;

    tempNode->val = data;
    tempNode->left = NULL;
    tempNode->right = NULL;

    //if tree is empty
    if((*root) == NULL){
        (*root) = tempNode;
    }
    else{
        current = (*root);
        parent = NULL;

        while(1){
            parent = current;

            //go to left of the tree
            if(data < parent->val){
                current = current->left;

                //insert to the left
                if(current == NULL){
                    parent->left = tempNode;
                    return;
                }
            }
            //go to right of the tree
            else if(data > parent->val){
                current = current->right;

                //insert to the right
                if(current == NULL){
                    parent->right = tempNode;
                    return;
                }
            }
            else{
                free(tempNode);
                return;
            }
        }
    }
}
void preorder(struct TreeNode* root){
    if(root == NULL) return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct TreeNode* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
    return;    
}
void postorder(struct TreeNode* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}

void deltree(struct TreeNode* root)
{
    if (root){
        deltree(root->left);
        deltree(root->right);
        free(root);
    }
}
