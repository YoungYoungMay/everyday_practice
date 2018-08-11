//二叉树的镜像-》牛客网

void Mirror(TreeNode* proot)
{
    if(proot == NULL)
        return;
    queue<TreeNode*> q;
    q.push(proot);
    while(!q.empty())
    {
        TreeNode* node = q.front();
        //交换左右子树
        TreeNode* ret = node->left;
        node->left = node->right;
        node->right = ret;
        //入左右子树
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
        //出当前子树的根节点
        q.pop();
    }
    return;
}
