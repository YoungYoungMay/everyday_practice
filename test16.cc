//求两链表的第一个公共结点->剑指offer
    //这里指的是两个不带环的链表


ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2 ) {
    //这里写的是两个都不带环的链表
    if(pHead1==NULL || pHead2==NULL)
        return NULL;
    ListNode* cur1 = pHead1;
    ListNode* cur2 = pHead2;
    int count1 = 0;
    int count2 = 0;
    int step = 0;
    for(; cur1!=NULL; cur1=cur1->next)
        count1++;
    for(; cur2!=NULL; cur2=cur2->next)
        count2++;
    cur1 = pHead1;
    cur2 = pHead2;
    if(count1 > count2)
    {
        step = count1-count2;
        for(int i=0; i<step; ++i)
            cur1 = cur1->next;
    }
    else
    {
        step = count2-count1;
        for(int i=0; i<step; ++i)
            cur2 = cur2->next;        
    }
    while(cur1!=NULL && cur2!=NULL)
    {
        if(cur1 == cur2)
            return cur1;
        cur1 = cur1->next;
        cur2 = cur2->next; 
    }
    return NULL;
}
