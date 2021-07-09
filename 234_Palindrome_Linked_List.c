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

bool isPalindrome(struct ListNode* head){
    if(head->next == NULL) return true;
    struct ListNode *slow=head, *fast=head;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *head2 = reverseList(slow);
    while(head2!=NULL){
        if(head2->val == head->val){
            head=head->next;
            head2=head2->next;
        }
        else{
            return false;
        }
    }
    return true;
}
