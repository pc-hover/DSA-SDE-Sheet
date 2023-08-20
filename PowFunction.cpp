#include <iostream>
using namespace std;

double pow(double x, int n)
{
    double ans = 1.0;
    long long m = n;
    if (m < 0)
        m = m * (-1);

    while (m)
    {
        if (m % 2 == 1)
        {
            ans = ans * x;
            m = m - 1;
        }
        else
        {
            x = x * x;
            m = m / 2;
        }
    }
    if (n < 0)
        ans = 1.0 / ans;

    return ans;
}
int main()
{
    double x = 2;
    int n = 10;
    cout << pow(x, 10);

    return 0;
}