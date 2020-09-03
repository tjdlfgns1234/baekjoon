#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    deque<int> deque;
    string tmp;
    int n;
    int idx = -1;
    int tmp2;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;

        if (tmp == "push_front")
        {
            cin >> tmp2;
            deque.push_front(tmp2);
            idx++;
        }
        else if (tmp == "push_back")
        {
            cin >> tmp2;
            deque.push_back(tmp2);
            idx++;
        }
        else if (tmp == "pop_front")
        {
            if (idx != -1)
            {
                std::cout << deque[0] << "\n";
                deque.pop_front();
                idx--;
            }
            else
            {
                std::cout << -1 << "\n";
            }
        }
        else if (tmp == "pop_back")
        {
            if (idx != -1)
            {
                std::cout << deque[idx] << "\n";
                deque.pop_back();
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
                std::cout << deque[0] << "\n";
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
                std::cout << deque[idx] << "\n";
            }
            else
            {
                std::cout << -1 << "\n";
            }
        }
    }
}