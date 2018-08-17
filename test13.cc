//序列化二叉树-》牛客网
    //实现二叉树的序列化及反序列化

TreeNode* decode(char *&str) 
{
    if(*str=='#')
    {
        str++;
        return NULL;                            
    }
    int num = 0;
    while(*str != ',')
        num = num*10 + (*(str++)-'0');//将字符数据转化为整型
    str++;
    TreeNode *root = new TreeNode(num);
    root->left = decode(str);
    root->right = decode(str);
    return root;                
}

char* Serialize(TreeNode *root) //序列化就是将二叉树的某种遍历结果保存为字符串，包括空结点
{
    if(root == NULL) 
        return "#";
    string r = to_string(root->val);
    r.push_back(',');//必须在每个结点的值之间加分隔符，否则转化为字符串之后不知道哪些值四哪个结点
    char *left = Serialize(root->left);
    char *right = Serialize(root->right);
    char *ret = new char[strlen(left) + strlen(right) + r.size()];
    strcpy(ret, r.c_str());
    strcat(ret, left);
    strcat(ret, right);
    return ret;
}

TreeNode* Deserialize(char *str) //反序列化就是根据序列化结果重建二叉树
{
    return decode(str);
}
