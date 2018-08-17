//binary-tree-preorder-traversal-》牛客网
    //给一棵二叉树，返回先序遍历结果

//递归太琐碎了，能不能用迭代实现？


//1.递归实现
vector<int> preorderTraversal(TreeNode *root) 
{
    digui(root);
    return v;        
}
vector<int> v;
void digui(TreeNode* root)
{
    if(root == NULL)
        return;
    v.push_back(root->val);
    digui(root->left);
    digui(root->right);                        
}

//2.利用栈辅助实现
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> v;
    stack<TreeNode*> s;
    TreeNode* cur = root;
    //cur为NULL并且栈为空时遍历结束
    while(cur!=NULL || !s.empty())
    {
        if(cur != NULL)//当前结点不为空
        {
            v.push_back(cur->val);
            s.push(cur);
            cur = cur->left;//访问了当前结点接着访问左子树
        }
        else//当前结点为空
        {
            cur = s.top();
            s.pop();
            cur = cur->right;//访问完左子树然后是右子树
        }
    }
    return v;
}


//3.利用栈辅助实现-》测试超过限制的内存
vector<int> preorderTraversal(TreeNode *root) 
{
    vector<int> v;
    if(root == NULL)
        return v;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* ret = s.top();
        v.push_back(ret->val);
        //因为栈是先进后出，所以要先入右子树再入左子树
        if(ret->right != NULL)
            s.push(ret->right);
        if(ret->left != NUL)
            s.push(ret->left);
    }
    return v;
}
