//输入一个十进制数M和要转换的进制数N,将M转化为N进制数输出
//用十进制数一直除要转换的进制数，得到的余数即为对应进制数的每一位

#include <iostream>
#include <stack>
using namespace std;

void Shift(int num, int radix)
{
    stack<int> s;
    int ret = num;
    while(ret)
    {
        s.push(ret%radix);
        ret /= radix;
    }
    while(!s.empty())
    {
        switch(s.top())
        {
            case 10:
                cout<<'A';
                break;
            case 11:
                cout<<'B';
                break;
            case 12:
                cout<<'C';
                break;
            case 13:
                cout<<'D';
                break;
            case 14:
                cout<<'E';
                break;
            case 15:
                cout<<'F';
                break;
            default:
                cout<<s.top();
                break;
        }
        s.pop();
    }
}

int main()
{
    int radix;
    int num;
    cin>>num>>radix;
    Shift(num, radix);
    cout<<endl;
    return 0;
}
