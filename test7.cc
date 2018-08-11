//把二叉树打印成多行-》牛客网
//从上到下按层打印二叉树，同一层结点从左至右输出，每一层输出为一行

vector<vector<int> > Print(TreeNode* proot)
{
    vector<vector<int> > vv;//用于存放最后结果
    if(proot == NULL)
        return vv;
    queue<TreeNode*> q;
    q.push(proot);
    //队列为空则遍历结束
    while(!q.empty())
    {
        vector<int> v;//存放每一层打印的每一行的结果
        int size =  q.size();
        int i = 0;
        for(; i<size; ++i)
        {
            TreeNode* ret = q.front();
            v.push_back(ret->val);
            if(ret->left != NULL)
                q.push(ret->left);
            if(ret->right != NULL)
                q.push(ret->right);
            q.pop();
        }
        vv.push_back(v);
    }
    return vv;
}
