#include<iostream>
#include<algorithm>
#define SIZE 6

using namespace std;

int gcd(int a, int b);

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a[6];
    for (int i = 0; i < SIZE; i++)
        cin >> a[i];
   
    int b[6];
    for (int j = 0; j < SIZE; j++)
        cin >> b[j];

    int cnt = 0;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (a[i] > b[j])
                cnt++;
    
    int mod = gcd(cnt, 36);

    cout << cnt / mod << "/" << 36 / mod;

    return 0;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}