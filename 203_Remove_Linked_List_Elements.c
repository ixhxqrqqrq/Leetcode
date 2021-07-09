/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* removeElements(struct ListNode* head, int val){
    if(head == NULL) return NULL;
    struct ListNode *p=head,*headq=(struct ListNode*)malloc(sizeof(struct ListNode));
    headq->next = NULL;
    struct ListNode *q=headq;
    while(p != NULL){
        if(p->val != val){
            q->next = p;
            p = p->next;
            q = q->next;
        }
        else{
            struct ListNode *temp = p;
            p = p->next;
            free(temp);
            temp = NULL;
        }
    }
    q->next = NULL;
    struct ListNode *tmp = headq->next;
    free(headq);
    return tmp;



}


