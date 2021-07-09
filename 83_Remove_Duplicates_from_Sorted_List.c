/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL) return head;
    struct ListNode *p=head,*q=head->next;
    while(q!=NULL){
        if(p->val == q->val) q=q->next;
        else{
            p=p->next;
            p->val = q->val;
            q=q->next;
        }
    }
    p->next = NULL;
    return head;

}
