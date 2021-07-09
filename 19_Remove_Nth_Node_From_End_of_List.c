/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head->next == NULL) return NULL;
    struct ListNode *Head0 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = Head0;
    Head0->next = head;
    struct ListNode *pre = Head0;
    int i = 0;
    while(p->next != NULL){
        p = p->next;
        i++;
        if(i>n){
            pre = pre->next;
        }
    }
    struct ListNode *temp = pre->next;
    pre->next = pre->next->next;
    free(temp);
    return Head0->next;

}
