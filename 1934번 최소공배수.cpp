#include <iostream>
#include <algorithm>

using namespace std;
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        cout << lcm(a, b) << "\n";
    }
    return 0;
}
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return a * (b / gcd(a, b));
}
