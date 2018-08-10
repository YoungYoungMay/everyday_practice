//add-two-numbers-》牛客网
//给两个链表，将两个链表的对应值相加，超过10进位，返回一个新链表

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
{
    if(l1==NULL || l2==NULL)
        return NULL;
    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    int flag = 0;
    while(cur1!= NULL || cur2!=NULL)
    {
        int val1 = 0;
        if(cur1 != NULL)
        {
            val1 = cur1->val;
            cur1 = cur1->next;                                       
        }
        int val2 = 0;                       
        if(cur2 != NULL)
        {
            val2 = cur2->val;
            cur2 = cur2->next;                  
        }
        int ret = val1 + val2 + flag;
        tail->next = new ListNode(ret%10);
        tail = tail->next;
        flag = ret/10;
    }
    //这句很重要!!!!!!!
    //这是链表最后一个节点相加之后产生的进位，此时新链表比给的链表长
    if(flag != 0)
        tail->next = new ListNode(flag);
    return head->next;
}
