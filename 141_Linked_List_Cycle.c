/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;
    struct ListNode *slow_p = head, *fast_p = head->next;
    while(fast_p!=NULL&&fast_p->next!=NULL){
        if(slow_p == fast_p) return true;
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
    }
    return false;
}
