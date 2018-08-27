//顺时针打印矩阵元素->2016年校招真题

vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m)//矩阵是n*m的
{
    vector<int> res;
    if(mat.empty())
        return res;
    int start_x = 0;
    int start_y = 0;
    ////下面两行是针对没有给矩阵的行列，只给了vector，自己求行列
    //int end_x = matrix.size()-1;
    //int end_y = matrix[0].size()-1;
    int end_x = n - 1;
    int end_y = m - 1;
    while(start_x<=end_x && start_y<=end_y)
    {
        //从左到右
        for(int j=start_y; j<=end_y; j++)
            res.push_back(mat[start_x][j]);
        //从上到下
        if(start_x < end_x)
            for(int i=start_x+1; i<=end_x; i++)
                res.push_back(mat[i][end_y]);
        //从右到左
        if(start_x<end_x && end_y>start_y)
            for(int j=end_y-1; j>=start_y; j--)
                res.push_back(mat[end_x][j]);
        //从下到上
        if(start_y<end_y && end_x>start_x)
            for(int i=end_x-1; i>start_x; i--)
                res.push_back(mat[i][start_y]);
        start_x++;
        start_y++;
        end_x--;
        end_y--;
    }
    return res;
}                                             
