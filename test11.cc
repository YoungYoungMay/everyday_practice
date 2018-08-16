//二叉搜索树的后序遍历序列-》牛客网
    //输入一个整形数组，判断该数组是不是某二叉搜索树的后序遍历结果，是输出Yes,否则输出No,假设数组的任意两个数字互不相同

bool VerifySquenceOfBST(vector<int> sequence) 
{
    return isSame(sequence, 0, sequence.size()-1);            
}
    
bool isSame(vector<int> v, int begin, int end)
{
    if(v.empty() || begin>end)
        return false;
    //后序遍历结果的最后一个元素为整棵树的根节点
    int root = v[end];
    int i = 0;
    for(; i<end; ++i)
    {
        //遍历数组得到的第一个大于根结点的值及其之后的为树的右子树的元素
        if(v[i] > root)
            break;   
    }
    int j = i;
    for(; j<end; ++j)
    {
        if(v[j] < root)
            return false;//右子树的元素一定大于根结点的值
        
    }
    
    //再继续判断当前根结点的左子树是否为二叉搜索树
    bool left = true;
    if(i > begin)
        left = isSame(v, begin, i-1);//i-1对应即为左子树的根结点
    
    //再继续判断当前根结点的右子树是否为二叉搜索树
    bool right = true;
    if(i < end-1)//end-1对应即为右子树的根结点
        right = isSame(v, i, end-1);//i对应即为右子树的后序遍历的第一个结点
    return left && right;
}
