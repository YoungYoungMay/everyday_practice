#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;//n堆苹果
    cin>>n;
    vector<int> v(n);
    int i = 0;
    int ret;
    for(; i<n; ++i)
    {
        cin>>ret;
        v[i] = ret;
    }
    int k;//询问几次
    cin>>k;
    vector<int> ques(k);
    for(i=0; i<k; ++i)
    {
        cin>>ret;
        ques[i] = ret;
    }

    vector<int> res;
    for(i=0; i<ques.size(); ++i)
    {
        int j = 0;
        int ret = ques[i];
        for(; j<v.size(); j++)
        {
            if(ret <= v[j])
            {
                cout<<j+1<<endl;
                //res.push_back(j+1);
                break;
            }
            ret = ret - ques[i];
        }
    }

    //for(i=0; i<res.size(); ++i)
    //{
    //    cout<<res[i]<<endl;
    //}
    return 0;

}
