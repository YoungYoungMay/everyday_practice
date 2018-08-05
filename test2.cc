//将任意进制数转换为十进制数
//乘以基数的次方求和

#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

void Shift(string num, int radix)
{
    int i = 0;
    int res = 0;//结果
    while(num.size() != i)
    {
        res *= radix;
        res += num[i] - '0';//将字符转换为整数
        i++;
    }
    cout<<res<<endl;
}

int main()
{
    int radix;
    string num;
    cin>>num>>radix;
    Shift(num, radix);
    return 0;
}
