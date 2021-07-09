/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0, lenB = 0;   
    struct ListNode *p=headA,*q=headB;
    while(p!=NULL){
        lenA++;
        p = p->next;
    }
    while(q!=NULL){
        lenB++;
        q = q->next;
    }
    while(lenA != lenB){
        if(lenA > lenB){
            headA = headA->next;
            lenA--;
        }
        else{
            headB = headB->next;
            lenB--;
        }

    }
    while(headA != NULL && headB != NULL){
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;

}
