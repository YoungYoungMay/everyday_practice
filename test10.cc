//判断一颗树是否为平衡二叉树-》牛客网
    //空树或者左右子树的高度差小于等于1

bool IsBalanced_Solution(TreeNode* pRoot) 
{
    if(pRoot == NULL)//空树就是平衡二叉树
        return true;
    int ldepth = Depth(pRoot->left);
    int rdepth = Depth(pRoot->right);
    if(ldepth-rdepth>1 || ldepth-rdepth<-1)
        return false;
    else//要判断每个结点的子树是否均为平衡二叉树
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);                                        
}

int Depth(TreeNode* root)//求传入结点的子树的高度
{
    if(root == NULL)//当前子树为空树
        return NULL;
    int l_depth = Depth(root->left);
    int r_depth = Depth(root->right);
    return l_depth > r_depth ? l_depth+1 : r_depth + 1;            
}
