//俄罗斯方块的得分情况
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;//n表示俄罗斯方块的行数，m表示落下的每块在第几行
    vector<int> v(n,0);//vector初始化为10个0
    while(m--)
    {
        int c;
        cin>>c;
        v[--c]++;
    }
    //min_element可以获取最小值的位置索引
    //max_element可以获取最大值的位置索引
    cout<<*min_element(v.begin(), v.end())<<endl;

    //vector<int> v(n);
    //int i = 0;
    //int ret;
    //for(; i<m; ++i)
    //{
    //    cin>>ret;
    //    if(v[ret-1] == 0)
    //        v[ret-1] = 1;
    //    else
    //        v[ret-1] += 1;
    //}

    //int res = v[0];
    //for(i=1; i<n; ++i)
    //{
    //    if(v[i] < res)
    //        res = v[i];
    //}
    //cout<<res<<endl;
    return 0;
}
