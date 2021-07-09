/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL) return l2;
    if(l2==NULL) return l1;
    int len1=0,len2=0;
    struct ListNode *p=l1,*q=l2;
    while(p!=NULL){
        len1++;
        p = p->next;
    }
    while(q!=NULL){
        len2++;
        q = q->next;
    }
    p = len1>len2?l1:l2;

    int addone = 0,sum=0;
    struct ListNode *l1ptr = l1, *l2ptr = l2;
    while(l1ptr!=NULL && l2ptr!=NULL){
        sum = l1ptr->val + l2ptr->val + addone;
        addone = sum / 10;
        sum = sum - 10*addone;
        p->val = sum;
        q = p;
        p = p->next;
        l1ptr = l1ptr->next;
        l2ptr = l2ptr->next;
    }
    while(l1ptr!=NULL){
        sum = l1ptr->val + addone;
        addone = sum / 10;
        sum = sum - 10*addone;
        p->val = sum;
        q = p;
        p = p->next;
        l1ptr = l1ptr->next;
    }
    while(l2ptr!=NULL){
        sum = l2ptr->val + addone;
        addone = sum / 10;
        sum = sum - 10*addone;
        p->val = sum;
        q = p;
        p = p->next;
        l2ptr = l2ptr->next;
    }
    if(addone != 0){
        struct ListNode *newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = 1;
        newnode->next = NULL;
        q->next = newnode;
    }


    return len1>len2?l1:l2;

}
