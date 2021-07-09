/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapnode(struct ListNode* A){
    struct ListNode* B = NULL;
    if(A->next == NULL) return NULL;
    else if(A->next->next == NULL){
        return NULL;
    }
    else{
        B = A->next;
        struct ListNode* C = B->next;
        struct ListNode* D = C->next;
        A->next = C;
        C->next = B;
        B->next = D;
    }
    return B;
}
struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL) return NULL;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* p = dummy;

    while(p!=NULL){
        struct ListNode *q = swapnode(p);
        p=q;
    }
    struct ListNode* temp = dummy->next;
    free(dummy);
    return temp;
}
