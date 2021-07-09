/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) return NULL;
    struct ListNode *preptr=NULL,*ptr=head,*nextptr=head->next;
    while(nextptr != NULL){
        ptr->next = preptr;
        preptr = ptr;
        ptr = nextptr;
        nextptr = nextptr->next;
    }

    ptr->next = preptr;
    return ptr;
}
