//计算最大兴趣得分？
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,k;//只能叫醒他一次
    cin>>n>>k;//n表示每堂课的时间(min)，k表示每叫一次的清醒时间
    vector<int> v(n);//每分钟代表的重要得分
    vector<int> x(n);//每分钟是否清醒(0/1表示)
    int i = 0;
    for(; i<n; ++i)
    {
        cin>>v[i];
    }
    int now = 0;
    for(i=0; i<n; ++i)
    {
        cin>>x[i];
        now += x[i]*v[i];//计算清醒时间的兴趣总数
    }
    int res = now;
    for(i=0; i<n;)
    {
        now += (!x[i])*v[i];
        if(++i > k)
        {
            res = max(res, now);
            now -= (!x[i-k])*v[i-k];
        }
    }
    cout<<res<<endl;
    return 0;
}
