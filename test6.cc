//对称的二叉树-》牛客网
    //判断一棵树是不是对称的，注意一个树的镜像若与原树一样则对称
    //-》即每个结点的左右子树相同即为对称

bool isSymmetrical(TreeNode* pRoot)
{
    if(pRoot == NULL)
        return true;
    return isSame(pRoot->left, pRoot->right);        
}

bool isSame(TreeNode* n1, TreeNode* n2)
{
    if(n1== NULL && n2==NULL)
        return true;
    if(n1==NULL || n2 == NULL)
        return false;
    if(n1->val != n2->val)
        return false;
    //当当前两个节点相等时，判断继续，不是结束条件，所以不return 
    return isSame(n1->left, n2->right) && isSame(n1->right, n2->left);
}
