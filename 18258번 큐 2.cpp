#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    string tmp;
    int n;
    int idx = -1;
    int tmp2;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;

        if (tmp == "push")
        {
            cin >> tmp2;
            q.push(tmp2);
            idx++;
        }
        else if (tmp == "pop")
        {
            if (idx != -1)
            {
                std::cout << q.front()<< "\n";
                q.pop();
                idx--;
            }
            else
            {
                std::cout << -1 << "\n";
            }
        }
        else if (tmp == "size")
        {
            std::cout << idx + 1 << "\n";
        }
        else if (tmp == "empty")
        {
            if (idx != -1)
            {
                std::cout << 0 << "\n";
            }
            else
            {
                std::cout << 1 << "\n";
            }
        }
        else if (tmp == "front")
        {
            if (idx != -1)
            {
                std::cout << q.front() << "\n";
            }
            else
            {
                std::cout << -1 << "\n";
            }
        }
        else if (tmp == "back")
        {
            if (idx != -1)
            {
                std::cout << q.back() << "\n";
            }
            else
            {
                std::cout << -1 << "\n";
            }
        }
    }
}