/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL)return NULL;
    struct ListNode dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *p = dummy;
    struct ListNode *A = head;
    struct ListNode *B = head->next;
    while(B){

    }
        

}

