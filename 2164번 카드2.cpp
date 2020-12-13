#include<iostream>
#include<algorithm>
#include <queue>

using namespace std;

int card(int n);

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    cout << card(n);


    return 0;
}
int card(int n)
{
    int result = 0;
    queue <int> q;

    for (int i = 0; i < n; i++)
        q.push(i+1);

    while (q.size()!=1)
    {
        q.pop();
        int tmp;
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    result = q.front();

    return result;
}