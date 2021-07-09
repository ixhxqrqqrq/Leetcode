/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(!head) return head;
    struct ListNode* pOdd = head;
    struct ListNode* p = head->next;
    struct ListNode* pNext = NULL;
    while( p && (pNext = p->next)){
        p->next = pNext->next;
        pNext->next = pOdd->next;
        pOdd->next = pNext;

        p = p->next;
        pOdd = pOdd->next;
    }

    return head;

}
