/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    if (l1 == NULL && l2 == NULL ) return NULL;

    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p=l1,*q=l2;
    struct ListNode *ptr = head; 
    while(p!=NULL && q!=NULL){
        head->next = NULL;
        if(p->val <= q->val){
            head->next = p;
            p = p->next;
            head = head->next;
        }
        else{
            head->next = q;
            q = q->next;
            head = head->next;
        }
    }
    if(p!=NULL){
        head->next = p;
    }
    if(q!=NULL){
        head->next = q;
    }
    head=ptr->next;
    free(ptr);
    return head;
}
