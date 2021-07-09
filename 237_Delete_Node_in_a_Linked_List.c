/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *pre=node,*p=node,*q=node->next;
    while(q!=NULL){
        p->val = q->val;
        pre=p;
        p = p->next;
        q = q->next;
    }
    free(p);
    pre->next = NULL;


    
}
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    struct ListNode* temp = node->next;
    node->next = node->next->next;
    free(temp);
}
