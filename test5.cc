//rotate-list -》牛客网右旋链表
    //给1->2->3->4->5,k=2
    //返回4->5->1->2->3
    //右旋2步，即从头走3步的下一个作头节点


ListNode* rotateRight(ListNode* head, int k)
{
    if(head==NULL || k<=0 || head->next==NULL)
        return head;
    ListNode* phead = head;
    ListNode* tail = NULL;
    ListNode* cur = head;
    int len = 0;
    //求得链表长度和尾节点
    while(cur != NULL)
    {
        ++len;
        if(cur->next == NULL)
            tail = cur;
        cur = cur->next;
    }
    //求要从头走的步数
    len = len- k%len;
    //形成一个环
    tail->next = head;
    int i = 0;
    for(; i<len; ++i)
    {
        tail = tail->next;
    }
    //走到这，返回链表的尾节点即tail
    phead = tail->next;
    tail->next = NULL;
    return phead;
}

